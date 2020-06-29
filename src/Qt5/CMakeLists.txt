cmake_minimum_required(VERSION 3.5)

## version ##
add_executable(version Introduction/version.cpp)
target_link_libraries(version Qt5::Core)
## gui ##
add_executable(gui Introduction/gui.cpp)
target_link_libraries(gui Qt5::Widgets Qt5::Gui)
