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
Tree * naiveMerge(Tree *main, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
//method
int main(){
  Tree *heap=creatHeap(heap,0);
  add(heap,1);
  add(heap,2);
  add(heap,3);
  add(heap,4);
  Tree element1=pop(heap);
  Tree element2=pop(heap);
  Tree element3=pop(heap);
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
Tree *tail=naiveMerge(main, itemT);
swap(tail);
 return 0;
}

int merge(Tree *main, Tree *item){
  Tree *tail =  naiveMerge(main,item);
  swap(tail);
  return 0;
}

int swap(Tree *tail){
  Tree *target;
  target=tail;
while((target->parent) !=empty){
  target=(target ->parent);
  Tree *temp =(target->left);
  (target->left) = (target-> right);
  (target ->right )=temp;
}
  return 0;
}


Tree * naiveMerge(Tree *main, Tree *item){
  Tree *container;
  //choose head
  if((main->value)>(item -> value)){
    Tree temp=*main;
    *main=*item;
    *item=temp;
    *head=*main;
  }else{
    *head=*main;
  }
container = head;
if((container->right)==empty){
      //position found
      //attach
      Tree *parent = container;
      //attach new tree
      (item->parent)=parent;
      (parent->right)=item;
      return parent->right; //return tail
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
      return parent->right; //return tail
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
}

Tree pop(Tree *main){
  Tree *left=(head->left);
  Tree *right =(head->right);
  //detach head
  (left->parent)=empty;
  (right->parent)=empty;
  (head->left)=empty;
  (head->right)=empty;
  Tree target=*head;
  merge(left,right);
  return target;
}
