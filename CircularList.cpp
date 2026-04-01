#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

struct List{
    Node* head;
    Node* tail;

     List(){              // without this constructor ... it was giving me Segmentation Fault
        head=tail=NULL;   // DSA mein pointers ko hamesha initialize (shuru mein NULL set) karna zaroori hai,
     }                    // warna wo "Dangling Pointers" ban kar program crash kar dete hain.

    void pushFront(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=tail=newNode;
            tail->next=newNode;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=head;
        }
    }

    void pushBack(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=tail=newNode;
            tail->next=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
            newNode->next=head;
        }
    }

    void popFront(){
        Node* temp=head;
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            head=head->next;
            tail->next=head;
            temp->next=NULL;  //to break it's connection with new circularlist it's optional
            delete temp;
        }
    }

    void popBack(){
        
        if(head==NULL){
            return;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
        }else{
            Node* temp=tail;
        Node* prev=head;
        while(prev->next!=tail){
            prev=prev->next;
        }
            tail=prev;
            tail->next=head;
            temp->next=NULL;  //to break it's connection with new circularlist it's optional
            delete temp;
        }
    }

    void print(){
        cout<<head->data<<" ";  
        Node* temp=head->next;
        while(temp!=head)  //it's change here ... in normal list we write temp!=NULL but in circular we have no 
        {                  //next ptr that points to null value so it will create infinite loop    
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    } 
};

int main(){
    List ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushBack(4);
    ll.print();
    ll.popFront();
    ll.popFront();
    ll.popBack();
    ll.print();
}


/*temp->next=NULL;  //to break it's connection with new circularlist
it's not necessary but good practice
Isay "Defensive Programming" kehte hain. Is ke do baray faide hain:

Isolation: Aap ne comment mein sahi likha hai, "to break its connection."
 Agar kisi wajah se delete temp karne mein thori dair ho ya code bohot bara ho, to aapka temp ab list ka hissa nahi raha.
 Wo ab kisi ko point nahi kar raha.

Dangling Pointers se bacho: Agar ghalti se aap baad mein temp->next access karne ki koshish karein (delete karne se pehle),
 to agar wo NULL hoga to program crash ho jayega (jo ke achi baat hai, kyunke aapko pata chal jayega ghalti kahan hai). 
Agar wo list ko point karta raha, to wo chup-chap list ka data kharab kar sakta hai.*/