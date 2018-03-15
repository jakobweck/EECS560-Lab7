Maxheap::Maxheap(){
  this->arr = new int[500];
  for(int i =0;i<500;i++){
    arr[i] = -1;
  }
  this->size = 0;
}
Maxheap::~Maxheap(){
  delete [] this->arr;
}
void Maxheap::buildHeap(int* input){
  this->size = input.size();
  for(int i=0;i<input.size();i++){
    this->arr[i] = input[i];
  }
  //find last parent
  heapify();
}

void Maxheap::insert(int x){
  if(arr[0]==-1){
    arr[0] = x;
    return;
  }
  for(int i=499;i>=0;i++){
    if(arr[i-1]!=-1 && arr[i]==-1){
      arr[i] = x;
    }
  }
  this->size++;
  heapify();
}

void Maxheap::deleteMin(){
  int firstLeaf = floor(1+(input.size()-1)/5);
  int currMin = arr[firstLeaf];
  int currMinIndex = firstLeaf;
  for(int i = firstLeaf;i<arr.size();i++){
    if (arr[i]<currMin){
      currMinIndex = i;
      currMin = arr[i];
    }
  }
  arr[currMinIndex] = -1;
  this->size--;
}

void Maxheap::deleteMax(){
  int last;
  int lastIndex;
  for(int i = arr.size();i>=0;i--){
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

int Maxheap::findMin(){
  int firstLeaf = floor(1+(input.size()-1)/5);
  int currMin = arr[firstLeaf];
  for(int i = firstLeaf;i<arr.size();i++){
    if (arr[i]<currMin){
      currMin = arr[i];
    }
  }
  return currMin;

}

int Maxheap::findMax(){
  return arr[0];
}

void Maxheap::levelOrder(){

}

void Maxheap::getParent(int i){
  return floor((i-1)/5);
}

int* Maxheap::getChildrenIndices(int i){
  int* children = new int[5];
  for(int j=1;j<=5;j++){
    if(this->arr[5*i+j]!=-1){
      children[j-1] = this->arr[5*i+j];
    }
  }
  return children;
}

void Maxheap::heapify(){
  int lastParentIndex = floor((this->size-1)/5);
  for(int i = lastParentIndex;i>=0;i--){
    int parent = arr[i];
    int* children = getChildrenIndices(i);
    int maxChild = parent;
    int maxChildIndex = -1;
    bool swap = false;
    //find max child if larger than parent
    for(int j=0;i<children.size();j++){
      if (arr[children[j]] != -1 && arr[children[j]]>maxChild){
        swap = true;
        maxChild = arr[children[j]];
        maxChildIndex = children[j];
      }
    }
    if(swap){
      arr[maxChildIndex] = parent;
      arr[i] = maxChild;
    }
  }
}
