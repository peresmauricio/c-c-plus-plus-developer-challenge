cmake_minimum_required(VERSION 3.10)
project(dynamox_challenger)

find_package(spdlog REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER g++)

file(GLOB PROJECT_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/src/*.cpp"
  "${CMAKE_SOURCE_DIR}/src/*.cc"
  "${CMAKE_SOURCE_DIR}/src/*.cxx"
  "${CMAKE_SOURCE_DIR}/src/*.c"
  "${CMAKE_SOURCE_DIR}/libs/*.cpp"
)

file(GLOB PROJECT_HEADERS CONFIGURE_DEPENDS
  "${CMAKE_SOURCE_DIR}/src/*.h"
  "${CMAKE_SOURCE_DIR}/libs/*.h"
)

if(NOT PROJECT_SOURCES)
  message(FATAL_ERROR "No source files found for target dynamox_challenger")
endif()

add_executable(dynamox_challenger ${PROJECT_SOURCES} ${PROJECT_HEADERS})

target_include_directories(dynamox_challenger
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/libs
)

target_link_libraries(dynamox_challenger PRIVATE stdc++ spdlog::spdlog)

