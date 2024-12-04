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

  void (*launch)(void);
};

struct Server server_construcor(int domain, int service, int protocol, u_long interface, int port, int backlog, struct sockaddr_in address, voiid (*launch)(void));

#endif
