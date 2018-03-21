#ifndef MINHEAP
#define MINHEAP
#include "Heap.h"
class Minheap: public Heap{
public:
  Minheap();
  ~Minheap();
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