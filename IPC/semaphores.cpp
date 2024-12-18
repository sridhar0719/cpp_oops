#include <iostream>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t semaphore;

void* threadFunction(void* arg) {
    sem_wait(&semaphore);  // Wait for the semaphore (decrement)
    std::cout << "Thread acquired semaphore" << std::endl;
    sleep(1);  // Simulate work
    std::cout << "Thread releasing semaphore" << std::endl;
    sem_post(&semaphore);  // Release the semaphore (increment)
    return nullptr;
}

int main() {
    // Initialize semaphore with a value of 1 (binary semaphore)
    if (sem_init(&semaphore, 0, 1) == -1) {
        perror("sem_init");
        return 1;
    }

    pthread_t threads[2];
    
    // Create two threads that will try to access the semaphore
    for (int i = 0; i < 2; ++i) {
        if (pthread_create(&threads[i], nullptr, threadFunction, nullptr)) {
            perror("pthread_create");
            return 1;
        }
    }

    // Join threads
    for (int i = 0; i < 2; ++i) {
        pthread_join(threads[i], nullptr);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

