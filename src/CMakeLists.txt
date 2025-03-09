cmake_minimum_required(VERSION 3.28)
project(ProceduralAnimation LANGUAGES CXX)


set(CORE_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/public/Core")
set(CORE_SOURCE_DIRS  "${PROJECT_SOURCE_DIR}/private/Core")
set(CORE_INCLUDE_DIRS ${CORE_INCLUDE_DIRS} CACHE STRING "Path to Core include directory")
set(CORE_SOURCE_DIRS ${CORE_SOURCE_DIRS} CACHE STRING "Path to Core source directory")

add_library(EventHandling STATIC 
    "${CORE_SOURCE_DIRS}/Events/EventHandler/EventHandler.cpp"
    "${CORE_SOURCE_DIRS}/Events/Event/Event.cpp"    
)
add_library(Core STATIC 
    "${CORE_SOURCE_DIRS}/RenderWindow/RenderWindow.cpp"   
)

target_include_directories(EventHandling PUBLIC
    "${CORE_INCLUDE_DIRS}"
    "${CORE_INCLUDE_DIRS}/Events/"
)

target_include_directories(Core PRIVATE 
    "${CORE_INCLUDE_DIRS}/RenderWindow/"
    "${CORE_INCLUDE_DIRS}/Events/"
)


target_include_directories(EventHandling PRIVATE "${FETCHCONTENT_BASE_DIR}/sfml_build/src/")
target_include_directories(Core PRIVATE "${FETCHCONTENT_BASE_DIR}/sfml_build/src/")


target_link_libraries(EventHandling PRIVATE SFML::Graphics)
target_link_libraries(Core PRIVATE SFML::Graphics)

target_link_libraries(Core PRIVATE EventHandling)
# Debugging messages
message(STATUS "CORE_INCLUDE_DIRS: ${CORE_INCLUDE_DIRS}")
message(STATUS "Events directory: ${CORE_INCLUDE_DIRS}/Events")
message(STATUS "Event/Event.hpp path: ${CORE_INCLUDE_DIRS}/Events/Event/Event.hpp")