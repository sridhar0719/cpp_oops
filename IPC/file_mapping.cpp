#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main() {
    const char* filename = "/tmp/my_mmap_file";
    const size_t SIZE = 4096;

    // Open file
    int fd = open(filename, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Resize file
    if (ftruncate(fd, SIZE) == -1) {
        perror("ftruncate");
        return 1;
    }

    // Map file into memory
    void* ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Write to memory-mapped file
    const char* message = "Hello, this is a memory-mapped file!";
    memcpy(ptr, message, strlen(message) + 1);

    std::cout << "Written to file: " << message << std::endl;

    // Cleanup
    if (munmap(ptr, SIZE) == -1) {
        perror("munmap");
        return 1;
    }
    close(fd);

    return 0;
}

