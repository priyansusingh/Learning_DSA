#include <iostream>
using namespace std;

class Stack{
   public: 
       int *arr;
       int size;
       int top1;
       int top2;
  
  Stack(int capacity){
    arr = new int[capacity];
    size = capacity;
    top1 = -1;   //invalid index
    top2 = size; //invalid index
  }

  void push1(int value){
    if(top2-top1 == 1){
      cout << "Stack Overflow, Cant push"<<endl;
    }
    else{
     top1++;
     arr[top1] = value;
    }
  }

  void push2(int value){
      if(top2-top1 == 1){
      cout << "Stack Overflow, Cant push"<<endl;
    }
    else{
     top2--;
     arr[top2] = value;
    }
  }
   
  void pop1(){
      if(top1 == -1){
        cout << "Stack underflow"<<endl;
      }
      arr[top1] = 0;
      top1--;
  }

  void pop2(){
    if( top2 == size){
      cout<< "Stack Underflow" << endl;
    }
    arr[top2] = 0;
    top2++;
  }

  void print(){
    for(int i=0; i<size; i++){
      cout << arr[i] <<" ";
    }cout<<endl;
  }
};

int main() {
  Stack s(4);

  s.push1(10);
  s.print();
  s.push1(20);
  s.print();
  s.push2(30);
  s.print();
  s.push2(40);
  s.print();
  s.push1(23);
  s.print();
  s.push2(82);
  s.print();
  
  // s.pop1();
  // s.print();

  // s.pop2();
  // s.print();
  

  return 0;
}