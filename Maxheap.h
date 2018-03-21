#ifndef MAXHEAP
#define MAXHEAP
#include "Heap.h"
class Maxheap: public Heap{
public:
  Maxheap();
  ~Maxheap();
  void buildHeap(int* input, int size);
  void insert(int x);
  void deleteMin();
  void deleteMax();
  int findMin();
  int findMax();
  void levelOrder();

  int getParent(int i);
  int* getChildrenIndices(int i);
  void heapify();

};
#endif