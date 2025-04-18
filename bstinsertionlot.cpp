#include <iostream>
#include<queue>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int value){
    this->data=value;
    this->left=NULL;
    this->right=NULL:
  }
}
Node* insertIntoBST(Node*root, int data){
  if(root==nullptr){
    root=new Node(data);
    return root;
  }
  if(data>root->data){
    root->right=insertIntoBST(root->right,data);
  }else{
    root->left=insertIntoBST(root->left,data);
  }
  return root;
}
void* createBST(Node* &root){
  cout<<"Enter data"<<endl;
  int data;
  cin>>data;
  while(data!=-1){
    root=insertIntoBST(root,data);
  }
}
void levelorderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(nullptr);
  while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    if(temp==NULL){
      cout<<endl;
      if(!q.empty()){
        q.push(NULL);
      }
    }else{
      cout<<temp->data<<" ";
      if(temp->left!=NULL) q.push(temp->left);
      if(temp->right!=NULL) q.push(temp->right);
    }
  }
}
int main() {
  Node* root=nullptr;
  createBST(root);
  levelorderTraversal(root);
  return 0;
}
