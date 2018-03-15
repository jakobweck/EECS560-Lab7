#ifndef HEAP
#define HEAP
class Maxheap{
public:
  virtual void buildHeap(int* arr);
  virtual void insert(int x);
  virtual void deleteMin();
  virtual int findMin();
  virtual int findMax();
  virtual void deleteMax();
  virtual void levelOrder();
private:
  int* arr;
  int size;
}
#endif