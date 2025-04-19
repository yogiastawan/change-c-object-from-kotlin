cmake_minimum_required(VERSION 3.22.1)

project(change_c_pointer C)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

file(GLOB SRCS src/*.c)

add_library(${CMAKE_PROJECT_NAME} SHARED ${SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${JNI_LIBRARIES})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)