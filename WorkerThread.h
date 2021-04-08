//
// Created by Tmax on 2021-04-07.
//

#ifndef THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H
#define THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H


#include <memory>
#include "Channel.h"

class WorkerThread {
private:
    int channel;

public:
    std::shared_ptr<Channel> request(std::shared_ptr<Channel>);
    void run();
};


#endif //THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H
