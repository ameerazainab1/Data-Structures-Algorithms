#include <iostream>
using namespace std;

int Rear=-1;
int Front=-1;
const int MAX_SIZE=5;
int queue_arr[MAX_SIZE];

int IsEmpty(){
    if(Front==-1&&Rear==-1){
        return true;
    }else{
        return false;
    }
}

int IsFull(){
    if(Rear==MAX_SIZE-1){
        return true;
    }else{
        return false;
    }
}

int DeQueue()
{
    if(IsEmpty()){
        cout<<"Stack Underflow"<<endl;
        return 0;
    }else if(Front==Rear){
        int item=queue_arr[Front];
        cout<<"Element deleted: "<<item;
        Front=Rear=-1;
    }else{
        int item=queue_arr[Front];
        cout<<"Element deleted: "<<item;
        Front=Front+1;
    }
    cout<<endl;
};

void EnQueue(int value){
    if(IsFull()){
        cout<<"Queue Overflow"<<endl;
        return;
    }else if(IsEmpty()){
            Front=Rear=0;
            queue_arr[Rear]=value;
        }else{
            Rear++;
        queue_arr[Rear]=value;
        }
    cout<<"Element inserted: "<<value<<endl;    
    };

    void print(){
        for(int i=Front;i<=Rear;i++){
            cout<<queue_arr[i]<<" ";
        }
        cout<<endl;
    }
int main(){
    EnQueue(10);
    EnQueue(20);
    EnQueue(10);
    EnQueue(20);
    EnQueue(10);
    EnQueue(20);
    print();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    DeQueue();
    print();
}