cmake_minimum_required(VERSION 3.5)
project(CppRobotics)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#########
## Qt5 ##
#########
find_package(Qt5 COMPONENTS Core Gui Widgets PrintSupport)
include_directories(
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Gui_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  ${Qt5PrintSupport_INCLUDE_DIRS}
  )
link_directories(
  ${Qt5Core_LIBRARY_DIRS}
  ${Qt5Gui_LIBRARY_DIRS}
  ${Qt5Widgets_LIBRARY_DIRS}
  ${Qt5PrintSupport_LIBRARY_DIRS}
  )

############
## Eigen3 ##
############
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

#########
## Src ##
#########
## Qt5 ##
add_subdirectory(src/Qt5)