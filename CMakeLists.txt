# Minimum CMake
cmake_minimum_required(VERSION 2.8,9)
project(nudfs)

# Boost and Family
set(Boost_USE_STATIC_LIBS ON)
#set_target_properties(${TARGET} PROPERTIES COMPILE_DEFINITIONS "BOOST_LOG_DYN_LINK")
find_package(
  Boost
  COMPONENTS unit_test_framework log program_options
  REQUIRED)

#This one for my Mac setup
set(CMAKE_CXX_STANDARD 17)


# Project Compiler Arguments
set(PROJECT_COMPILER_FLAGS " -Wall -fprofile-arcs -ftest-coverage  -std=c++11 ")
set(PROJECT_LINK_FLAGS     "-lgcov --coverage")
include_directories( "common" )
include_directories( "fs/sources/inc")
add_subdirectory(fs)