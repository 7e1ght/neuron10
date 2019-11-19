cmake_minimum_required(VERSION 2.8)

project(neuron10)

find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} "main.cpp")

add_library(SingleNeuron STATIC singleneuron.cpp singleneuron.h)
add_library(trainer STATIC neurontrainer.cpp neurontrainer.h)
add_library(r_element STATIC r_element.cpp r_element.h)

target_link_libraries(trainer ${CMAKE_THREAD_LIBS_INIT} SingleNeuron)
target_link_libraries(r_element ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(${PROJECT_NAME} SingleNeuron trainer r_element)
