cmake_minimum_required(VERSION 3.10)

project(Mp3Player)

# necessary to set the CMAKE_PREFIX_PATH pointed to the Qt

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Quick REQUIRED)
find_package(Qt5 COMPONENTS Multimedia REQUIRED)

include_directories(
    src/
    /home/yzvihunov/libs/taglib-1.11.1/out/usr/local/include/taglib
)

link_directories(
    /home/yzvihunov/libs/taglib-1.11.1/out/usr/local/lib
)

add_executable(
    Mp3Player

    src/main.cpp
    src/RootContext.cpp
    src/ControlModel.cpp
    src/PlaylistModel.cpp
    src/PlaylistItem.cpp
    src/SongInfoReaderThread.cpp

    resources/qml.qrc
)

target_link_libraries(
    Mp3Player 
    
    Qt5::Core 
    Qt5::Widgets 
    Qt5::Quick 
    Qt5::Multimedia
    
    tag
    z
)
