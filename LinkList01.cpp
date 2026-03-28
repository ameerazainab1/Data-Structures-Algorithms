#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

class List{
    Node* head;
    Node* tail; //tail pointer ki value user kese set kr sakta hai? tail pointer ki value pushBack function main set ho jati hai
    public: List(){
        head=tail=NULL;
    }

    void pushFront(int value){
        Node* newNode=new Node(value); //dynamic object persist in memory after function call
        //Node newNode(value); static object don't exists in memoery after function call
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head; //newNode pointer main phle wale head ki value store ho jaye gi
            head=newNode;//newNode ki value head pointer main ja kr store ho jaye gi yani newNode pointer main jo value hai wo ab head hai 
        }
    }

    void pushBack(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode; //tail pointer main value
            tail=newNode;
        }
    }

    void popFront(){
        Node* temp=head;  //temp pointer main head ki value store ho jaye gi
        if(head==NULL){
            return;
        }else{
            head=head->next; //head main next node ki value store ho jaye gi
            temp=NULL; //temp pointer yani head ki purani value ko NULL kr do
            delete temp;
        }
    }

    void popBack(){
        Node* temp=head;
        Node* prev=NULL;
        if(temp==NULL){
            return;
        }
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        delete temp;
    }

    void searchNode(int value){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==value){
                cout<<temp->data<<" and "<<temp->next<<endl;
            }temp=temp->next;
        }
    };

    void updateNode(int value){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==value){
                 temp->data=100;
            }temp=temp->next;
        }
    };

    void printLinkList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    List ll;

    ll.pushFront(10);
    ll.pushFront(20);
    ll.pushFront(30);

    ll.pushBack(40);

    ll.popFront();
    
    ll.popBack();

    ll.searchNode(20);

    ll.updateNode(30);

    ll.printLinkList();
}