#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define EXIT_CMD "Bye"

int main() {
  int sockfd, n;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in serv_addr;

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("Failed to open socket");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){//converts ip addr from string to binary
    perror("Invalid host");
    exit(EXIT_FAILURE);
  }

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
    perror("Error occurred while connecting to the server");
    exit(EXIT_FAILURE);
  }

  while(1){
    bzero(buffer, BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if(n < 0){
      perror("Error on writing");
      exit(EXIT_FAILURE);
    }

    bzero(buffer, BUFFER_SIZE);

    n = read(sockfd, buffer, BUFFER_SIZE);
    if(n < 0){
      perror("Error on reading");
      exit(EXIT_FAILURE);
    }

    printf("Server: %s\n", buffer);

    if(strncmp(EXIT_CMD, buffer, strlen(EXIT_CMD)) == 0){
      break;
    }
  }

  close(sockfd);
  return 0;
}
