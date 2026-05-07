#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node{value, NULL};

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Search element
void search(Node* head, int target) {
    int position = 0;

    while (head != NULL) {
        if (head->data == target) {
            cout << "Found Number : " << head->data << endl;
            return;
        }
        head = head->next;
        position++;
    }

    cout << "Not found\n";
}

// Delete a node
void deleteNode(Node*& head, int value) {
    if (head == NULL) return;

    // If head is target
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    // Input 
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nLinked List: ";
    display(head);

    // Search
    int target;
    cout << "\nEnter value to search: ";
    cin >> target;
    search(head, target);

    // Delete
    int delValue;
    cout << "\nEnter value to delete: ";
    cin >> delValue;
    deleteNode(head, delValue);

    cout << "\nAfter deletion: ";
    display(head);

    return 0;
}
