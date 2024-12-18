#include <iostream>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal) {
    std::cout << "Caught signal " << signal << std::endl;
}

int main() {
    // Register signal handler
    signal(SIGINT, signalHandler);  // Catch Ctrl+C (SIGINT)

    std::cout << "Waiting for SIGINT (Ctrl+C)..." << std::endl;

    // Infinite loop to keep the program running until SIGINT is received
    while (true) {
        sleep(1);  // Simulate work
    }

    return 0;
}

