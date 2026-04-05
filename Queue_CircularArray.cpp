#include <iostream>
using namespace std;

// 1. Global variables for easy access (Aapka style)
const int MAX_SIZE = 5;
int queue_arr[MAX_SIZE];
int Front = -1;
int Rear = -1;

// 2. Modulo logic se check karna ke queue full hai ya nahi
bool IsFull() {
    return ((Rear + 1) % MAX_SIZE == Front);
}

// 3. Simple check for Empty
bool IsEmpty() {
    return (Front == -1);
}

// 4. EnQueue Operation
void EnQueue(int value) {
    if (IsFull()) {
        cout << "Queue Overflow! Can't add " << value << endl;
        return;
    }
    if (IsEmpty()) {
        Front = Rear = 0; // Pehla element index 0 par
    } else {
        // Rear ko circular move karo
        Rear = (Rear + 1) % MAX_SIZE; 
    }
    queue_arr[Rear] = value;
    cout << "Element inserted: " << value << " at Index: " << Rear << endl;
}

// 5. DeQueue Operation
void DeQueue() {
    if (IsEmpty()) {
        cout << "Queue Underflow! Kuch delete nahi ho sakta." << endl;
        return;
    }
    
    int item = queue_arr[Front];
    cout << "Element deleted: " << item << " from Index: " << Front << endl;

    if (Front == Rear) {
        // Agar aik hi element tha, toh reset kar do
        Front = Rear = -1;
    } else {
        // Front ko circular move karo
        Front = (Front + 1) % MAX_SIZE;
    }
}

// 6. Display function jo circular ghoomay ga
void print() {
    if (IsEmpty()) {
        cout << "Queue Khali hai!" << endl;
        return;
    }
    cout << "Current Queue: ";
    int i = Front;
    while (true) {
        cout << queue_arr[i] << " ";
        if (i == Rear) break;
        i = (i + 1) % MAX_SIZE; // Circular increment
    }
    cout << endl;
}

int main() {
    EnQueue(10);
    EnQueue(20);
    EnQueue(30);
    EnQueue(40);
    EnQueue(50);
    print();

    DeQueue(); // Index 0 khali ho jayega
    DeQueue(); // Index 1 khali ho jayega

    cout << "After deleting 2, let's add 60 (Circular logic test)..." << endl;
    EnQueue(60); // Ye wapas Index 0 par jaye ga!
    
    print();
    return 0;
}