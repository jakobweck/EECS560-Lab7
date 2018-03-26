#include "Minheap.h"
#include <math.h>
#include <iostream>
//allocate array of size 500 to store complete BT
Minheap::Minheap(){
    this->arr = new int[500];
    for(int i =0;i<500;i++){
      arr[i] = -1;
    }
    this->size = 0;
}
//free minheap storage
Minheap::~Minheap(){
    delete [] this->arr;    
}
//insert elements of input into array to form a complete BT, then modify it to obey heap property
void Minheap::buildHeap(int* input, int size){
    this->size = size;
    for(int i=0;i<size;i++){
      this->arr[i] = input[i];
    }
    levelOrder();
    heapify();
}
//insert an item into the min heap, maintaining heap property.
void Minheap::insert(int x){
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
//delete the minimum element by replacing the root with the last element and heapifying
void Minheap::deleteMin(){
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
//find the maximum element among the maxheap's leaves and delete it, maintaining heap property
void Minheap::deleteMax(){
    int firstLeaf = floor(1+(this->size-1)/5);
    int currMax = arr[firstLeaf];
    int currMaxIndex = firstLeaf;
    int lastIndex = 0;
    for(int i = this->size;i>=0;i--){
      if(arr[i] != -1){
        lastIndex = i;
        break;
      }
    }
    for(int i = firstLeaf;i<this->size;i++){
      if (arr[i] != -1 && arr[i]>currMax){
        currMaxIndex = i;
        currMax = arr[i];
      }
    }
    arr[currMaxIndex] = arr[lastIndex];
    arr[lastIndex]  = -1;
    this->size--;
    heapify();
}
//return the root
int Minheap::findMin(){
    return arr[0];
    
}
//search the leaves for the maximum element
int Minheap::findMax(){
    int firstLeaf = floor(1+(this->size-1)/5); //should these sizes be number of elements or array size?
    int currMax = arr[firstLeaf];
    for(int i = firstLeaf;i<this->size;i++){
      if (arr[i]>currMax){
        currMax = arr[i];
      }
    }
    return currMax;
}
//print the heap's elements by level
void Minheap::levelOrder(){
    if(arr[0] == -1) return;
    std::cout << "1: " << arr[0] << "\n";
    std::cout << "2: ";
    for(int i =1;i<6;i++){
        if(arr[i] == -1) return;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
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
int Minheap::getParent(int i){
    return floor((i-1)/5);
}

//get an array of the 0-5 children of an individual node
int* Minheap::getChildrenIndices(int i){
    int* children = new int[5];
    for(int j=1;j<=5;j++){
      children[j-1] = 5*i+j;
    }
    return children;
}
//starting at the last parent node, swap all parents with their smallest child if it is smaller than the parent.

void Minheap::heapify(){
        int lastParentIndex = floor((this->size-1)/5);    
        for(int i = lastParentIndex;i>=0;i--){
            int parent = arr[i];
            int* children = getChildrenIndices(i);
            int minChild = parent;
            int minChildIndex = -1;
            bool swap = false;
            for(int j=0;j<5;j++){
                if (arr[children[j]] != -1 && arr[children[j]]<minChild){
                    swap = true;
                    minChild = arr[children[j]];
                    minChildIndex = children[j];
                }
            }
            if(swap){
                arr[minChildIndex] = parent;
                arr[i] = minChild;
                heapify();
            }
        }
}