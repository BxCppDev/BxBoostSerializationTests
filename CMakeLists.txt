# - Top level CMake script

#-----------------------------------------------------------------------
# Enforce an out-of-source build.
#
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(STATUS "This package requires an out-of-source build.")
  message(STATUS "Please remove these files from ${CMAKE_BINARY_DIR} first:")
  message(STATUS "  CMakeCache.txt")
  message(STATUS "  CMakeFiles")
  message(STATUS "Once these files are removed, create a separate directory")
  message(STATUS "and run CMake from there, pointing it to:")
  message(STATUS "  ${CMAKE_SOURCE_DIR}")
  message(FATAL_ERROR "in-source build detected")
endif()

#-----------------------------------------------------------------------
# CMake/project requirements and configuration
#
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(BxBoostSerializationTests)

# - Load Custom Modules
list(INSERT CMAKE_MODULE_PATH 0 ${PROJECT_SOURCE_DIR}/cmake)

#-----------------------------------------------------------------------
# Configure build of Bayeux library
# - Packages
# - Boost
set(BAYEUX_BOOST_MIN_VERSION "1.63.0")
set(BAYEUX_BOOST_COMPONENTS
  filesystem
  system
  serialization
  iostreams
  )
set(Boost_NO_BOOST_CMAKE ON)
find_package(Boost ${BAYEUX_BOOST_MIN_VERSION}
  REQUIRED
  ${BAYEUX_BOOST_COMPONENTS}
  )
foreach(_boost_lib ${BAYEUX_BOOST_COMPONENTS})
  list(APPEND Bayeux_Boost_LIBRARIES Boost::${_boost_lib})
endforeach()
get_filename_component(Bayeux_BOOST_ROOT ${Boost_INCLUDE_DIR} DIRECTORY)

add_subdirectory(test1)

# - end