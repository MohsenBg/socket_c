#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

struct sockaddr_in set_socket_addr(sa_family_t sin_family, in_addr_t sin_addr,
                                   int port);

int main() {
  char message[256] = "you are connecting to server";
  int server_socket;

  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server_address =
      set_socket_addr(AF_INET, inet_addr("127.0.0.1"), 9002);

  bind(server_socket, (struct sockaddr *)&server_socket,
       sizeof(server_address));

  listen(server_socket, 5);

  int client_socket;

  client_socket = accept(server_socket, NULL, NULL);

  send(client_socket, message, sizeof(message), 0);

  close(server_socket);

  return 0;
}

struct sockaddr_in set_socket_addr(sa_family_t sin_family, in_addr_t sin_addr,
                                   int port) {
  struct sockaddr_in server_address;
  server_address.sin_family = sin_family;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = sin_addr;
  return server_address;
}
