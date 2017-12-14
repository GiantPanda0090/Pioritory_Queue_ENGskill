#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int *myArray;
int size =0;
void creatHeap(int size);

int main(){
  creatHeap(10);
  printf("%lu \n", sizeof(*myArray));
  return 0;
}
void creatHeap(int size){
  int array[size];
  myArray= array;
  size =sizeof(array);
}

int getHeap(){
  return *myArray;
}

int getParent(int index,int *heap){
  int parentIndex=(index - 2) / 2;
  return heap[parentIndex];
}

int getChildrenLeft(int index,int *heap){
  int leftIndex = (index * 2) +1;
  return heap[leftIndex];
}

int getChildrenRight(int index, int *heap){
  int rightIndex = (index * 2) + 2;
  return heap[rightIndex];
}

int pop(int *heap){
  if (size==0){
    return -1;
  }
int answer =heap[0];
heap[0]=heap[sizeof(heap-1)];
size=size-1;
//heapifyDown();
return size;
}


//void heapifyDown(){

//}

//void heapifyUp(){

//}
