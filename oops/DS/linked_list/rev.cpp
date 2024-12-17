#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr, *current = head, *next = nullptr;

    // Traverse the list and reverse the links
    while (current != nullptr) {
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move prev to current node
        current = next;        // Move current to next node
    }
    
    return prev;  // prev is the new head of the reversed list
}

// Helper function to create a new node
ListNode* createNode(int val) {
    return new ListNode(val);
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a simple linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    cout << "Original list: ";
    printList(head);

    // Reverse the linked list
    ListNode* reversedHead = reverseList(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}

