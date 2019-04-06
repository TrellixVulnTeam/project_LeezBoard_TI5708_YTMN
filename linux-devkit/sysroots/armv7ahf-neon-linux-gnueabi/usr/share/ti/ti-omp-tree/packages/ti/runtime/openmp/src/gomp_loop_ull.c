/* Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
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

/* This file handles the LOOP (FOR/DO) construct.  */

#include "tomp_parallel.h"
#include <stdlib.h>          /* for abort() */

typedef unsigned long long gomp_ull;
/* Allocate a new work share structure */

/* Initialize the given work share construct from the given arguments.  */

static inline void
gomp_loop_ull_init (struct gomp_work_share *ws, bool up, gomp_ull start,
		    gomp_ull end, gomp_ull incr, enum gomp_schedule_type sched,
		    gomp_ull chunk_size)
{

  ws->sched = sched;
  ws->chunk_size_ull = chunk_size;
  /* Canonicalize loops that have zero iterations to ->next == ->end.  */
  ws->end_ull = ((up && start > end) || (!up && start < end))
		? start : end;
  ws->incr_ull = incr;
  ws->next_ull = start;
  ws->mode = 0;
  if (sched == GFS_DYNAMIC)
    {
      ws->chunk_size_ull *= incr;
    }
  if (!up)
    ws->mode |= 2;
}

/* The *_start routines are called when first encountering a loop construct
   that is not bound directly to a parallel construct.  The first thread
   that arrives will create the work-share construct; subsequent threads
   will see the construct exists and allocate work from it.

   START, END, INCR are the bounds of the loop; due to the restrictions of
   OpenMP, these values must be the same in every thread.  This is not
   verified (nor is it entirely verifiable, since START is not necessarily
   retained intact in the work-share data structure).  CHUNK_SIZE is the
   scheduling parameter; again this must be identical in all threads.

   Returns true if there's any work for this thread to perform.  If so,
   *ISTART and *IEND are filled with the bounds of the iteration block
   allocated to this thread.  Returns false if all work was assigned to
   other threads prior to this thread's arrival.  */

static bool
gomp_loop_ull_static_start (bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;

  thr->ts->static_trip = 0;
  if (gomp_work_share_start (false))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_STATIC, chunk_size);
      gomp_work_share_init_done ();
    }

  return !gomp_iter_ull_static_next (istart, iend);
}

static bool
gomp_loop_ull_dynamic_start (bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull chunk_size,
			     gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  if (gomp_work_share_start (false))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_DYNAMIC, chunk_size);
      gomp_work_share_init_done ();
    }

  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_dynamic_next_locked (istart, iend);
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

static bool
gomp_loop_ull_guided_start (bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  if (gomp_work_share_start (false))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_GUIDED, chunk_size);
      gomp_work_share_init_done ();
    }

  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_guided_next_locked (istart, iend);
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

bool
GOMP_loop_ull_runtime_start (bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull *istart, gomp_ull *iend)
{
  struct gomp_task_icv *icv = gomp_icv ();
  switch (icv->run_sched_var)
    {
    case GFS_STATIC:
      return gomp_loop_ull_static_start (up, start, end, incr,
					 icv->run_sched_modifier,
					 istart, iend);
    case GFS_DYNAMIC:
      return gomp_loop_ull_dynamic_start (up, start, end, incr,
					  icv->run_sched_modifier,
					  istart, iend);
    case GFS_GUIDED:
      return gomp_loop_ull_guided_start (up, start, end, incr,
					 icv->run_sched_modifier,
					 istart, iend);
    case GFS_AUTO:
      /* For now map to schedule(static), later on we could play with feedback
	 driven choice.  */
      return gomp_loop_ull_static_start (up, start, end, incr,
					 0, istart, iend);
    default:
      abort ();
    }

  return false;
}

/* The *_ordered_*_start routines are similar.  The only difference is that
   this work-share construct is initialized to expect an ORDERED section.  */

static bool
gomp_loop_ull_ordered_static_start (bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;

  thr->ts->static_trip = 0;
  if (gomp_work_share_start (true))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_STATIC, chunk_size);
      gomp_ordered_static_init ();
      gomp_work_share_init_done ();
    }

  return !gomp_iter_ull_static_next (istart, iend);
}

static bool
gomp_loop_ull_ordered_dynamic_start (bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull chunk_size,
				     gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  if (gomp_work_share_start (true))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_DYNAMIC, chunk_size);
      // gomp_mutex_lock (&thr->ts->work_share->lock);
      gomp_work_share_init_done ();
    }
  // else
  //   gomp_mutex_lock (&thr->ts->work_share->lock);

  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_dynamic_next_locked (istart, iend);
  if (ret)
    gomp_ordered_first ();
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

static bool
gomp_loop_ull_ordered_guided_start (bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  if (gomp_work_share_start (true))
    {
      gomp_loop_ull_init (thr->ts->work_share, up, start, end, incr,
			  GFS_GUIDED, chunk_size);
      // gomp_mutex_lock (&thr->ts->work_share->lock);
      gomp_work_share_init_done ();
    }
  // else
  //  gomp_mutex_lock (&thr->ts->work_share->lock);

  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_guided_next_locked (istart, iend);
  if (ret)
    gomp_ordered_first ();
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

bool
GOMP_loop_ull_ordered_runtime_start (bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull *istart,
				     gomp_ull *iend)
{
  struct gomp_task_icv *icv = gomp_icv ();
  switch (icv->run_sched_var)
    {
    case GFS_STATIC:
      return gomp_loop_ull_ordered_static_start (up, start, end, incr,
						 icv->run_sched_modifier,
						 istart, iend);
    case GFS_DYNAMIC:
      return gomp_loop_ull_ordered_dynamic_start (up, start, end, incr,
						  icv->run_sched_modifier,
						  istart, iend);
    case GFS_GUIDED:
      return gomp_loop_ull_ordered_guided_start (up, start, end, incr,
						 icv->run_sched_modifier,
						 istart, iend);
    case GFS_AUTO:
      /* For now map to schedule(static), later on we could play with feedback
	 driven choice.  */
      return gomp_loop_ull_ordered_static_start (up, start, end, incr,
						 0, istart, iend);
    default:
      abort ();
    }

    return false;
}

/* The *_next routines are called when the thread completes processing of
   the iteration block currently assigned to it.  If the work-share
   construct is bound directly to a parallel construct, then the iteration
   bounds may have been set up before the parallel.  In which case, this
   may be the first iteration for the thread.

   Returns true if there is work remaining to be performed; *ISTART and
   *IEND are filled with a new iteration block.  Returns false if all work
   has been assigned.  */

static bool
gomp_loop_ull_static_next (gomp_ull *istart, gomp_ull *iend)
{
  return !gomp_iter_ull_static_next (istart, iend);
}

static bool
gomp_loop_ull_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
  bool ret;

  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_dynamic_next_locked (istart, iend);
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

static bool
gomp_loop_ull_guided_next (gomp_ull *istart, gomp_ull *iend)
{
  bool ret;

  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_guided_next_locked (istart, iend);
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

bool
GOMP_loop_ull_runtime_next (gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;

  switch (thr->ts->work_share->sched)
    {
    case GFS_STATIC:
    case GFS_AUTO:
      return gomp_loop_ull_static_next (istart, iend);
    case GFS_DYNAMIC:
      return gomp_loop_ull_dynamic_next (istart, iend);
    case GFS_GUIDED:
      return gomp_loop_ull_guided_next (istart, iend);
    default:
      abort ();
    }

  return false;
}

/* The *_ordered_*_next routines are called when the thread completes
   processing of the iteration block currently assigned to it.

   Returns true if there is work remaining to be performed; *ISTART and
   *IEND are filled with a new iteration block.  Returns false if all work
   has been assigned.  */

static bool
gomp_loop_ull_ordered_static_next (gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  int test;

  gomp_ordered_sync ();
  tomp_mutex_lock (thr->ts->work_share->lock);
  test = gomp_iter_ull_static_next (istart, iend);
  if (test >= 0)
    gomp_ordered_static_next ();
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return test == 0;
}

static bool
gomp_loop_ull_ordered_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  gomp_ordered_sync ();
  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_dynamic_next_locked (istart, iend);
  if (ret)
    gomp_ordered_next ();
  else
    gomp_ordered_last ();
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

static bool
gomp_loop_ull_ordered_guided_next (gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;
  bool ret;

  gomp_ordered_sync ();
  tomp_mutex_lock (thr->ts->work_share->lock);
  ret = gomp_iter_ull_guided_next_locked (istart, iend);
  if (ret)
    gomp_ordered_next ();
  else
    gomp_ordered_last ();
  tomp_mutex_unlock (thr->ts->work_share->lock);

  return ret;
}

bool
GOMP_loop_ull_ordered_runtime_next (gomp_ull *istart, gomp_ull *iend)
{
  //struct gomp_thread *thr = gomp_thread ();
  tomp_Thread *thr = &tomp_thread;

  switch (thr->ts->work_share->sched)
    {
    case GFS_STATIC:
    case GFS_AUTO:
      return gomp_loop_ull_ordered_static_next (istart, iend);
    case GFS_DYNAMIC:
      return gomp_loop_ull_ordered_dynamic_next (istart, iend);
    case GFS_GUIDED:
      return gomp_loop_ull_ordered_guided_next (istart, iend);
    default:
      abort ();
    }
  return false;
}

bool
GOMP_loop_ull_static_start (bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_static_start (up, start, end, incr, chunk_size, istart,
				     iend);
}

bool
GOMP_loop_ull_dynamic_start (bool up, gomp_ull start, gomp_ull end,
			     gomp_ull incr, gomp_ull chunk_size,
			     gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_dynamic_start (up, start, end, incr, chunk_size, istart,
				      iend);
}

bool
GOMP_loop_ull_guided_start (bool up, gomp_ull start, gomp_ull end,
			    gomp_ull incr, gomp_ull chunk_size,
			    gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_guided_start (up, start, end, incr, chunk_size, istart,
				     iend);
}

bool
GOMP_loop_ull_ordered_static_start (bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_static_start (up, start, end, incr, chunk_size,
					     istart, iend);
}

bool
GOMP_loop_ull_ordered_dynamic_start (bool up, gomp_ull start, gomp_ull end,
				     gomp_ull incr, gomp_ull chunk_size,
				     gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_dynamic_start (up, start, end, incr, chunk_size,
					      istart, iend);
}

bool
GOMP_loop_ull_ordered_guided_start (bool up, gomp_ull start, gomp_ull end,
				    gomp_ull incr, gomp_ull chunk_size,
				    gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_guided_start (up, start, end, incr, chunk_size,
					     istart, iend);
}

bool
GOMP_loop_ull_static_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_static_next (istart, iend);
}

bool
GOMP_loop_ull_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_dynamic_next (istart, iend);
}

bool
GOMP_loop_ull_guided_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_guided_next (istart, iend);
}

bool
GOMP_loop_ull_ordered_static_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_static_next (istart, iend);
}

bool
GOMP_loop_ull_ordered_dynamic_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_dynamic_next (istart, iend);
}

bool
GOMP_loop_ull_ordered_guided_next (gomp_ull *istart, gomp_ull *iend)
{
  return gomp_loop_ull_ordered_guided_next (istart, iend);
}