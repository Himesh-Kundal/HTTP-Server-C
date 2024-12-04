#include <stdio.h>
#include <stdlib.h>

#include "Server.h"

int main(){
    struct Server server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 8080, 5, NULL);
    server.launch();
    return 0;
}