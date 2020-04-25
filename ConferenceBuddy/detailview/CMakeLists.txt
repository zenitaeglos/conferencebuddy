project(libDetailView VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(DetailView detailviewfactory.cpp
    detailview.cpp
    tuebix/tuebixdetailview.cpp
    fosdem/fosdemdetailview.cpp
    maindetailview.cpp
    tuebix/tuebixview.cpp
    fosdem/fosdemview.cpp)


find_package(Qt5 COMPONENTS Core Widgets Network Multimedia MultimediaWidgets REQUIRED)

SET(QT_USE_QTMULTIMEDIA TRUE)
SET(QT_USE_QTMULTIMEDIAWIDGETS TRUE)
QT5_USE_MODULES (DetailView Multimedia MultimediaWidgets)

#target_link_libraries(DetailView PRIVATE Qt5::Core Qt5::Widgets Qt5::Network)
