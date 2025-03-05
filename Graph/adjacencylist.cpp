#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;
template<typename T>
// class Graph{
//   public:
//   unordered_map<int,list<int>>adjlist;
//     void addEdge(int u,int v,bool direction){
//       //if direction ==true then directed else undirected
//       if(direction==1){
//         //u se v ki taraf se edge h
//         adjlist[u].push_back(v);   
//       }else{
//         //u se v bhi edge niklegi aur v se u bhi niklegi
//         adjlist[u].push_back(v);
//         adjlist[v].push_back(u);
//              }
//         cout<<"printing list"<<endl;
//         printlist();
//     }
//     void printlist(){
//         for(auto i:adjlist){
//           cout<<i.first<<"-> {";
//           for(auto j:i.second){
//             cout<<j<<" ";
//           }
//         cout<<"}"<<endl;

//         }
//        }     
// };
class Wgraph{
  public:
  unordered_map<T,list<pair<T,int>>>adjlist;
  void addEdge(T u,T v,int wt,bool direction){
    if(direction==1){
      adjlist[u].push_back({v,wt});
    }else{
      adjlist[u].push_back({v,wt});
      adjlist[v].push_back({u,wt});
    }
  print();
  cout<<endl;
  }
  void print(){
    for(auto i:adjlist){
      cout<<i.first<<"->{";
      for(auto p:i.second){
         cout<<"{"<<p.first<<","<<p.second<<"},";
      }
      cout<<"}"<<endl;
    }
  }
};
int main() {
  // Graph g;
  // g.addEdge(0,1,1);
  // g.addEdge(1,2,1);
  // g.addEdge(1,3,1);
  // g.addEdge(2,3,1);
  Wgraph<char> g;
  g.addEdge('a','b',2,1);
  g.addEdge('e','d',54,1);

} 
