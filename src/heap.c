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
int limit;
int add_counter=0;
double dequeue_t,enqueue_t=0.0;
double insert_t,pop_t,init_t=0.0;
double rest_t=0.0;

int enqueue_counter=0;
int dequeue_counter=0;

float n_counter=0;
int debug=0;
double tail_record=0;


//method declearation
Tree * creatHeap(Tree *heap,double value);
Tree * creatNode(double value);
int add(Tree *main, double item);
Tree * naiveMerge(Tree *main1, Tree *item);
int swap(Tree *tail);
Tree pop(Tree *main);
int merge(Tree *main, Tree *item);
int decompose(Tree element,double timestemp);
double increment(double t);


//absolute value
double absu(double value) {
    double out =0;
    if (value<0){
        out=value*(-1);
    }else{
        out =value;
    }
    return out;
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
   srand(seed);
  int current =1+((absu(rand())/(double) RAND_MAX)*(nrEvent));//random N



//DEBUG
//printf("current generate as %d \n",current);

float dataList[3];


  //add
    double timestemp;

  Tree *heap=creatHeap(heap,timestemp);

    double previous_timestemp=0.0;
    struct timespec time;
    limit=nrEvent+current;



    init_t=0.0;
  for (int i =0;i<current;i++){
      clock_gettime(CLOCK_MONOTONIC,&time);
      timestemp=(double)(BILLION * (time.tv_sec)+ time.tv_nsec);
      timestemp =timestemp+((timestemp-previous_timestemp)*(rand()/(double) RAND_MAX));

    add(heap,timestemp);
    init_t=init_t+(insert_t);
      previous_timestemp=timestemp;
  }
    enqueue_t=enqueue_t+(init_t/current);


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
    if(add_counter<limit){
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
    enqueue_t=(rest_t/enqueue_counter);






    Tree element=pop(heap);
   /*
   printf("\n#After last pop: \n");
   printf("head is %f\n",head->value);
   debug(head);
   */



     printf("%d\t%lf\t%lf\n", nrEvent, (enqueue_t),(dequeue_t/dequeue_counter));


//printf("# not crashed");

return 0;
}


int decompose(Tree element,double timestemp){
    int n =1+ ((limit-add_counter-1) * (absu(rand()) / (double)RAND_MAX));
  double t =element.value;//random N
double variable=0;
    double decom_t=0;

  for(int i=0;i<n;i++){
     variable =t+increment(t);
    add(head,variable);
      decom_t=decom_t+(insert_t);
  }
//printf("%d\t%d\t%d\t",nrEvent,n,add_counter);
        decom_t=decom_t/n;
        rest_t=rest_t+decom_t;
        enqueue_counter++;


}

double increment(double t){
    int output=0;
    double x=0.0;
    double prob= (absu(rand()) / (double)RAND_MAX);

    double avg=tail_record - (head->value);
    x =((head->value) - t)+((avg)*prob);

    double randomNr=x;
  return absu(randomNr);
}

Tree * creatHeap(Tree *heap,double value){
  Tree *out=creatNode(value);
  head=out;
  return out;
}

Tree * creatNode(double value){
  Tree *out=malloc(sizeof *out);
  out->parent=empty;
  out->left =empty;
  out->right=empty;
  out->value=value;
  out->self=&*out;
  return out;
}
int add(Tree *main, double item){
    struct timespec  start,end;
    clock_gettime(CLOCK_MONOTONIC,&start);
    insert_t=0.0;

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
    clock_gettime(CLOCK_MONOTONIC,&end);
    insert_t = (double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
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
    pop_t=0;
    struct timespec start,end;
 clock_gettime(CLOCK_MONOTONIC,&start);

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
        clock_gettime(CLOCK_MONOTONIC,&exclude_start);
        merge(left,right);
        clock_gettime(CLOCK_MONOTONIC,&exclude_end);
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

clock_gettime(CLOCK_MONOTONIC,&end);
    pop_t=((double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec));

    dequeue_t=dequeue_t+pop_t;
    dequeue_counter++;
//reset flag
leftFlag =0;
rightFlag=0;
  return target;
}
