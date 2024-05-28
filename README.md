# Simple TCP Client-Server Application

This is a simple TCP client-server application implemented in C.


### Setting up the Environment

Before compiling the files, ensure that you have `gcc` installed. 

#### Compiling the Files

To compile the server and  client file, use the following command:</br>
`gcc server.c -o server`</br>
`gcc client.c -o client`

### Running the Programs

Make sure to follow the correct order of running the programs, starting with the server and then the client.
 1. First, run the server program by executing the following command in the terminal:
	`./server`	
2. Then, run the client program by executing the following command in another terminal window:
	`./client`

## Demo



https://github.com/Dishant1804/socket-chat/assets/115367435/f4498ea3-2c86-48c3-94f3-660b81130cc5



## Libraries and Their Functions

### Libraries Used

1. **`<netinet/in.h>`**
   - Contains constants and structures needed for internet domain addresses, such as `struct sockaddr_in`.
   
2. **`<stdio.h>`**
   - Provides functions for input and output, such as `printf`, `scanf`, `fgets`, and `perror`.
   
3. **`<stdlib.h>`**
   - Provides functions for memory allocation, process control, conversions, and others, such as `exit`.
   
4. **`<sys/types.h>`**
   - Defines data types used in system calls, such as `socket`, `bind`, and `accept`.
   
5. **`<sys/socket.h>`**
   - Contains definitions of structures needed for sockets, and declarations of functions like `socket`, `bind`, `listen`, `accept`, and `connect`.
   
6. **`<string.h>`**
   - Provides functions for manipulating arrays of characters, such as `strlen`, `strcmp`, `strncpy`, and `bzero`.
   
7. **`<unistd.h>`**
   - Declares miscellaneous functions like `read`, `write`, and `close` used for low-level I/O operations.

### Functions and Their Parameters

#### `socket(int domain, int type, int protocol)`
- **Parameters**:
  - `domain`: Communication domain, e.g., `AF_INET` for IPv4 , `AF_INET6` for IPv6.
  - `type`: Communication type, e.g., `SOCK_STREAM` for TCP , `SOCK_DGRAM` for UDP.
  - `protocol`: Protocol to be used, usually `0` to select the default protocol.
- **Returns**:
  - File descriptor for the new socket, or `-1` if an error occurred.

#### `bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)`
- **Parameters**:
  - `sockfd`: File descriptor of the socket to bind.
  - `addr`: Pointer to `struct sockaddr` containing the address to bind to.
  - `addrlen`: Size (in bytes) of the address structure that addr points to.
- **Returns**:
  - `0` on success, or `-1` if an error occurred.

#### `listen(int sockfd, int backlog)`
- **Parameters**:
  - `sockfd`: File descriptor of the socket to listen on.
  - `backlog`: Number of connections allowed on the incoming queue.
- **Returns**:
  - `0` on success, or `-1` if an error occurred.

#### `accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)`
- **Parameters**:
  - `sockfd`: File descriptor of the socket to accept connections on.
  - `addr`: Pointer to `struct sockaddr` to store the address of the connecting entity.
  - `addrlen`: Pointer to a variable that stores the size of the address structure.
- **Returns**:
  - File descriptor through which further communication takes place, or `-1` if an error occurred.

#### `connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)`
- **Parameters**:
  - `sockfd`: File descriptor of the socket to connect.
  - `addr`: Pointer to `struct sockaddr` containing the address to connect to.
  - `addrlen`: Size (in bytes) of the address structure that addr points to.
- **Returns**:
  - `0` on success, or `-1` if an error occurred.

#### `read(int fd, void *buf, size_t count)`
- **Parameters**:
  - `fd`: File descriptor to read from.
  - `buf`: Buffer to store the read data.
  - `count`: Number of bytes to read.
- **Returns**:
  - Number of bytes read, or `-1` if an error occurred.

#### `write(int fd, const void *buf, size_t count)`
- **Parameters**:
  - `fd`: File descriptor to write to.
  - `buf`: Buffer containing the data to write.
  - `count`: Number of bytes to write.
- **Returns**:
  - Number of bytes written, or `-1` if an error occurred.

#### `close(int fd)`
- **Parameters**:
  - `fd`: File descriptor to close.
- **Returns**:
  - `0` on success, or `-1` if an error occurred.

#### `perror(const char *s)`
- **Parameters**:
  - `s`: Custom message to print before the system error message.
- **Returns**:
  - Nothing. Prints an error message to `stderr`.

#### `exit(int status)`
- **Parameters**:
  - `status`: Exit status. `EXIT_SUCCESS` or `EXIT_FAILURE`.
- **Returns**:
  - Nothing. Terminates the program.

#### `fgets(char *str, int n, FILE *stream)`
- **Parameters**:
  - `str`: Pointer to a buffer where the string is stored.
  - `n`: Maximum number of characters to read.
  - `stream`: File stream to read from.
- **Returns**:
  - Pointer to the string read, or `NULL` if an error occurred.

#### `bzero(void *s, size_t n)`
- **Parameters**:
  - `s`: Pointer to the memory area to be filled with zeroes.
  - `n`: Number of bytes to set to zero.
- **Returns**:
  - Nothing. Sets the memory area to zero.
