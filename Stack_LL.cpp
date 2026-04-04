#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    public:
    Node(int value){
        data=value;
        next=NULL;
    }
};

struct Stack{
    Node* top; //top pointer stack ke top node ko point karega you can say it's head

    Stack(){
        top=NULL; 
    }

     void push(int value){
        Node* newNode=new Node(value);
        newNode->next=top; 
        top=newNode; 
        cout<<"Element pushed: "<<value<<endl;
     }

     void pop(){
        Node* temp=top;
        if(top==NULL){
            return;
        }else{
            top=top->next;
            cout<<"Element popped: "<<temp->data<<endl;
            temp=NULL;
            delete temp;
        }
     }

     void displayTop(){
        cout<<"Top on stack: "<<top->data<<endl;
     }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(40);
    s.push(30);

    s. displayTop();
    
    s.pop();
    s.pop();

    s.displayTop();
}