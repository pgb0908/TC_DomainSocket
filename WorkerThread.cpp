//
// Created by Tmax on 2021-04-06.
//

#include "WorkerThread.h"

WorkerThread::WorkerThread() {

}

int WorkerThread::getThreadID() {
    return threadID;
}

void WorkerThread::setThreadID(int val) {
    threadID = val;
}

std::shared_ptr<Handler> WorkerThread::getHandler() {
    return std::shared_ptr<Handler>();
}

void WorkerThread::setHandler(std::shared_ptr<Handler>) {

}

std::shared_ptr<Channel> WorkerThread::request(std::shared_ptr<Channel>) {
    return std::shared_ptr<Channel>();
}


