#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65); // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT); // Create message queue

    msg_buffer message;
    message.msg_type = 1;
    strcpy(message.msg_text, "Hello, this is IPC!");

    msgsnd(msgid, &message, sizeof(message), 0); // Send message
    std::cout << "Message sent: " << message.msg_text << std::endl;

    // Receive message
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    std::cout << "Received message: " << message.msg_text << std::endl;

    msgctl(msgid, IPC_RMID, NULL); // Destroy message queue

    return 0;
}

