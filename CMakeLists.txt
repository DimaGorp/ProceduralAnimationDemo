cmake_minimum_required(VERSION 3.28)
project(ProceduralAnimation LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)





set(FETCHCONTENT_BASE_DIR "${PROJECT_SOURCE_DIR}/thirdparty/")
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
    )
FetchContent_MakeAvailable(SFML)

add_subdirectory(src/)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)

target_link_libraries(main PRIVATE SFML::Graphics)
target_link_libraries(main PRIVATE Core)

target_include_directories(main PRIVATE ${CORE_INCLUDE_DIRS})