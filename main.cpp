
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
  std::string heapChoice = argv[1];
  Heap* heap;
  if(heapChoice.compare("max") == 0){
    heap = new Maxheap();
  }
  else if (heapChoice.compare("min")==0){
    heap = new Minheap();
  }
  else{
    std::cout<<"Usage: ./prog [max]/[min]";    
    return 0;
  }
  std::ifstream file;
  file.open("data.txt");
  int curr;
  int i = 0;
  while(file>>curr){
      i++;
  }
  int* arr = new int[i];  
  i = 0;
  file.close();
  file.open("data.txt");
  while(file>>curr){
    arr[i] = curr;
    i++;
  }
  heap->buildHeap(arr, i);
  delete [] arr;
  bool keepRunning = true;
  while(keepRunning){
      std::cout<<"Please choose one of the following commands: \n1- Insert\n2- deleteMin\n3- findMin\n4- findMax\n5- deleteMax\n6- levelOrder\n7- Exit";
      int choice;
      std::cin >> choice;
      switch (choice){
        case 1:{
          std::cout<<"Choose a number to insert: ";
          int x;
          std::cin >> x;
          heap->insert(x);
          heap->levelOrder();
          break;
        }
        case 2:{
          heap->deleteMin();
          heap->levelOrder();
          break;
        }
        case 3:{
          int res = heap->findMin();
          std::cout <<"Min value: " << res << "\n";          
          break;
        }
        case 4:{
          int res = heap->findMax();
          std::cout << "Max value: " <<  res << "\n";
          break;
        }
        case 5:{
          heap->deleteMax();
          heap->levelOrder();
          break;
        }
        case 6:{
          heap->levelOrder();
          std::cout << "\n";
          break;
        }
        case 7:{
          keepRunning = false;
          break;
        }
      }
    }
  delete heap;
	return 0;
}

