#include <sys/types.h>
#include <sys/socket.h>
#include <cstring>
#include "server_core.h"


/*Server_core handles all server networking*/
Server_core::Server_core(uint16_t p, uint8_t b) {
    set_port(p);
    set_backlog(b);

    init_socket();
    bind();
}

/*Initializes socket FD, specifically a TCP socket*/
void Server_core::init_socket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    int on = 1;

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(int));
}

/*Binds the socket to a particular port on localhost*/
void Server_core::bind() {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    
    ::bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

/*Server starts listening for connections using the socket
 * backlog is the number of possible concurrent clients*/
void Server_core::listen() {
    ::listen(sockfd, backlog);
}

uint16_t Server_core::get_port() {
    return port;
}

void Server_core::set_port(uint16_t p) {
    this->port = p;
}

uint8_t Server_core::get_backlog() {
    return backlog;
}

void Server_core::set_backlog(uint8_t b){
    this->backlog = b;
}
