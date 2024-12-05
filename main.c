#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "Server.h"

void launch(struct Server *server) {
    const char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello world!";
    int address_length = sizeof(server->address);
    int new_socket;

    while (1) {
        char buffer[1024 * 30] = {0};
        printf("==== Waiting for connection ====\n");

        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        if (new_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            perror("Error reading data");
        } else {
            printf("Received request:\n%s\n", buffer);
        }

        if (write(new_socket, hello, strlen(hello)) < 0) {
            perror("Error writing response");
        }

        close(new_socket);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);

    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 5, launch);
    printf("Starting server on port %d...\n", port);

    server.launch(&server);

    return 0;
}
