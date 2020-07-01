cmake_minimum_required(VERSION 3.5)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Examples/Plot)

# build #
add_executable(plot2d_static src/plot2d_static.cpp)
target_link_libraries(plot2d_static
  CRPlot
  Qt5::Core
  ${EIGEN3_LIBRALIES}
  )
