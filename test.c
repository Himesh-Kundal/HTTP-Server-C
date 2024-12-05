#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "Server.h"

// Function to handle incoming connections
void launch(struct Server *server) {
    const char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello world!";
    int address_length = sizeof(server->address);
    int new_socket;

    while (1) {
        char buffer[1024 * 30] = {0}; // Initialize buffer
        printf("==== Waiting for connection ====\n");

        // Accept a new connection
        new_socket = accept(server->socket, (struct sockaddr *)&server->address, (socklen_t *)&address_length);
        if (new_socket < 0) {
            perror("Error accepting connection");
            continue; // Continue accepting other connections
        }

        // Read data from the client
        ssize_t bytes_read = read(new_socket, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            perror("Error reading data");
        } else {
            printf("Received request:\n%s\n", buffer);
        }

        // Send response
        if (write(new_socket, hello, strlen(hello)) < 0) {
            perror("Error writing response");
        }

        // Close the connection
        close(new_socket);
    }
}

int main() {
    // Create and initialize the server
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 5, launch);
    printf("Server is running on port 8080...\n");

    // Launch the server
    server.launch(&server);

    return 0;
}
