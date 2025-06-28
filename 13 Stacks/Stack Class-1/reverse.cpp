#include <iostream>
#include<stack>
using namespace std;

int main() {
  stack<char> s;
  string str = "1234";

  for(int i=0; i<str.length(); i++){
    char ch = str[i];
    s.push(ch);
  }

  while(!s.empty()){
    cout << s.top();
    s.pop();
  }

  return 0;
}