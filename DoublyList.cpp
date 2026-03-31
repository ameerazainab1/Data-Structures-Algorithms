#include <iostream>
using namespace std;

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
    Node(int value){
        data=value;
        prev=next=NULL;
    }
};

struct list{
    struct Node* head;
    struct Node* tail;

    list(){
        head=tail=NULL;
    }
    
    void pushFront(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void pushBack(int value){
        Node* newNode=new Node(value);
            if(head==NULL){
                head=tail=newNode;
            }else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }

    void popFront(){
        Node* temp=head;
        if(head==NULL){
            return;
        }else{
            // head->next=head; //(Iska matlab: Head ke 'next' dibbe mein head ka address daal do).
            head = head->next; //(Iska matlab: Head ka label uthao aur agle node par rakh do)
            if(head!=NULL){
                head->prev=NULL;
             }
                temp->next=NULL;
                delete temp;
        }
    }

    void popBack(){
        if(head==NULL){ //checking head here to see if List is empty or not
            return;
        }else{
            Node* temp=tail;
            tail=tail->prev;
            tail->next=NULL;
            temp->prev==NULL;
            delete temp;
        }
    }

    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    list ll;
    ll.pushFront(10);
    ll.pushFront(20);
    ll.pushFront(30);
    ll.print();
    ll.pushBack(40);
    ll.popFront();
    ll.print();
    ll.popBack();
    ll.print();
}