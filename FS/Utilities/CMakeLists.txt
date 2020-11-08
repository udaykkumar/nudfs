# Minimum CMake
 cmake_minimum_required(VERSION 2.8,9)

 file(GLOB APP_SOURCES *.c**)
 file(GLOB FS_SOURCES ../Sources/src/*.c**)
 
 foreach(sourceFile ${APP_SOURCES})
     get_filename_component(name ${sourceFile} NAME_WE)
     add_executable(${name} ${sourceFile} ${FS_SOURCES})
     target_link_libraries(${name} ${Boost_LIBRARIES})
 endforeach(sourceFile ${APP_SOURCES})