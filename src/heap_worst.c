#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include "print_ascii.h"



//public
struct Trees *empty =NULL;
struct Trees *head;

int nrEvent;
int dynAvg;
int chance;
int pCount;
int add_counter=0;
clock_t save;
float n_counter=0;
int debug=0;


//method declearation
Tree * creatHeap(Tree *heap,float value);
Tree * creatNode(float value);
int add(Tree *main, float item);
Tree * naiveMerge(Tree *main1, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
int decompose(Tree element,clock_t timestemp);
int increment();
int findright();


//absolute value
//https://stackoverflow.com/questions/22268815/absolute-value-of-int-min
unsigned int absu(int value) {
    return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}

//method
int main(int argc, char *argv[] ){
if(argc != 4) {
    printf("usage: list  <nrEvent> <debug switch>\n");
    exit(0);
  }

  nrEvent =atoi(argv[1]);
debug=atoi(argv[2]);
int seed=atoi(argv[3]);
  int counter=0;
  dynAvg=0;
  chance=0;
  pCount=0;
clock_t rand_t;
   srand(seed);
  int current =absu(rand()+rand()-rand())%(nrEvent-add_counter);//random N
current =absu(current);
 while(current==0){
      current =(rand()+rand()-rand())%(nrEvent-add_counter);
    }

//DEBUG
//printf("current generate as %d \n",current);

float dataList[3];
  clock_t t,timestemp;


  //add
      timestemp =clock();
  Tree *heap=creatHeap(heap,timestemp);
  for (int i =1;i<current;i++){
      timestemp =clock();
    add(heap,timestemp);
  }
if (current !=0){
save=save/current;
}

  //debug 
if (debug==1){
print_ascii_tree(heap);
}
  /*
  printf("\n#After head: \n");
  printf("#head is %f\n",head->value);
  debug(head);
  */
//pop
  while((heap->left)!=empty&&(heap -> right)!=empty){
    Tree element=pop(heap);
    /*
    printf("\n#After pop: \n");
    printf("head is %f\n",head->value);
debug(head);
*/

if (debug==1){
printf("#After pop %f \n\n", element.value);
print_ascii_tree(heap);
printf("\n");
}


    //decompose
    if(add_counter<nrEvent){
   decompose(element, timestemp);

if (debug==1){
printf("#After decompose \n\n");
print_ascii_tree(heap);
printf("\n");
}

   /*
   printf("\n#After decompose: \n");
   printf("head is %f\n",head->value);
   debug(head);
   */
}
   
   }





   Tree element=pop(heap);
   /*
   printf("\n#After last pop: \n");
   printf("head is %f\n",head->value);
   debug(head);
   */



    double effeciency=(save)/(double)CLOCKS_PER_SEC*1000;
     printf("%d\t%.8lf\n", nrEvent, effeciency);


//printf("# not crashed");

return 0;
}


int decompose(Tree element,clock_t timestemp){
    int n =absu(rand()+rand()-rand())%(nrEvent-add_counter);//random N
n=absu(n);
  int t =element.value;//random N
float variable=0;
  for(int i=1;i<n;i++){
     variable =findright()+absu(increment());
    add(head,variable);
  }
if (n !=0){
save=save/n;
}
}
int findright(){
Tree* search = head;
while (search -> right != NULL){
search = search ->right;
}
printf("right element %f\n",(search -> value));
return search -> value;
}
int increment(){
  int randomNr=rand()%(int)(500);
  return randomNr;
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
  out->self=&*out;
  return out;
}
int add(Tree *main, float item){

  int replacement=0;
if(item > head->value){
  replacement=item-head->value;
}else{
  replacement=head->value-item;
}
if(replacement>dynAvg){
  dynAvg=replacement;
}

Tree *itemT=creatNode(item);
merge(main, itemT);
add_counter++;
 return 0;
}

int merge(Tree *main, Tree *item){
  Tree *tail =  naiveMerge(main,item);
  swap(tail);
  return 0;
}

int swap(Tree *tail){
clock_t start,end;
start=clock();
while((tail->parent) !=empty){//probelm infinity loop
n_counter++;
  pCount++;
  tail=(tail ->parent);
  Tree *temp =(tail->left);
  (tail->left) = (tail-> right);
  (tail ->right)=temp;
}
end =clock();
save=save+(end-start);
//printf("# %d\n",pCount);
pCount=0;
  return 0;
}

Tree * naiveMerge(Tree *main1, Tree *item){
  Tree *container;
  Tree *main=malloc(sizeof *main);
  *main=*main1;
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
  free(main);
  }else{
    if((main->left)!=empty){
      main->left->parent=head;

  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
  free(main);
  }
container = head;
  while(1){
  //rest
//search
clock_t start,end;
start=clock();
  while((container->value)<=(item -> value)){
n_counter++;
pCount++;
    //check last item
    if((container->right)==empty){//reason of infinity loop
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
end =clock();
save=save+(end-start);
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
clock_t start,end;
start = clock();

  Tree *left=(head->left);
  Tree *right =(head->right);
  int leftFlag=0;
  int rightFlag=0;
pCount++;
  //detach head

  //detach left
  if((head->left)!=empty){
  (left->parent)=empty;
  (head->left)=empty;
  leftFlag=1;
}
//detach right
if ((head -> right)!=empty){
  (right->parent)=empty;
  (head->right)=empty;
  rightFlag=1;
}


  Tree target=*head;

  if(leftFlag==1&&rightFlag==1){
  merge(left,right);
  if(head->value==left->value){
    //free(left);
  }else if(head->value ==right->value){
    //free(right);
  }
}else if (leftFlag==1&&rightFlag==0){
  //attach head to the next Item
  *head=*left;
  free(left);
}else if (leftFlag==0&&rightFlag==1){
  *head=*right;
  free(right);
}
end =clock();
save=save+(end-start);
//reset flag
leftFlag =0;
rightFlag=0;

  return target;
}