#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
    const char* socket_path = "/tmp/my_socket";
    
    // Create socket
    int server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

    // Bind socket to the file
    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    std::cout << "Server listening on " << socket_path << std::endl;

    int client_fd = accept(server_fd, NULL, NULL);  // Accept client connection
    if (client_fd == -1) {
        perror("accept");
        return 1;
    }

    // Receive data from the client
    char buffer[256];
    ssize_t len = read(client_fd, buffer, sizeof(buffer));
    if (len == -1) {
        perror("read");
        return 1;
    }
    buffer[len] = '\0';  // Null-terminate the string
    std::cout << "Received message: " << buffer << std::endl;

    close(client_fd);
    close(server_fd);
    unlink(socket_path);  // Clean up the socket file
    return 0;
}

