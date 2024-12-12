#include <iostream>
using namespace std;

// Define the Node class
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Define the Queue class
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to clean up the allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue: Add an element to the rear of the queue
    void enqueue(int val) {
        Node* newNode = new Node(val);

        if (rear == nullptr) {
            // If the queue is empty, new node is both front and rear
            front = rear = newNode;
        } else {
            // Add the new node at the end of the queue
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << val << endl;
    }

    // Dequeue: Remove an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return -1 if queue is empty
        } else {
            Node* temp = front;
            int dequeuedData = front->data;
            front = front->next;

            // If the queue becomes empty, set rear to nullptr
            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp; // Free the memory of the dequeued node
            return dequeuedData;
        }
    }

    // Peek: Return the front element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

// Main function to demonstrate the queue
int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display the queue
    cout << "Queue after enqueuing elements: ";
    q.display();

    // Dequeue an element
    cout << "Dequeued: " << q.dequeue() << endl;

    // Display the queue after dequeue
    cout << "Queue after dequeue: ";
    q.display();

    // Peek at the front element
    cout << "Front element: " << q.peek() << endl;

    // Dequeue remaining elements
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    // Try to dequeue from an empty queue
    q.dequeue();

    return 0;
}

