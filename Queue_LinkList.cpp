#include <iostream>
using namespace std;

// Node ka structure
struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    // 1. Element insert karna (Enqueue)
    void enqueue(int x) {
        Node* temp = new Node(); // Naya dabba (node) banaya
        temp->data = x;
        temp->next = NULL;

        // Agar queue khali hai, to naya node hi front aur rear hoga
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        // Rear ke aage naya node joro aur rear ko naye node par le jao
        rear->next = temp;
        rear = temp;
        cout << "Inserted: " << x << endl;
    }

    // 2. Element nikalna (Dequeue)
    void dequeue() {
        // Agar queue khali hai
        if (front == NULL) {
            cout << "Queue Khali hai!" << endl;
            return;
        }

        // Front ko ek kadam aage barhao aur purana node delete karo
        Node* temp = front;
        front = front->next;

        // Agar front NULL ho gaya, to rear ko bhi NULL kar do
        if (front == NULL) {
            rear = NULL;
        }

        cout << "Deleted: " << temp->data << endl;
        delete(temp);
    }

    // 3. Queue ko display karna
    void display() {
        if (front == NULL) {
            cout << "Queue Khali hai!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}