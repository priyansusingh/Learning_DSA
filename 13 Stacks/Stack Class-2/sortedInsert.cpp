#include <iostream>
#include<stack> 
using namespace std;

void sortedInsert(stack<int> &s, int value){

    if(s.empty()){
        s.push(value);
        return;
    }
   
    if(!s.empty() && s.top() < value){
        s.push(value);
        return;
    }

    int topE = s.top();
    s.pop();
    sortedInsert(s,value);
    s.push(topE);
}

void print(stack<int> s){
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }cout<<endl;
}

int main() {
  stack<int> s;

  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);
  int value = 23;
  sortedInsert(s, value);
  print(s);
  return 0;
}