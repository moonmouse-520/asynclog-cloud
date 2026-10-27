cmake_minimum_required(VERSION 3.16)
project(asynclog_cloud LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra)

find_package(Threads REQUIRED)
find_package(nlohmann_json 3.10 REQUIRED)

include(CheckIncludeFileCXX)
check_include_file_cxx("boost/beast.hpp" HAVE_BOOST_BEAST)
if(NOT HAVE_BOOST_BEAST)
    message(FATAL_ERROR "缺少 Boost 头文件，请先执行: sudo apt install libboost-all-dev")
endif()

set(ASYNCLOG_SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${ASYNCLOG_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Threads::Threads
    nlohmann_json::nlohmann_json
)
