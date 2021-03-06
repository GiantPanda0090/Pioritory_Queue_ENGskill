#define _POSIX_C_SOURCE 199309L
#define BILLION 1000000000L


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sys/time.h>
#include "print_ascii.h"
#include <stdint.h>
#include <unistd.h>
#include <time.h>



//public
struct Trees *empty =NULL;
struct Trees *head;

int nrEvent;
int dynAvg;
int chance;
int pCount;
int add_counter=0;


int dequeue_t,enqueue_t;
int enqueue_counter=0;
int dequeue_counter=0;


int insert_counter=0;
int pop_counter=0;
int swap_counter=0;
int nav_counter=0;
float n_counter=0;
int debug=0;
float tail_record=0;



//method declearation
Tree * creatHeap(Tree *heap,float value);
Tree * creatNode(float value);
int add(Tree *main, float item);
Tree * naiveMerge(Tree *main1, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
int decompose(Tree element,clock_t timestemp);
int increment(int t);


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
    printf("%d\t%d\t%d\n", nrEvent, (enqueue_t/enqueue_counter),(dequeue_t/dequeue_counter));



//printf("# not crashed");

return 0;
}


int decompose(Tree element,clock_t timestemp){
    int n =absu(rand()+rand()-rand())%(nrEvent-add_counter);//random N
n=absu(n);
  int t =element.value;//random N
float variable=0;


  for(int i=1;i<n;i++){
     variable =t+absu(increment(t));
    add(head,variable);
  }

}

int increment(int t){
    int output=0;


    float avg=tail_record - (head->value);
    int x =(0)+(((head ->value)-t))*((double)rand() / (double)RAND_MAX );

    int randomNr=x;
    return absu(randomNr);
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

    struct timespec  start,end;
    clock_gettime(CLOCK_REALTIME,&start);

    if (item > tail_record){
        tail_record=item;
    }else if(head==NULL){
        tail_record=0;
    }

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

    clock_gettime(CLOCK_REALTIME,&end);
    enqueue_t = enqueue_t+(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    enqueue_counter++;
 return 0;
}

int merge(Tree *main, Tree *item){
  Tree *tail =  naiveMerge(main,item);
  swap(tail);
  return 0;
}

int swap(Tree *tail){

while((tail->parent) !=empty){//probelm infinity loop
n_counter++;
  pCount++;
  tail=(tail ->parent);
  Tree *temp =(tail->left);
  (tail->left) = (tail-> right);
  (tail ->right)=temp;
}

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
    struct timespec start,end;
    clock_gettime(CLOCK_REALTIME,&start);

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
    struct timespec exclude_start,exclude_end;
    uint64_t exclude=0;
  if(leftFlag==1&&rightFlag==1){
      clock_gettime(CLOCK_REALTIME,&exclude_start);
  merge(left,right);
      clock_gettime(CLOCK_REALTIME,&exclude_end);
      exclude = (BILLION * (exclude_end.tv_sec - exclude_start.tv_sec) + exclude_end.tv_nsec - exclude_start.tv_nsec);
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
    clock_gettime(CLOCK_REALTIME,&end);
    dequeue_t=dequeue_t+((BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec));
    dequeue_counter++;

//reset flag
leftFlag =0;
rightFlag=0;

  return target;
}
