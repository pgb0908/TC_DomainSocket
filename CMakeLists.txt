cmake_minimum_required(VERSION 3.19)
project(Thread_Comm_using_DomainSocket)

include_directories(ThreadPool)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-pthread")

add_executable(Thread_Comm_using_DomainSocket main.cpp Handler.h Channel.cpp Channel.h Handler.cpp WorkerThread.cpp WorkerThread.h ./ThreadPool/KoThreadPool.hpp)