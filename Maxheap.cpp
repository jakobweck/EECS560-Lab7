
#include "Maxheap.h"
#include <math.h>
#include <iostream>
//allocate array of size 500 to store complete BT
Maxheap::Maxheap(){
  this->arr = new int[500];
  for(int i =0;i<500;i++){
    arr[i] = -1;
  }
  this->size = 0;
}
//free maxheap storage
Maxheap::~Maxheap(){
  delete [] this->arr;
}
//insert elements of input into array to form a complete BT, then modify it to obey heap property
void Maxheap::buildHeap(int* input, int size){
  this->size = size;
  for(int i=0;i<size;i++){
    this->arr[i] = input[i];
  }
  heapify();
}
//insert an item into the max heap, maintaining heap property.
void Maxheap::insert(int x){
  if(arr[0]==-1){
    arr[0] = x;
    return;
  }
  for(int i=499;i>=1;i--){
    if(arr[i-1]!=-1 && arr[i]==-1){
      arr[i] = x;
      break;
    }
  }
  this->size++;
  heapify();
}
//find the minimum element among the maxheap's leaves and delete it, maintaining heap property
void Maxheap::deleteMin(){
  int firstLeaf = floor(1+(this->size-1)/5);
  int currMin = arr[firstLeaf];
  int currMinIndex = firstLeaf;
  int lastIndex = 0;
  //find the last element - final leaf
  for(int i = this->size;i>=0;i--){
    if(arr[i] != -1){
      lastIndex = i;
      break;
    }
  }
  //find the minimum leaf
  for(int i = firstLeaf;i<this->size;i++){
    if (arr[i] != -1 && arr[i]<currMin){
      currMinIndex = i;
      currMin = arr[i];
    }
  }
  //move the last element into the position to be deleted
  arr[currMinIndex] = arr[lastIndex];
  //delete the last element and heapify
  arr[lastIndex]  = -1;
  this->size--;
  heapify();
}
//delete the maximum element by replacing the root with the last element and heapifying
void Maxheap::deleteMax(){
  int last = 0;
  int lastIndex = 0;
  if(this->size ==0) return;
  for(int i = this->size;i>=0;i--){
    if(arr[i] != -1){
      last = arr[i];
      lastIndex = i;
      break;
    }
  }
  arr[0] = last;
  arr[lastIndex] = -1;
  this->size--;
  heapify();
}
//search the leaves for the minimum element
int Maxheap::findMin(){
  int firstLeaf = floor(1+(this->size-1)/5); //should these sizes be number of elements or array size?
  int currMin = arr[firstLeaf];
  for(int i = firstLeaf;i<this->size;i++){
    if (arr[i]<currMin){
      currMin = arr[i];
    }
  }
  return currMin;

}
//return the root
int Maxheap::findMax(){
  return arr[0];
}
//print the heap's elements by level
void Maxheap::levelOrder(){
  if(arr[0] == -1) return;
  std::cout << "1: " << arr[0] << "\n";
  std::cout << "2: ";
  for(int i =1;i<6;i++){
      if(arr[i] == -1) return;
      std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  //for row n after row 2, the first element is at row position 5^(n-2)+1
  for(int i = 1; pow(5, i)<500;i++){
      if(arr[i] == -1) return;
      std::cout << i+2 << ": ";
      for(int j = pow(5, i)+1; j<pow(5, i+1);j++){
          if(arr[j] == -1) return;
          std::cout << arr[j] << " ";
      }
      std::cout << "\n";
  }
  std::cout << "\n";

}
//get the parent index of an individual node
int Maxheap::getParent(int i){
  return floor((i-1)/5);
}
//get an array of the 0-5 children of an individual node
int* Maxheap::getChildrenIndices(int i){
  int* children = new int[5];
  for(int j=1;j<=5;j++){
    children[j-1] = 5*i+j;
  }
  return children;
}
//starting at the last parent node, swap all parents with their largest child if it is larger than the parent.
void Maxheap::heapify(){
    int lastParentIndex = floor((this->size-1)/5);
    for(int i = lastParentIndex;i>=0;i--){
      int parent = arr[i];
      int* children = getChildrenIndices(i);
      int maxChild = parent;
      int maxChildIndex = -1;
      bool swap = false;
      for(int j=0;j<5;j++){
        
        if (arr[children[j]] != -1 && arr[children[j]]>maxChild){
          swap = true;
          maxChild = arr[children[j]];
          maxChildIndex = children[j];
        }
      }
      if(swap){
        arr[maxChildIndex] = parent;
        arr[i] = maxChild;
        heapify();
      }
    }
}
