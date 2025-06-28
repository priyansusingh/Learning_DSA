#include <iostream>
using namespace std;

class Stack{
  public:
  int *arr;
  int size;
  int top;

  Stack(int capacity){
    arr = new int[capacity];
    size = capacity;
    top = -1;
  }

  void push(int value){
     if(top == size-1){
      cout << "Stack Overflow" << endl;
     }
     else{
      top++;
      arr[top] = value;
     }
  }

  void pop(){
     if(top == -1){
      cout << "Stack Underflow, no element in stack"<<endl;
     }
     else{
      arr[top] = -1;
      top--;
     }
  }

  int getSize(){
     return top+1;
  }

  bool isEmpty(){
    if( top == -1){
      return true;
    }
    else{
      return false;
    }
  }

  int getTop(){
    if(top == -1){
      cout << "Stack is empty" << endl;
      return -1;
    }
    else{
      return arr[top];
    }
  }

  void print(){
    cout<< "Printing Stack: "<<endl;
    for(int i=0; i<size; i++){
      cout << arr[i] <<" ";
    }cout << endl;
  }

};

int main() {
  Stack s(5);
  s.print();

  s.push(10);
  s.print();
  s.push(20);
  s.print();
  s.push(30);
  s.print();
  s.push(40);
  s.print();
  s.push(50);
  s.pop();
  cout << s.getSize() << endl;
  cout << s.getTop() << endl;
  cout << s.isEmpty() << endl;
  return 0;
}