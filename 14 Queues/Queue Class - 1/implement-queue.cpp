#include <iostream>
using namespace std;

class Queue{
   private:
   int *arr;
   int size;
   int front;
   int rear;

   public:
   Queue(int capacity){
    arr = new int[capacity];
    size = capacity;
    front = -1;
    rear = -1;
   }
   void push(int value){
    if(rear == size-1){
        cout <<"Queue if full, cant push" << endl;
    }
    else if(front == -1 && rear == -1){
     front++;
     rear++;
     arr[rear] = value;
    }
    else{
        rear++;
        arr[rear] = value;
    }
   }

   void pop(){
    if(front == -1 && rear == -1){
        cout<<"Queue is empty, cant pop"<<endl;
    }
    else if(front == rear){
        // arr[rear]=-1;   //optional
        front = -1;
        rear=-1;
    }
   else{
    front++;
  }
   }

   int getFront(){
    if(front == -1) cout<<"Queue is empty";
      return arr[front];
   }

   int getRear(){
    if(rear == -1) cout<<"Queue is empty";
    return arr[rear];
   }

   int getSize(){
    if(front == -1 && rear == -1) return 0;
    else return ((rear-front)+1);
   }

   bool isEmpty(){
    if(front == -1 && rear == -1) return true;
    else return false;
   }

};



int main() {
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.getSize()<<endl;

    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    q.push(50);
    cout<<q.isEmpty()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.getSize()<<endl;

 return 0;
}