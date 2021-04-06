//
// Created by Tmax on 2021-04-06.
//

#ifndef THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H
#define THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H

#include <string>
#include "Handler.h"

class WorkerThread {
private:
    std::string threadName;
    int threadID;
    std::shared_ptr<Handler> handler;

public:
    WorkerThread();

    int getThreadID();
    void setThreadID(int);
    std::shared_ptr<Handler> getHandler();
    void setHandler(std::shared_ptr<Handler>);

    std::shared_ptr<Channel> request(std::shared_ptr<Channel>);

};


#endif //THREAD_COMM_USING_DOMAINSOCKET_WORKERTHREAD_H
