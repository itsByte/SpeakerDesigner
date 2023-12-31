cmake_minimum_required(VERSION 3.16)

project(SpeakerDesigner VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
add_test(NAME Run COMMAND SpeakerDesigner)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGL OpenGLWidgets)
find_package(Qwt REQUIRED)

qt_standard_project_setup()

include_directories(${PROJECT_SOURCE_DIR}/src)

qt_add_executable(SpeakerDesigner
    src/ui/mainwindow.ui
    src/mainwindow.cpp
    src/main.cpp
    src/driver.cpp 
    src/response.cpp 
    src/bodeplot.cpp
    src/tracker.cpp
    src/treewidget.cpp
)

target_link_libraries(SpeakerDesigner PRIVATE Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets Qwt::Qwt)

set_target_properties(SpeakerDesigner PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)