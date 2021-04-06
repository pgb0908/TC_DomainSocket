//
// Created by Tmax on 2021-04-06.
//

#include "Handler.h"


Handler::Handler() {

}

void Handler::sendToWorkerThread(std::shared_ptr<Channel>) {

}

std::shared_ptr<Channel> Handler::sendToEventLayer(std::shared_ptr<Channel>) {
    return std::shared_ptr<Channel>();
}
