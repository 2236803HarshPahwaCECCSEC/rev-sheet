#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
	int data;
	Node* left;
	Node* right;


	Node(int val) {
	  this->data = val;
	  this->left = NULL;
	  this->right = NULL;
	}
};

Node* createTree() {
  cout << "Enter the value for Node : " ;
  int value;
  cin >> value;

  if(value == -1) {
	return NULL;
  }

  //create Node;
  Node* root = new Node(value);
  cout << "Entering in left of: "<< value << endl;
  root->left = createTree() ;
  cout << "Entering in right of: "<< value << endl;
  root->right = createTree();
  return root;
}


void levelOrderTraversal(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);
  cout << endl;
  while(!q.empty()) {
	Node* temp = q.front();
	q.pop();

	if(temp == NULL) {
	  cout << endl;
	  if(!q.empty()) {
		q.push(NULL);
	  }
	}
	else {
	  cout << temp->data << " ";
	  if(temp->left != NULL) {
		q.push(temp->left);
	  }
	  if(temp->right != NULL) {
		q.push(temp->right);
	  }
	}


  }
}

void printTopView(Node*root){
  map<int,int> hdTonodemap;
  queue<pair<Node*,int>> q;
  q.push(make_pair(root,0));
  while(!q.empty()){
    pair<Node*,int> temp=q.front();
    q.pop();
    Node* frontNode=temp.first;
    int hd=temp.second;
    if(hdTonodemap.find(hd)==hdTonodemap.end()){
      hdTonodemap[hd]=frontNode->data;
    }
    if(frontNode->left!=NULL){
      q.push(make_pair(frontNode->left,hd-1));
    }
    if(frontNode->right!=NULL){
      q.push(make_pair(frontNode->right,hd+1));
    }
  }
  for(auto i:hdTonodemap){
    cout<<i.second<<" ";
  }

  
}
void printBottomView(Node*root){
  map<int,int> hdTonodemap;
  queue<pair<Node*,int>> q;
  q.push(make_pair(root,0));
  while(!q.empty()){
    pair<Node*,int> temp=q.front();
    q.pop();
    Node* frontNode=temp.first;
    int hd=temp.second;
    if(hdTonodemap.find(hd)==hdTonodemap.end()){
      hdTonodemap[hd]=frontNode->data;
    }
    if(frontNode->left!=NULL){
      q.push(make_pair(frontNode->left,hd-1));
    }
    if(frontNode->right!=NULL){
      q.push(make_pair(frontNode->right,hd+1));
    }
  }
  for(auto i:hdTonodemap){
    cout<<i.second<<" ";
  }

  
}
void printLeftView(Node* root, int level, vector<int>& leftView) {
  if(root == NULL) 
	return;

  if(level == leftView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	leftView.push_back(root->data);
  }
  printLeftView(root->left, level+1, leftView);
  printLeftView(root->right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView) {
  if(root == NULL) 
	return;

  if(level == rightView.size()) {
	//iska matlab left view ki node milgyi h , store karlo
	rightView.push_back(root->data);
  }
  printRightView(root->right, level+1, rightView);
  printRightView(root->left, level+1, rightView);
}




int main() {
  Node* root = createTree();
	//10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1 
  levelOrderTraversal(root);

  // boundaryTraversal(root);
  //printBottomView(root);

  printTopView(root);

	// vector<int> rightView;
	//   printRightView(root, 0, rightView);

	//   cout << "Printing rightView: " << endl;
	//   for(int i=0; i<rightView.size(); i++) {
	// 	  cout << rightView[i] << " ";
	//   }
  
  // vector<int> leftView;
  // printLeftView(root, 0, leftView);

  // cout << "Printing Left View: " << endl;
  // for(int i=0; i<leftView.size(); i++) {
	 //  cout << leftView[i] << " ";
  // }

	

  return 0;
}
