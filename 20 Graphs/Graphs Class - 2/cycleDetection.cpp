#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

class Graph{
  public:
  unordered_map<int,list<int>> adjList;

  void addEdge(int u, int v, bool direction){
      //direction = 0 -> undirected
      //direction = 1 -> directed

      if(direction = 0){
        //undirected edge
        adjList[u].push_back(v);
        adjList[v].push_back(u);
      }
      else{
        //directed ege
        adjList[u].push_back(v);
      }
  }

  void printAdjList(int n){
   for(int i=0; i<n; i++){
   cout << i <<": ";
   cout << "{";
   list<int> temp = adjList[i];
   for(auto j : temp){
    cout << j <<",";
   }
   cout << "}" << endl;
  }
 }

 bool cycleDetectionUndirectedBFS(int src, unordered_map<int,bool> &visited){
    queue<int> q;
    unordered_map<int,int> parent;

    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while(!q.empty()){
        int frontNode =q.front();
        q.pop();

        for(auto nbr:adjList[frontNode]){
            if(!visited[nbr]){
              q.push(nbr);
              visited[nbr] = true;
              parent[nbr] = frontNode;
            }
            else if(visited[nbr] == true && nbr != parent[frontNode]){
                //Cycle present return true
                return true;
            }
        }
    }
    return false;
 }
};


int main() {
  Graph g;
  g.addEdge(0,1,0);
  g.addEdge(1,2,0);
  g.addEdge(3,0,0);
  g.addEdge(2,3,0); 
  int n = 4;
  g.printAdjList(n);
  
  bool ans = false;
  unordered_map<int,bool> visited;
  for(int i=0; i<n; i++){
   if(!visited[i]){
    ans = g. cycleDetectionUndirectedBFS(i,visited);
     if(ans == true){
      break;
     }
   }
  }
  if(ans == true){
    cout << "Cycle present"<<endl;
  }
  else{
    cout <<"Cycle abscent"<<endl;
  }
  return 0;
}