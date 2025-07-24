#include <iostream>
#include<unordered_map>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
    public:
    
    void topoDfs(int src,  unordered_map<int,bool> &vis, vector<int> adj[], vector<int> &ans){
        
        vis[src] = true;
        
        for(auto nbr: adj[src]){
            if(!vis[nbr]){
                topoDfs(nbr,vis,adj,ans);
            }
        }
        
        ans.push_back(src);
    }
      
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
    
              vector<int> adj[V];
            
            // Convert edge list to adjacency list
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
            }
            
            unordered_map<int,bool> visited;
            int n = V;
            vector<int> ans;
            
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    topoDfs(i,visited,adj,ans);
                }
            }
            // reverse the ordering 
            reverse(ans.begin(),ans.end());
            
            return ans;
      }
  };