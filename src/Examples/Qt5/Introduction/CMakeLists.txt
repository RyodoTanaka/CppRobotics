cmake_minimum_required(VERSION 3.5)
## set binary directory ##
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Examples/Qt5/Introduction)
## version ##
add_executable(version version.cpp)
target_link_libraries(version Qt5::Core)
## gui ##
add_executable(gui gui.cpp)
target_link_libraries(gui Qt5::Widgets Qt5::Gui)
