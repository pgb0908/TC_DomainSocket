//
// Created by Tmax on 2021-04-06.
//

#ifndef THREAD_COMM_USING_DOMAINSOCKET_HANDLER_H
#define THREAD_COMM_USING_DOMAINSOCKET_HANDLER_H

#include <cstdint>
#include <memory>
#include "Channel.h"

/*
 * Handler는 epoll과 workerThread 사이에 위치하여 통신을 하기위한 객체
 */
class Handler {
private:
    int32_t sink;  // 클라이언트 <-- 서버
    int32_t source; // 서버 <-- 클라

public:
    Handler();

    virtual void sendToWorkerThread(std::shared_ptr<Channel>);
    std::shared_ptr<Channel> sendToEventLayer(std::shared_ptr<Channel>);
};



#endif //THREAD_COMM_USING_DOMAINSOCKET_HANDLER_H
