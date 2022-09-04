#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

struct sockaddr_in set_socket_addr(sa_family_t sin_family, in_addr_t sin_addr,
                                   int port);

int main() {

  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address =
      set_socket_addr(AF_INET, INADDR_ANY, 9001);

  int connect_status =
      connect(network_socket, (struct sockaddr *)&server_address,
              sizeof(server_address));

  if (connect_status == -1)
    printf("error on connection\n");

  char buffer[256];

  recv(network_socket, &buffer, sizeof(buffer), 0);

  printf("buffer_recv:%s\n", buffer);

  close(network_socket);

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
