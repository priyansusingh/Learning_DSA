#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q){
   stack<int> st;

   while(!q.empty()){
    int element = q.front();
    q.pop();
    st.push(element);
   }
   // ab tak queue ke saare elements stack me push ho chuke honge
   while(!st.empty()){
    int element = st.top();
    st.pop();
    q.push(element);
   }
}

void reverseQueueRec(queue<int> &q){
    if(q.empty()){
        return;
    }

    int topE = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(topE);
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    reverseQueueRec(q);

    while(!q.empty()){
      cout << q.front() <<" ";
      q.pop();
    }cout<<endl;

    return 0;
}