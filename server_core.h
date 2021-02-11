#ifndef SERVER_CORE_H
#define SERVER_CORE_H

#include <cstdint>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server_core
{
    public:
        Server_core(uint16_t port, uint8_t backlog);
        
        uint16_t get_port();
        void set_port(uint16_t port);

        uint8_t get_backlog();
        void set_backlog(uint8_t backlog);
        
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
