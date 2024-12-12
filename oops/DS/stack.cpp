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

// Define the Stack class
class Stack {
private:
    Node* top;  // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() {
        top = nullptr;
    }

    // Destructor to clean up the allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Push: Add an element to the top of the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;  // Point the new node's next to the current top
        top = newNode;        // Update top to the new node
        cout << "Pushed: " << val << endl;
    }

    // Pop: Remove an element from the top of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Return -1 if stack is empty
        } else {
            Node* temp = top;
            int poppedData = top->data;
            top = top->next;  // Move the top pointer to the next node
            delete temp;      // Free the memory of the popped node
            return poppedData;
        }
    }

    // Peek: Return the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    // Display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }
};

// Main function to demonstrate the stack
int main() {
    Stack s;

    // Push elements
    s.push(10);
    s.push(20);
    s.push(30);

    // Display the stack
    cout << "Stack after pushing elements: ";
    s.display();

    // Pop an element
    cout << "Popped: " << s.pop() << endl;

    // Display the stack after pop
    cout << "Stack after pop: ";
    s.display();

    // Peek at the top element
    cout << "Top element: " << s.peek() << endl;

    // Pop remaining elements
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    // Try to pop from an empty stack
    s.pop();

    return 0;
}

