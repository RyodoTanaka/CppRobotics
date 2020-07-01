cmake_minimum_required(VERSION 3.5)

## set binary directory ##
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Examples/Qt5/Strings)

## basic ##
add_executable(basic basic.cpp)
target_link_libraries(basic Qt5::Core)
## init ##
add_executable(init init.cpp)
target_link_libraries(init Qt5::Core)
## access ##
add_executable(access access.cpp)
target_link_libraries(access Qt5::Core)
## length ##
add_executable(length length.cpp)
target_link_libraries(length Qt5::Core)
## building ##
add_executable(building building.cpp)
target_link_libraries(building Qt5::Core)
## substrings ##
add_executable(substrings substrings.cpp)
target_link_libraries(substrings Qt5::Core)
## looping ##
add_executable(looping looping.cpp)
target_link_libraries(looping Qt5::Core)
## comparing ##
add_executable(comparing comparing.cpp)
target_link_libraries(comparing Qt5::Core)
## converting ##
add_executable(converting converting.cpp)
target_link_libraries(converting Qt5::Core)
## letters ##
add_executable(letters letters.cpp)
target_link_libraries(letters Qt5::Core)
## modify ##
add_executable(modify modify.cpp)
target_link_libraries(modify Qt5::Core)
## right_align ##
add_executable(right_align right_align.cpp)
target_link_libraries(right_align Qt5::Core)
## html_escape ##
add_executable(html_escape html_escape.cpp)
target_link_libraries(html_escape Qt5::Core)
file(COPY source DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
