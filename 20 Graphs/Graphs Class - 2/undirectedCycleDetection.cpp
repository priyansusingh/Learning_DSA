#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Solution {
    public:
     bool dfsHelper(int node, unordered_map<int,bool> &vis, vector<int> adj[], unordered_map<int,bool> &dfsTracker ){
         vis[node] = true;
         dfsTracker[node] = true;
         
         for(auto nbr: adj[node]){
             if(!vis[nbr]){
                 if(dfsHelper(nbr, vis, adj, dfsTracker)) {
                     return true;
                 }
             }
             else if(dfsTracker[nbr]){
                 return true;
             }
         }
         dfsTracker[node] = false;
         return false;
     }
  
      bool isCyclic(int V, vector<vector<int>> &edges) {
          vector<int> adj[V];
          
          // Convert edge list to adjacency list
          for(auto &edge : edges){
              int u = edge[0];
              int v = edge[1];
              adj[u].push_back(v);
          }
  
          unordered_map<int,bool> vis;
          unordered_map<int,bool> dfsTracker;
  
          for(int i = 0; i < V; i++){
              if(!vis[i]){
                  if(dfsHelper(i, vis, adj, dfsTracker)){
                      return true;
                  }
              }
          }
  
          return false;
      }
  };
  