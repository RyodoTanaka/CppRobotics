cmake_minimum_required(VERSION 3.5)
## set binary directory ##
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Qt5/Examples/CustomPlot)
# use include file on current directory #
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set arguments #
set(SOURCES
  src/mainwindow.cpp
  src/main.cpp
  src/qcustomplot.cpp
  )
set(HEADERS
  include/mainwindow.h
  include/qcustomplot.h
  )
set(UIS
  ui/mainwindow.ui
  )
include_directories(include)

# wrap the ui file to a c++ header #
qt5_wrap_ui(UI_WRAP ${UIS})
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
# build #
add_executable(main 
	${SOURCES} 
	${HEADERS}
	${UI_WRAP} 
	${MOC_SOURCES})
target_link_libraries(main
	PUBLIC
	Qt5::Core
	Qt5::Gui 
	Qt5::Widgets
    Qt5::PrintSupport
    )
