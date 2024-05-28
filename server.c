#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080 //consistent port for client and server
#define BUFFER_SIZE 1024 
#define EXIT_CMD "Bye"

int main() {
  int sockfd, newsockfd, n;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in serv_addr;
  socklen_t addrlen = sizeof(serv_addr);

  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY; //any ipv4 address
  serv_addr.sin_port = htons(PORT);

  if(bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
    perror("Failed to bind");
    exit(EXIT_FAILURE);
  }


  if(listen(sockfd, 4) < 0){
    perror("Failed to listen");
    exit(EXIT_FAILURE);
  }


  if ((newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &addrlen)) < 0){
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  while (1){
    bzero(buffer, BUFFER_SIZE);

    n = read(newsockfd, buffer, BUFFER_SIZE); 
    if(n < 0){
      perror("Error on reading");
      exit(EXIT_FAILURE);
    }
    printf("Client: %s\n", buffer);

    bzero(buffer, BUFFER_SIZE); //empty the buffer before reading i/p from server
    fgets(buffer, BUFFER_SIZE, stdin); 

    n = write(newsockfd, buffer, strlen(buffer));
    if(n < 0){
      perror("Error on writing");
      exit(EXIT_FAILURE);
    }

    if(strncmp(EXIT_CMD, buffer, strlen(EXIT_CMD)) == 0){
      break;
    }
  }

  close(newsockfd);
  close(sockfd);
  return 0;
}
