#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include<cstring>
int main() {
    int pipefds[2];
    pid_t pid;

    if (pipe(pipefds) == -1) {
        std::cerr << "Pipe failed" << std::endl;
        return 1;
    }

    pid = fork(); // Create a child process

    if (pid == -1) {
        std::cerr << "Fork failed" << std::endl;
        return 1;
    }

    if (pid == 0) { // Child process
        close(pipefds[1]);  // Close write end
        char buffer[128];
        read(pipefds[0], buffer, sizeof(buffer));  // Read from pipe
        std::cout << "Child received: " << buffer << std::endl;
        close(pipefds[0]);
    } else { // Parent process
        close(pipefds[0]);  // Close read end
        const char* message = "Hello from parent!";
        write(pipefds[1], message, strlen(message) + 1); // Write to pipe
        close(pipefds[1]);
    }

    return 0;
}

