#include <iostream>
using namespace std;
class Info{
  public:
    int maxVal;
    bool valid;
};
Info checkMaxHeap(Node* root){
  if(root==NULL){
    Info temp;
    temp.maxVal=INT_MIN;
    temp.valid=true;
    return temp;
  }
  if(root->left==nullptr&& root->right==nullptr){
    Info temp;
    temp.maxVal=root->data;
    temp.valid=true;
    return temp;
  }
  Info leftkaans=checkMaxHeap(root->left);
  Info rightkaans=checkMaxHeap(root->right);
  if(leftkaans.maxVal<root->data&&rightkaans.maxVal<root->data&&leftkaans.valid&&rightkaans.valid){
    Info res;
    res.maxVal=root->data;
    res.valid=true;
    return res;
  }else{
    Info res;
    res.maxVal=max(root->data,max(leftkaans.maxVal,rightkaans.maxVal));
    res.valid=false;
    return res;
  }
}
