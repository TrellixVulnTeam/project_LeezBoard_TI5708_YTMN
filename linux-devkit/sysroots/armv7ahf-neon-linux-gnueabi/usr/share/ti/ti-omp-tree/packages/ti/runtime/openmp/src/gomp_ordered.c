/* Copyright (C) 2005, 2009 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

 /* Copyright (C) 2013
   Texas Instruments, Inc.
   
   Changes from original:
   - Casting added to suppress warning from TI compiler 
   - Replaced references to gomp team/thread structures with TI equivalents
*/
   
/* This file handles the ORDERED construct.  */

#include "tomp_parallel.h"
#include "gomp.h"


/* This function is called when first allocating an iteration block.  That
   is, the thread is not currently on the queue.  The work-share lock must
   be held on entry.  */

void
gomp_ordered_first (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned index;

  /* Work share constructs can be orphaned.  */
  if (team == NULL || team->nthreads == 1)
    return;

  index = ws->ordered_cur + ws->ordered_num_used;
  if (index >= team->nthreads)
    index -= team->nthreads;
  ws->ordered_team_ids[index] = thr->ts->team_id;

  /* If this is the first and only thread in the queue, then there is
     no one to release us when we get to our ordered section.  Post to
     our own release queue now so that we won't block later.  */
  if (ws->ordered_num_used++ == 0)
    team->ordered_release[thr->ts->team_id] = 1;
}

/* This function is called when completing the last iteration block.  That
   is, there are no more iterations to perform and so the thread should be
   removed from the queue entirely.  Because of the way ORDERED blocks are
   managed, it follows that we currently own access to the ORDERED block,
   and should now pass it on to the next thread.  The work-share lock must
   be held on entry.  */

void
gomp_ordered_last (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned next_id;

  /* Work share constructs can be orphaned.  */
  if (team == NULL || team->nthreads == 1)
    return;

  /* We're no longer the owner.  */
  ws->ordered_owner = (unsigned)-1;

  /* If we're not the last thread in the queue, then wake the next.  */
  if (--ws->ordered_num_used > 0)
    {
      unsigned next = ws->ordered_cur + 1;
      if (next == team->nthreads)
	next = 0;
      ws->ordered_cur = next;

      next_id = ws->ordered_team_ids[next];
      team->ordered_release[next_id] = 1;
    }
}


/* This function is called when allocating a subsequent allocation block.
   That is, we're done with the current iteration block and we're allocating
   another.  This is the logical combination of a call to gomp_ordered_last
   followed by a call to gomp_ordered_first.  The work-share lock must be
   held on entry. */

void
gomp_ordered_next (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned index, next_id;

  /* Work share constructs can be orphaned.  */
  if (team == NULL || team->nthreads == 1)
    return;

  /* We're no longer the owner.  */
  ws->ordered_owner = (unsigned)-1;

  /* If there's only one thread in the queue, that must be us.  */
  if (ws->ordered_num_used == 1)
    {
      /* We have a similar situation as in gomp_ordered_first
	 where we need to post to our own release semaphore.  */
      team->ordered_release[thr->ts->team_id] = 1;
      return;
    }

  /* If the queue is entirely full, then we move ourself to the end of 
     the queue merely by incrementing ordered_cur.  Only if it's not 
     full do we have to write our id.  */
  if (ws->ordered_num_used < team->nthreads)
    {
      index = ws->ordered_cur + ws->ordered_num_used;
      if (index >= team->nthreads)
	index -= team->nthreads;
      ws->ordered_team_ids[index] = thr->ts->team_id;
    }

  index = ws->ordered_cur + 1;
  if (index == team->nthreads)
    index = 0;
  ws->ordered_cur = index;

  next_id = ws->ordered_team_ids[index];

  /* There is no need for an mfence after this store because the thread that 
   * is spinning on team->ordered_release[thr->ts.team_id] becoming non-zero 
   * in gomp_ordered_sync will eventually see that write and exit the loop
   */
  team->ordered_release[next_id] = 1;
}


/* This function is called when a statically scheduled loop is first
   being created.  */

void
gomp_ordered_static_init (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;

  if (team == NULL || team->nthreads == 1)
    return;

  team->ordered_release[0] = 1;
}

/* This function is called when a statically scheduled loop is moving to
   the next allocation block.  Static schedules are not first come first
   served like the others, so we're to move to the numerically next thread,
   not the next thread on a list.  The work-share lock should *not* be held
   on entry.  */

void
gomp_ordered_static_next (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;
  unsigned id = thr->ts->team_id;

  if (team == NULL || team->nthreads == 1)
    return;

  /* Reset ordered owner. Will be set to new owner in gomp_ordered_sync */
  ws->ordered_owner = (unsigned)-1;

  /* This thread currently owns the lock.  Increment the owner.  */
  if (++id == team->nthreads)
    id = 0;
  ws->ordered_team_ids[0] = id;
  team->ordered_release[id] = 1;
}

/* This function is called when we need to assert that the thread owns the
   ordered section.  Due to the problem of posted-but-not-waited semaphores,
   this needs to happen before completing a loop iteration.  */

void
gomp_ordered_sync (void)
{
  tomp_Thread *thr  = &tomp_thread;
  tomp_Team   *team = thr->ts->team;
  struct gomp_work_share *ws = thr->ts->work_share;

  /* Work share constructs can be orphaned.  But this clearly means that
     we are the only thread, and so we automatically own the section.  */
  if (team == NULL || team->nthreads == 1)
    return;

  /* ??? I believe it to be safe to access this data without taking the
     ws->lock.  The only presumed race condition is with the previous
     thread on the queue incrementing ordered_cur such that it points
     to us, concurrently with our check below.  But our team_id is
     already present in the queue, and the other thread will always
     post to our release semaphore.  So the two cases are that we will
     either win the race an momentarily block on the semaphore, or lose
     the race and find the semaphore already unlocked and so not block.
     Either way we get correct results.  */

  if (ws->ordered_owner != thr->ts->team_id)
    {
      /* This test is once per chunk. After the call to gomp_ordered_sync in
       * the first iteration of a chunk, the thread updates ordered_owner to
       * its thread id. In subsequent iterations of the chunk, the if test
       * above is false
       */

      while (team->ordered_release[thr->ts->team_id] == 0);
      
      /* There is no need for an mfence here. The potential race is another 
       * thread writing 1 to re-enable this thread to enter the ordered region. 
       * This is not possible because another thread cannot start running its 
       * ordered region till this thread hits GOMP_loop_ordered_dynamic_next 
       * and transfers control. I.e. If we consider 2 threads, T0 and T1, it's 
       * not possible for T1 to be in GOMP_ordered_sync (which sets 
       * ordered_release[T1] to 0) and for T0 to be in 
       * GOMP_loop_ordered_dynamic_next which could potentially write a 1 to 
       * ordered_release[T1]
       */
      team->ordered_release[thr->ts->team_id] = 0;
      ws->ordered_owner = thr->ts->team_id;
    }

}

/* This function is called by user code when encountering the start of an
   ORDERED block.  We must check to see if the current thread is at the
   head of the queue, and if not, block.  */

void
GOMP_ordered_start (void)
{
  gomp_ordered_sync ();

  /* OMP v3.0, 2.8.6, "At entry to ordered region" */
  __gomp_flush0();
}

/* This function is called by user code when encountering the end of an
   ORDERED block.  With the current ORDERED implementation there's nothing
   for us to do.

   However, the current implementation has a flaw in that it does not allow
   the next thread into the ORDERED section immediately after the current
   thread exits the ORDERED section in its last iteration.  The existance
   of this function allows the implementation to change.  */

void
GOMP_ordered_end (void)
{
  /* OMP v3.0, 2.8.6, "At exit from ordered region" */
  __gomp_flush0();
}
