#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//https://stackoverflow.com/questions/1921539/using-boolean-values-in-c
typedef struct Trees{
  struct Trees *parent;
  struct Trees *left;
  struct Trees *right;
  int value;
}Tree;

//public
struct Trees *empty =NULL;
struct Trees *head;

//method declearation
Tree * creatHeap(Tree *heap,int value);
Tree * creatNode(int value);
int add(Tree *main, int item);
int naiveMerge(Tree *main, Tree *item);

//method
int main(){
  Tree *heap=creatHeap(heap,1);
  add(heap,0);
  add(heap,9);
  add(heap,4);
  add(heap,5);
  printf("not crashed");
}

Tree * creatHeap(Tree *heap,int value){
  Tree *out=malloc(sizeof *out);
  out->parent=empty;
  out->left =empty;
  out->right=empty;
  out->value=value;
  head=out;
  return out;
}

Tree * creatNode(int value){
  Tree *out=malloc(sizeof *out);
  out->parent=empty;
  out->left =empty;
  out->right=empty;
  out->value=value;
  return out;
}

int add(Tree *main, int item){
Tree *itemT=creatNode(item);
 naiveMerge(main, itemT);
 return 0;
}


int naiveMerge(Tree *main, Tree *item){
  Tree *container;
  //choose head
  if((main->value)>(item -> value)){
    Tree temp=*head;
    *head=*item;
    *item=temp;
  }
container = head;
if((container->right)==empty){
      //position found
      //attach
      Tree *parent = container;
      //attach new tree
      (item->parent)=parent;
      (parent->right)=item;
      return 0;
    }else{
  container=main->right;
}

  while(1){
  //rest
  while((container->value)<(item -> value)){
    //check last item
    if((container->right)==empty){
      //position found
      //attach
      Tree *parent = container;
      //attach new tree
      (item->parent)=parent;
      (parent->right)=item;
      return 0;
    }else{
    container=(container->right);
  }
  }
  //position found
  //attach
  Tree *parent = (container->parent);
  //detch both child and parent
  (container->parent)=empty;
  (parent->right) = empty;
  //attach new tree
  (item->parent)=parent;
  (parent->right)=item;
  //prepare for next round
  item=container;
  container=(parent->right);
}

return 0;

}
