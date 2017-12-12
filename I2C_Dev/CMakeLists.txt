project(I2C_Dev)
cmake_minimum_required(VERSION 2.8.11)

add_definitions(-std=gnu++11)

include_directories(
	include
)

file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})

target_link_libraries(main m) 
