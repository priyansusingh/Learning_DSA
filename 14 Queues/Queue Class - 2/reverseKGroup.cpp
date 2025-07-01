#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseInKGroup(queue<int> &q, int k, int count){
  if(count >= k) {
    // count , k se jyada hai iska matlab queue mein k se jyada elements hai
    // iska matlab k ka group ban sakta hai
    stack<int> st;
    // queue se k elements fetch karo aur stack in insert karo
    for(int i=0; i<k; i++){
       int element = q.front();
       q.pop();
       st.push(element);
    }
    //yaha tak sara k elements stack me insert ho gaya hoga
    // ab wo k elements ko fir se queue mein push kar do
    for(int i=0; i<k; i++){
        int element = st.top();
        st.pop();
        q.push(element);
    }
    reverseInKGroup(q,k,count-k);
  }
  else{
    for(int i=0; i<count; i++){
        int element = q.front();
        q.pop();
        q.push(element);
    }
  }
}

int main(){
  queue<int> q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  q.push(70);
  q.push(80);
  q.push(90);
//   q.push(100);
//   q.push(110);
  int count = q.size();
  // count -> k ka group ban sakega ki nahi isse pata chalega
  int k=3;
  reverseInKGroup(q,k,count);

  while(!q.empty()){
    cout << q.front() <<" ";
    q.pop();
  }cout<<endl;
  
}