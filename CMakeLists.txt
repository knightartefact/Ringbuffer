cmake_minimum_required(VERSION 3.20)
project("ringbuf")

option(ENABLE_TESTS "If enabled, build the unit tests and run them with CTest." OFF)

add_compile_options(-Wall -Wextra)
file(GLOB_RECURSE SRC_FILES source/*.c)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
