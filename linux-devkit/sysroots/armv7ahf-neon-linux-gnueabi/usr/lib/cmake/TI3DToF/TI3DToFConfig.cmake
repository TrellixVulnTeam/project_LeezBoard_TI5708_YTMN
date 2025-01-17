# - Config file for the FooBar package
# It defines the following variables
#  TI3DToF_INCLUDE_DIRS - include directories for FooBar
#  TI3DToF_LIBRARIES    - libraries to link against

find_package(Voxel "0.6.8" REQUIRED)
 
# Compute paths
get_filename_component(TI3DTOF_CMAKE_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

set(TI3DToF_INCLUDE_DIRS "${TI3DTOF_CMAKE_DIR}/../../../include/voxel-0.6.8" "${VOXEL_INCLUDE_DIRS}")
 
# Our library dependencies (contains definitions for IMPORTED targets)
if(NOT TARGET Voxel::ti3dtof AND NOT Voxel_BINARY_DIR)
  include("${TI3DTOF_CMAKE_DIR}/TI3DToFTargets.cmake")
endif()
 
# These are IMPORTED targets created by FooBarTargets.cmake
set(TI3DToF_LIBRARIES Voxel::ti3dtof ${VOXEL_LIBRARIES})
