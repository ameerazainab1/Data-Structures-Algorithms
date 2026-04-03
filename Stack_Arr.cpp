#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
int stack_arr[MAX_SIZE];
int top = -1;

void push(int value);
int pop();
void display();

int main()
{
    int data, option;
    while (1)
    {
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Display All Stack Elements" << endl;
        cout << "4.Quit" << endl;
        cout << "Enter Option: ";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter element to push: ";
            cin >> data;
            push(data);
        }
        else if (option == 2)
        {
            data = pop();
            cout <<"Element deleted: "<< data << endl;
        }
        else if (option == 3)
        {
            display();
        }
        else if (option == 4)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid Option." << endl;
        }
    }
}

void push(int value)
{
    if (top == MAX_SIZE - 1)
    {
        cout << "Outflow of stack" << endl;
    }
    else
    {
        top++;
        stack_arr[top] = value;
        cout<<"Element pushed: "<<value<<endl;
    }
    cout << endl;
}

int pop()
{
    if (top == -1)
    {
        cout << "Stack underflow";
    }
    else
    {
        int value = stack_arr[top--];
        return value;
    }
    cout << endl;
}

void display()
{
    if (top == -1)
    {
        cout << "Underflow of stack" << endl;
    }
    else
    {
        for (int i = 0; i < MAX_SIZE - 1; i++)
        {
            cout << stack_arr[i] << " ";
        }
    }
    cout << endl;
}