# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(nudfs)

# Boost and Family
set(Boost_USE_STATIC_LIBS ON)
find_package(
  Boost
  COMPONENTS unit_test_framework log program_options
  REQUIRED)

  include_directories(${Boost_INCLUDE_DIRS}) 
#This one for my Mac setup
set(CMAKE_CXX_STANDARD 17)


# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS     "-lgcov --coverage")

#include directories
include_directories( "nudfs/nud-common" )
include_directories( "nudfs/nud-csl" )
include_directories( "nudfs/nud-dev" )
include_directories( "nudfs/nud-fs" )
include_directories( "nudfs/nud-net" )
include_directories( "nudfs/nud-utils" )


file(GLOB TEST_SOURCES_NUD_COMMON     "nudfs/nud-common/*.cpp"  )
file(GLOB TEST_SOURCES_NUD_CSL        "nudfs/nud-csl/*.cpp"     )
file(GLOB TEST_SOURCES_NUD_DEV        "nudfs/nud-dev/*.cpp"     )
file(GLOB TEST_SOURCES_NUD_FS         "nudfs/nud-fs/*.cpp"      )
file(GLOB TEST_SOURCES_NUD_UTILS      "nudfs/nud-utils/*.cpp"   )


add_subdirectory(experiments)
add_subdirectory(nudfs)
add_subdirectory(unit-tests)

