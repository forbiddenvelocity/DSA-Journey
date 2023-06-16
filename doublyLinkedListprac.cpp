#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void insertAtTail(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    void deleteAtHead() {
        if (head == nullptr) {
            cout << "Doubly linked list is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "Doubly linked list is empty. Nothing to delete." << endl;
            return;
        }

        if (position == 0) {
            deleteAtHead();
            return;
        }

        Node* current = head;
        int currentPosition = 0;

        while (current != nullptr && currentPosition < position) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Invalid position. Node not found." << endl;
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
    }

    void displayForward() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtHead(3);
    dll.insertAtHead(2);
    dll.insertAtHead(1);

    cout << "Doubly linked list (forward): ";
    dll.displayForward();

    cout << "Doubly linked list (backward): ";
    dll.displayBackward();

    dll.deleteAtHead();

    cout << "Doubly linked list after deleting at the head (forward): ";
    dll.displayForward();

    dll.insertAtTail(4);
    dll.insertAtTail(5);

    cout << "Doubly linked list (forward): ";
    dll.displayForward();

    cout << "Doubly linked list (backward): ";
   