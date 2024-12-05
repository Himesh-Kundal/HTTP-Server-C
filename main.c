#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Server.h"

void launch(struct Server *server){
    char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello world!";
    int address_length = sizeof(server->address);
    int new_socket;
    while(1){
        char buffer[1024*30]={0};
        printf("==== Waiting for connection ====\n");
        new_socket=accept(server->socket, (struct sockaddr *)&server->address, (socklen_t*)&address_length);
        read(new_socket, buffer, 1024*30);
        printf("%s\n", buffer);
        write(new_socket, hello, strlen(hello));
        close(new_socket);
    }
}

int main(){
    struct Server server =server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 5, launch);
    server.launch(&server);
    return 0;
}