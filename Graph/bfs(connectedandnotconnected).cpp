#include <iostream>
#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
  public:
  unordered_map<T,list<T>>adjlist;
    void addEdge(T u,T v,bool direction){
      //if direction ==true then directed else undirected
      if(direction==1){
        //u se v ki taraf se edge h
        adjlist[u].push_back(v);   
      }else{
        //u se v bhi edge niklegi aur v se u bhi niklegi
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
             }
      
    }
    void bfs(T src,unordered_map<char,bool> &visited){
      
        queue<T>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T frontNode=q.front();
            cout<<frontNode<<" ";
            q.pop();
            for(auto nbr:adjlist[frontNode]){
                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }
            }
        }
    }
    // void printlist(){
    //     for(auto i:adjlist){
    //       cout<<i.first<<"-> {";
    //       for(auto j:i.second){
    //         cout<<j<<" ";
    //       }
    //     cout<<"}"<<endl;

    //     }
    //    }     
};
int main() {
  Graph<char> g;
//   g.addEdge('a','b',0);
//   g.addEdge('a','c',0);
//   g.addEdge('b','c',0);
//   g.addEdge('b','d',0);
//   g.addEdge('c','e',0);
//   g.addEdge('c','f',0);
//   g.addEdge('e','f',0);
g.addEdge('a','b',0);
  g.addEdge('a','c',0);
//   g.addEdge('b','c',0);
//   g.addEdge('b','d',0);
  g.addEdge('d','e',0);
  g.addEdge('f','f',0);
//   g.addEdge('e','f',0);
unordered_map<char,bool> visited;
  for(char node='a';node<'f';node++){
      if(!visited[node]){
          g.bfs(node,visited);
      }
  }
// return 0;
}
