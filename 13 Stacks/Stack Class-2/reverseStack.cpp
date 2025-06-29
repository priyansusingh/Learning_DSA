#include <iostream>
#include<stack>
using namespace std;

void insertAtBottom( stack<int> &s, int value){
   if(s.empty()){
    s.push(value);
    return;
   }

   int topELement = s.top();
   s.pop();
   insertAtBottom(s,value);
   s.push(topELement);
}

void reverseStack( stack<int> &s){
    if(s.empty()){
      return;
    }
    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,topElement);
}

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
      }cout <<endl;
}

int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  
  print(s);
  reverseStack(s);
  print(s);

  return 0;
}