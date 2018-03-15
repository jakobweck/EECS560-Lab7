
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Maxheap.h"
#include "Minheap.h"

int main(int argc, char** argv)
{
  if(argc<2){
    std::cout<<"Usage: ./prog [max]/[min]";
    return 0;
  }
  char* heapChoice = argv[1];
  Heap* heap;
  if(heapChoice.compare("max") == 0){
    heap = new Maxheap();
  }
  else if (heapChoice.compare("min")==0){
    heap = new Minheap();
  }
  else{
    return 0;
  }

  file.open("data.txt");
  int curr;

  while(file>>curr){
      std::cout<<"Inserting " << curr << "\n";
      heap->insert(curr);

  }
  bool keepRunning = true;
  while(keepRunning){
      std::cout<<"Please choose one of the following commands: \n1- Insert\n2- deleteMin\n3- findMin\n4- findMax\n5- deleteMax\n6-levelOrder\n7- Exit";
      int choice;
      std::cin >> choice;
      switch (choice){
        case 1:{
          int x;
          std::cin >> x;
          heap->insert(x);
          break;
        }
        case 2:{
          heap->deleteMin();
          break;
        }
        case 3:{
          int res = heap->findMin();
          break;
        }
        case 4:{
          int res = heap->findMax();
          break;
        }
        case 5:{
          heap->deleteMax();
          break;
        }
        case 6:{
          heap->levelOrder();
          break;
        }
        case 7:{
          keepRunning = false;
          break;
        }
      }
    }

	return (0);
}

