cmake_minimum_required(VERSION 3.12)
project(MathematicaLinkServer C)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/Mathematica" ${CMAKE_MODULE_PATH})

# Set this to the correct path of your Mathematica installation or comment it out if it can be found automatically!
set(Mathematica_ROOT_DIR "/usr/local/Wolfram/Mathematica/11.3" CACHE STRING "Root dir of Mathematica")

find_package(Mathematica COMPONENTS WSTP)

set(CMAKE_C_STANDARD 99)


message("${CMAKE_PROJECT_NAME}/LibraryResources/${Mathematica_SYSTEM_ID}")
message("${CMAKE_SOURCE_DIR}")

add_executable(MathematicaLinkServer MathematicaLinkServer.c)
target_link_libraries (MathematicaLinkServer ${Mathematica_WSTP_LIBRARIES})
include_directories(${Mathematica_INCLUDE_DIRS})


