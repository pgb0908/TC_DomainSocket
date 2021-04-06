cmake_minimum_required(VERSION 3.19)
project(Thread_Comm_using_DomainSocket)

set(CMAKE_CXX_STANDARD 11)

add_executable(Thread_Comm_using_DomainSocket main.cpp Handler.h Channel.cpp Channel.h Handler.cpp WorkerThread.cpp WorkerThread.h)