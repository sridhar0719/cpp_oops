#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>

int main() {
    const char* shm_name = "/my_shared_memory";
    const size_t SIZE = 4096;

    // Create and map shared memory
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        return 1;
    }

    // Resize the shared memory segment
    if (ftruncate(shm_fd, SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map the shared memory object into the address space
    void* ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write to shared memory
    const char* message = "Hello from shared memory!";
    memcpy(ptr, message, strlen(message) + 1);

    std::cout << "Written to shared memory: " << message << std::endl;

    // Cleanup
    if (munmap(ptr, SIZE) == -1) {
        perror("munmap");
        return 1;
    }
    if (close(shm_fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}

