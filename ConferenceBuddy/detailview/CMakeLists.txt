project(libDetailView VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(DetailView detailviewbuilder.cpp)


find_package(Qt5 COMPONENTS Core Widgets Network REQUIRED)


target_link_libraries(DetailView PRIVATE Qt5::Core Qt5::Widgets Qt5::Network)
