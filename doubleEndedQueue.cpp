#include <iostream>

using namespace std;

class Deque {
   private:
    int *arr;
    int front;
    int rear;
    int capacity;

   public:
    Deque(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = 0;
    }

    ~Deque() {
        delete[] arr;
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert element.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (front == 0)
            front = capacity - 1;
        else
            front = front - 1;

        arr[front] = element;
        cout << "Element inserted at the front: " << element << endl;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert element.\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1)
            rear = 0;
        else
            rear = rear + 1;

        arr[rear] = element;
        cout << "Element inserted at the rear: " << element << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element.\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1)
            front = 0;
        else
            front = front + 1;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element.\n";
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (rear == 0)
            rear = capacity - 1;
        else
            rear = rear - 1;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty() || rear < 0) {
            cout << "Deque is empty.\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == capacity - 1) || (front == rear + 1);
    }
};

int main() {
    int size, choice, element;
    cout << "Enter the size of the Deque: ";
    cin >> size;
    Deque dq(size);

    do {
        cout << "\n\n***** MENU *****" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Get Front" << endl;
        cout << "6. Get Rear" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to insert at the front: ";
                cin >> element;
                dq.insertFront(element);
                break;

            case 2:
                cout << "Enter the element to insert at the rear: ";
                cin >> element;
                dq.insertRear(element);
                break;

            case 3:
                dq.deleteFront();
                cout << "Element deleted from the front.\n";
                break;

            case 4:
                dq.deleteRear();
                cout << "Element deleted from the rear.\n";
                break;

            case 5:
                element = dq.getFront();
                if (element != -1)
                    cout << "Front element: " << element << endl;
                break;

            case 6:
                element = dq.getRear();
                if (element != -1)
                    cout << "Rear element: " << element << endl;
                break;

            case 7:
                cout << "Exiting the program. Goodbye!";
                exit(0);

            default:
                cout << "Invalid choice! Please enter a valid option.";
        }
    } while (true);

    return 0;
}
