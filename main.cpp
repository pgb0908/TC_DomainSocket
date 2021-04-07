#include <iostream>
#include <cstring>

#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/un.h>
#include <fcntl.h>

#include "Handler.h"

#define maxEvent 1000
#define buffer_size 1000
#define BACKLOG 10

void error_handling(const char*);

int32_t setup_domain_socket();

int main() {
    int32_t handler_listener;
    int32_t epfd;
    struct epoll_event event;
    struct epoll_event events[maxEvent];
    char buffer[buffer_size];

    // Handler 객체 생성
    std::shared_ptr<Handler> handler = std::make_shared<Handler>();

    // epoll create
    epfd = epoll_create(maxEvent);
    if(epfd < 0){
        error_handling("epoll create");
    }

    handler_listener = setup_domain_socket();

    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = handler_listener;
    // epfd에 관심 이벤트를 추가
    epoll_ctl(epfd, EPOLL_CTL_ADD, handler_listener, &event);

    // event loop 시작
    for(;;){
        // epoll wait, epfd에 일어난 일을 events로 전달
        int i;
        int nfd = epoll_wait(epfd, events, maxEvent, -1);

        for(i = 0; i < nfd; i++){

            if(events[i].data.fd == handler_listener){
                // accpet
                struct sockaddr_un client_addr;
                socklen_t client_addr_len = sizeof(client_addr);

                int client = accept(handler_listener,
                                    (struct sockaddr*)&client_addr, &client_addr_len);
                if(client < 0){
                    error_handling("accept");
                    continue;
                }

                int flag = fcntl(client, F_GETFL, 0);
                fcntl(client, F_SETFL, flag | O_NONBLOCK);
                memset(&event, 0, sizeof(event));
                event.events = EPOLLIN;
                event.data.fd = client;
                // client fd로부터 값이 들어오면 이벤트 감지
                epoll_ctl(epfd, EPOLL_CTL_ADD, client, &event);

            }else{
                // read
                int client = events[i].data.fd;
                int n = read(client, buffer, sizeof(buffer));
                if(n < 0){
                    error_handling("read");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, client, &event);
                    close(client);
                }else if(n == 0){
                    epoll_ctl(epfd, EPOLL_CTL_DEL, client, &event);
                    close(client);
                }else{
                    // 일을 배정해줌  sentToWorkerThread
                }
            }
        }
    }

    return 0;
}

int setup_domain_socket() {
    int sock;
    struct sockaddr_un sun;

    sock = socket(AF_UNIX, SOCK_DGRAM, 0);
    if(sock < 0){
        error_handling("socket creating");
    }

    memset(&sun, 0, sizeof(sun));

    sun.sun_family = AF_UNIX;
    strcpy(sun.sun_path, "/mnt/c/Users/Tmax/CLionProjects/Thread_Comm_using_DomainSocket");
    int sock_addr_len = sizeof(sun.sun_family) + strlen(sun.sun_path);

    if(bind(sock, (struct sockaddr*)&sun, sock_addr_len) < 0){
        close(sock);
        error_handling("binding");
    }

    if(listen(sock, BACKLOG) < 0){
        close(sock);
        error_handling("listening");
    }


    return 0;
}

void error_handling(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
