#include<iostream>
#include<queue>
using namespace std;

class Solution {
    public:
      queue<int> rearrangeQueue(queue<int> q1) {
          // code here
          queue<int> q2;
          int size = q1.size();
          int half = size/2;
          
          while(half--){
              int element = q1.front();
              q1.pop();
              q2.push(element);
          }
          //first half q2 mein hai
          //second half q1 mein hai
          
          int count = q2.size();
          queue<int> ans;
          
          while(count--){
              ans.push(q2.front());
              q2.pop();
              ans.push(q1.front());
              q1.pop();
          }
          
       return ans;
      }
  };