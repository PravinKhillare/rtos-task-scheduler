cmake_minimum_required(VERSION 3.10)
project(RTOSTaskScheduler)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(rtos_scheduler
    src/main.cpp
    src/Task.cpp
    src/Scheduler.cpp
)
