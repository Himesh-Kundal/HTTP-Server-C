#ifndef Server.h 
#define Server.h  

#include <sys/socket.h>
#include <netinet/in.h>

struct Server{
  int domain;
  int service;
  int protocol;
  u_long interface;
  int port;
  int backlog;
  
  struct sockaddr_in address;

  int socket;

  void (*launch)(void);
};

struct Server server_construcor(int domain, int service, int protocol, u_long interface, int port, int backlog, voiid (*launch)(void));

#endif
