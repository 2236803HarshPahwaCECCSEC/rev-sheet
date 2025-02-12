#include <iostream>
using namespace std;
class Heap{
  public:
  int *arr;
  int size;
  int capacity;//total size it can hold dynamically;
  Heap(int capacity){
    this->arr=new int[capacity];
    this->size=0;
    this->capacity=capacity;
  }
  void insert(int val){
    if(size==capacity){
      cout<<"heap overflow"<<endl;
      return;
    }
    size++;
    int index=size;
    arr[index]=val;
    while(index>1){
      int parentindex=index/2;
      if(arr[index]>arr[parentindex]){
        swap(arr[index],arr[parentindex]);
      }else break;
    }
  }
  int deletefromheap(){
      int ans=arr[1];
      arr[1]=arr[size];
      size--;
      int index=1;
      while(index<size){
        int largestindex=index;
        int leftindex=2*index;
        int rightindex=(2*index)+1;
        if(leftindex<=size&&arr[largestindex]<arr[leftindex]){
            largestindex=leftindex;
        }if(rightindex<=size&&arr[largestindex]<arr[rightindex]){
            largestindex=rightindex;
        }
        if(largestindex==index){break;}
        else{
            swap(arr[index],arr[largestindex]);
            index=largestindex;
        }
      }
      return ans;
  }
  void printHeap(){
    for(int i=1;i<=size;i++){
      cout<<arr[i]<<" ";
    }
  }
};

//heapify a heap using recursion
void heapify(int *arr,int size,int index){
    int leftindex=2*index;
    int rightindex=(2*index)+1;
    int largestindex=index;
    if(leftindex<=size&&arr[leftindex]>arr[largestindex]){
        largestindex=leftindex;
    }
    if(rightindex<=size&&arr[rightindex]>arr[largestindex]){
        largestindex=rightindex;
    }
    if(largestindex!=index){
        swap(arr[index],arr[largestindex]);
        index=largestindex;
        heapify(arr,size,index);
    }
}
void buildheap(int arr[],int n){
  for(int index=n/2;index>0;index--){
      heapify(arr,n,index);
  }}
void heapsort(int arr[],int n){
  while(n!=0){
    swap(arr[1],arr[n]);
    n--;
    heapify(arr,n,1);
  }
}
int main() {
  // cout << "Creation of heap" << endl;
  // Heap h(6);
  // h.insert(10);
  // h.insert(20);
  // h.insert(5);
  // h.insert(11);
  // h.insert(6);
  // h.printHeap();
  // cout<<endl;
  // cout<<h.deletefromheap();
  // cout<<endl;
  // h.printHeap();
  int arr[]={-1,5,10,15,20,25,12};
  int n=6;
  buildheap(arr,n);
  cout<<"printing heap"<<endl;
  for(int i=1;i<=6;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  heapsort(arr,n);
  cout<<"printing array ele"<<endl;
  for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}
