cmake_minimum_required(VERSION 3.16)
project(Task_2)

option(ENABLE_ADDRESS "Enable address sanitizer" OFF)
option(ENABLE_THREAD "Enable thread sanitizer" OFF)

if (ENABLE_ADDRESS AND ENABLE_THREAD)
  message(FATAL_ERROR "Cannot enable both AddressSanitizer and ThreadSanitizer at the same time")
elseif (ENABLE_ADDRESS)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
elseif (ENABLE_THREAD)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -g")
endif()

add_executable(${PROJECT_NAME} main.cpp)