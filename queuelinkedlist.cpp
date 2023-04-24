#include <iostream>
using namespace std;

// Define the structure of each node in the linked list
struct Node {
    int data;
    Node* next;
};

// Define the queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == NULL && rear == NULL);
    }

    // Function to add an element to the rear of the queue
    void enqueue(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Function to remove an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        if (front == rear) {
            front = rear = NULL;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Driver program to test the queue implementation
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}