#ifndef HEAP
#define HEAP
//abstract heap class with all methods implemented by both heap types
//allows us to polymorphically choose which heap type to instantiate based on terminal args
class Heap{
public:
  Heap() {};
  ~Heap() {};
  virtual void buildHeap(int* arr, int size) = 0;
  virtual void insert(int x) = 0;
  virtual void deleteMin() = 0;
  virtual int findMin() = 0;
  virtual int findMax() = 0;
  virtual void deleteMax() = 0;
  virtual void levelOrder() = 0;
  virtual int getParent(int i) = 0;
  virtual int* getChildrenIndices(int i) = 0;
  virtual void heapify() = 0;
  int* arr;
  int size;
private:

};

#endif



