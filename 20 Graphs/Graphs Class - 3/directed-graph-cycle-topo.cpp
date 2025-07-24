#include <iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    public:
        void topoBfs(int n, vector<int> adj[], vector<int> &ans){
           unordered_map<int,int> indegree;
           queue<int> q;
           
           // prepare indegree map
           for(int src=0; src<n; src++){
               for(auto nbr: adj[src]){
                   //src-> nbr
                   indegree[nbr]++;
               }
           }
           
           //check for indegree 0 and push in queue
           //maintain initial state in queue
           for(int i=0; i<n; i++){
             if(indegree[i] == 0){
                 q.push(i);
             }
           }
           while(!q.empty()){
               int frontNode = q.front();
               ans.push_back(frontNode);
               q.pop();
               
               
               for(auto nbr: adj[frontNode]){
                   //remove frontNode->nbr
                   indegree[nbr]--;
                   if(indegree[nbr] == 0){
                       q.push(nbr);
                   }
               }
           }
       } 
     
  
      bool isCyclic(int V, vector<vector<int>> &edges) {
          vector<int> adj[V];
          
          // Convert edge list to adjacency list
          for(auto &edge : edges){
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
          }
  
          vector<int> ans;
          
          topoBfs(V,adj,ans);
          
          if(ans.size() == V){
              // all nodes are present, no cycle
              return false;
          }
          else{
              //cycle present
              return true;
          }
      }
  };
  