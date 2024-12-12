#include <iostream>
#define SIZE 5
using namespace std;

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() { front = rear = -1; }

    void enqueue(int value) {
        if ((front == 0 && rear == SIZE - 1) || (rear == front - 1)) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = rear = 0;
        else if (rear == SIZE - 1) rear = 0;
        else rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else if (front == SIZE - 1) front = 0;
        else front++;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is Empty" << endl;
            return;
        }
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        } while (i != (rear + 1) % SIZE);
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, val;

    do {
        cout << "\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
