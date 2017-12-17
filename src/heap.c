#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>


typedef struct Trees{
  struct Trees *parent;
  struct Trees *left;
  struct Trees *right;
  float value;
  int arch;
}Tree;

//public
struct Trees *empty =NULL;
struct Trees *head;
int maxTask;
int nrEvent;
int archtecture;

//method declearation
Tree * creatHeap(Tree *heap,float value);
Tree * creatNode(float value);
int add(Tree *main, float item);
Tree * naiveMerge(Tree *main, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
int decompose(Tree element,clock_t timestemp);

//method
int main(int argc, char *argv[] ){
  /*
  clock_t t;
  maxTask =5;
  nrEvent =4;
  t=clock();//predefined  function in c
  Tree *heap=creatHeap(heap,0);
  printf("Item %d has been added \n" , 0);

  for (int i =1;i<nrEvent;i++){
    add(heap,i);
      printf("Item %d has been added \n" , i);
  }
  for (int i =0;i<nrEvent;i++){
    Tree element=pop(heap);
    printf("Item %d has been poped \n" , element.value);
   }
t=clock()-t;
float effeciency=((float)t)/CLOCKS_PER_SEC;
  printf ("Program took %f seconds to finish.\n",((float)t)/CLOCKS_PER_SEC);
  printf("not crashed");
  */
  maxTask =atoi(argv[1]) ;
  nrEvent =atoi(argv[2]);
  archtecture=atoi(argv[3]);


int current=0;
int counter=0;
float dataList[3];
while(current<nrEvent){
  clock_t t,timestemp;
  t=clock();//predefined  function in c

  //add
  Tree *heap=creatHeap(heap,t);
  //printf("#Item %f has been added \n" , (float)t);
  for (int i =1;i<current+1;i++){
      timestemp =clock();
    add(heap,timestemp);
      //printf("Item %f has been added \n" ,(float)timestemp);
      //  printf("This is Item Nr %d \n" ,i);

  }
//pop
  while((heap->left)!=empty||(heap -> right)!=empty){

    Tree element=pop(heap);
    //printf("Item %f has been poped \n" , element.value);
    //decompose
    if(element.arch>0){
   decompose(element, timestemp);
}
   }
   Tree element=pop(heap);
  // printf("Item %f has been poped \n" , element.value);


 t=clock()-t;
 float effeciency=((float)t)/CLOCKS_PER_SEC;
 dataList[counter]=effeciency;
   //printf ("Program took %f seconds to finish.\n",((float)t)/CLOCKS_PER_SEC);
  // printf("not crashed");
  counter++;
  if (counter==3){
    current++;
    float sum=dataList[0]+dataList[1]+dataList[2];
    effeciency=sum / 3;
    counter=0;
    printf("%d\t%.8f\n", current, effeciency);
  }
  free(head);
}
return 0;
}
int decompose(Tree element,clock_t timestemp){
  //int t= target.value;
  int n =rand()%maxTask;//random N
  //printf("maxTask been set as %d \n" ,n);
  for(int i=1;i<n;i++){
    timestemp =clock();
    add(head,timestemp);
    //printf("Item %f has been added \n" ,(float)timestemp);
  }
  element.arch=element.arch-1;
}

Tree * creatHeap(Tree *heap,float value){
  Tree *out=creatNode(value);
  head=out;
  return out;
}

Tree * creatNode(float value){
  Tree *out=malloc(sizeof *out);
  out->parent=empty;
  out->left =empty;
  out->right=empty;
  out->value=value;
  out->arch=rand()%archtecture;
  return out;
}

int add(Tree *main, float item){
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
    //exchange item and main
    Tree *temp=main;
     main=item;
     item=temp;
     //head attach
    if((main->left)!=empty){
      main->left->parent=head;

  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
    main=head;
  }else{
    if((main->left)!=empty){
      main->left->parent=head;

  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
    main=head;
  }
container = head;
/*
//first time
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
*/
  while(1){
  //rest
  while((container->value)<=(item -> value)){

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
  Tree *left=(main->left);
  Tree *right =(main->right);
  int leftFlag=0;
  int rightFlag=0;

  //detach head

  //detach left
  if((main->left)!=empty){
  (left->parent)=empty;
  (main->left)=empty;
  leftFlag=1;
}
//detach right
if ((main -> right)!=empty){
  (right->parent)=empty;
  (main->right)=empty;
  rightFlag=1;
}


  Tree target=*main;

  if(leftFlag==1&&rightFlag==1){
  merge(left,right);
}else if (leftFlag==1&&rightFlag==0){
  //attach head to the next Item
  *head=*left;
    left=head;
}else if (leftFlag==0&&rightFlag==1){
  *head=*right;
    right=head;
}
//reset flag
leftFlag =0;
rightFlag=0;
/*
  //decompose
  int t= target.value;
  //new tree
  int n =rand()%maxTask;//implement maxTask
  for(int i=1;i<n;i++){
    float timestemp =clock();
    add(head,timestemp);
  }
*/
  return target;
}
