#include <iostream>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
    const char* socket_path = "/tmp/my_socket";

    // Create socket
    int client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_fd == -1) {
        perror("socket");
        return 1;
    }

    sockaddr_un addr;
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

    // Connect to the server
    if (connect(client_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    const char* message = "Hello, Server!";
    ssize_t len = write(client_fd, message, strlen(message));
    if (len == -1) {
        perror("write");
        return 1;
    }

    std::cout << "Sent message: " << message << std::endl;

    close(client_fd);
    return 0;
}

