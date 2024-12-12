#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(int data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (!top) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        int data = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return data;
    }

    void display() {
        Node* temp = top;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int n, val;
    
    cout << "Enter number of elements to push to the stack: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value to push: ";
        cin >> val;
        s.push(val);
    }

    cout << "Stack contents: ";
    s.display();

    cout << "Popped value: " << s.pop() << endl;
    cout << "Stack contents after pop: ";
    s.display();
    return 0;
}
