cmake_minimum_required(VERSION 3.1)

project(ConferenceBuddy LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ConferenceBuddy_VERSION_MAJOR 0)
set(ConferenceBuddy_VERSION_MINOR 1)
set(ConferenceBuddy_VERSION_PATCH 0)

set(MYSOURCES "${PROJECT_SOURCE_DIR}/src/mainwindow.h"
    "${PROJECT_SOURCE_DIR}/src/mainwindow.cpp")

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc" ${MYSOURCES})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick Qt5::Widgets)
