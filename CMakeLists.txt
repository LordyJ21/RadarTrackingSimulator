cmake_minimum_required(VERSION 3.10)

project(RadarTrackingSimulator)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

add_executable(RadarTrackingSimulator
    src/main.cpp
    src/MovingObject.cpp
    src/RadarSystem.cpp
    src/RadarScanner.cpp
    src/ThreatDetector.cpp
    src/CollisionEngine.cpp
    src/Renderer.cpp
    src/Logger.cpp
)

target_link_libraries(RadarTrackingSimulator
    sfml-graphics
    sfml-window
    sfml-system
)