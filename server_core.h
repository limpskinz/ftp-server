#ifndef SERVER_CORE_H
#define SERVER_CORE_H

#include <cstdint>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class server_core
{
    public:
        server_core(uint16_t port, uint8_t backlog);
    private:
        uint16_t port;
        int sockfd;
        uint8_t backlog;
        struct sockaddr_in server_addr;
        struct sockaddr_storage client_addr;
        socklen_t addrlen;

        void init_socket();
        void bind();
        void listen();
};

#endif /* SERVER_CORE_H */
