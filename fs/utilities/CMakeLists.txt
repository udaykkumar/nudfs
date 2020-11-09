# Minimum CMake
 cmake_minimum_required(VERSION 2.8,9)

 file(GLOB APP_SOURCES *.c**)
 # Horrible Hack .. I should grow up a bit
 file(GLOB fs_SOURCES ../sources/src/*.c**)
 
 foreach(sourceFile ${APP_SOURCES})
     get_filename_component(name ${sourceFile} NAME_WE)
     add_executable(${name} ${sourceFile} ${fs_SOURCES})
     target_link_libraries(${name} ${Boost_LIBRARIES})
 endforeach(sourceFile ${APP_SOURCES})