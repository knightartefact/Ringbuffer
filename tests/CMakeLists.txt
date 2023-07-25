cmake_minimum_required(VERSION 3.20)
project(ringbuf_tests)

include(CTest)

file(GLOB_RECURSE TEST_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*test.c)
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/source/*.c)

add_compile_options(--coverage)
add_executable(${PROJECT_NAME} ${TEST_SRC_FILES} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} gcov)
target_link_libraries(${PROJECT_NAME} criterion)
target_link_libraries(${PROJECT_NAME} ringbuf)
add_test(NAME main_test COMMAND ${PROJECT_NAME})
