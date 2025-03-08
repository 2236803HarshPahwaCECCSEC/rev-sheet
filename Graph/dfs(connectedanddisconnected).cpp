
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
    void dfs(T src,unordered_map<char,bool>&visited){
        visited[src]=true;
        cout<<src<<" ";
        for(auto nbr:adjlist[src]){
            T nbrdata=nbr;
            if(!visited[nbrdata]){dfs(nbrdata,visited);}
        }
    }
};
int main() {
  Graph<char> g;
  g.addEdge('a','b',0);
  g.addEdge('a','c',0);
  g.addEdge('b','c',0);
  g.addEdge('b','d',0);
  g.addEdge('c','e',0);
  g.addEdge('c','f',0);
  g.addEdge('e','f',0);
      unordered_map<char,bool> visited;
  for(char node='a';node<='f';node++){
      if(!visited[node]) 
        g.dfs(node,visited);
  }



}
