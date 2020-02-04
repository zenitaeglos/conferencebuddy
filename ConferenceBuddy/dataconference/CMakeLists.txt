set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(DataConference dataconference.cpp
    dataformat.cpp
    dataxmlformat.cpp)


find_package(Qt5 COMPONENTS Core Widgets REQUIRED)


target_link_libraries(DataConference PRIVATE Qt5::Core Qt5::Widgets)

