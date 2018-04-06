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
  struct Trees *self;
}Tree;

//public
struct Trees *empty =NULL;
struct Trees *head;

int nrEvent;
int dynAvg;
int chance;
int pCount;
int add_counter=0;
clock_t save;



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

int debug(Tree *head) {
    if(head == NULL){
//        printf(" \t ");
printf("# dynavg value %d\n",dynAvg);
      return 0;
    }
    //printf(" \t ");
    debug(head -> left);
    //printf(" \t ");
    printf("# |____");
    printf(" %f\n",head -> value);
    //printf(" \t ");

    debug(head ->right);

}

//method
int main(int argc, char *argv[] ){
if(argc != 2) {
    printf("usage: list  <nrEvent> \n");
    exit(0);
  }

  nrEvent =atoi(argv[1]);

  int counter=0;
  dynAvg=0;
  chance=0;
  pCount=0;
clock_t rand_t;
   srand((unsigned) time(&rand_t));
  int current =(rand()+rand()-rand())%(nrEvent-add_counter);//random N
float dataList[3];
  clock_t t,timestemp;


  //add
  Tree *heap=creatHeap(heap,t);
  for (int i =1;i<current+1;i++){
      timestemp =clock();
    add(heap,timestemp);
  }
  /*
  printf("\n#After head: \n");
  printf("#head is %f\n",head->value);
  debug(head);
  */
//pop
  while((heap->left)!=empty||(heap -> right)!=empty){
    Tree element=pop(heap);
    /*
    printf("\n#After pop: \n");
    printf("head is %f\n",head->value);
debug(head);
*/


    //decompose
    if(add_counter<nrEvent){
   decompose(element, timestemp);
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
     printf("%d\t%.8lf\n", add_counter, effeciency);


//printf("# not crashed");

return 0;
}


int decompose(Tree element,clock_t timestemp){
    int n =(rand()+rand()-rand())%(nrEvent-add_counter);//random N//random N
  int t =element.value;//random N
float variable=0;
  for(int i=1;i<n;i++){
     variable =t+increment();
    add(head,variable);
  }
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
clock_t start,end;
start=clock();
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
end=clock();
save=save+(end-start);
add_counter++;
 return 0;
}

int merge(Tree *main, Tree *item){
  Tree *tail =  naiveMerge(main,item);
  swap(tail);
  return 0;
}

int swap(Tree *tail){
while((tail->parent) !=empty){//probelm infinity loop
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
  //free(main1);
  }else{
    if((main->left)!=empty){
      main->left->parent=head;

  }
  if ((main -> right)!=empty){
    main->right->parent=head;

  }
  *head=*main;
  //free(main1);
  }
container = head;
  while(1){
  //rest
  while((container->value)<=(item -> value)){
pCount++;
    //check last item
    if((container->right)==empty){//reason of infinity loop
      //position found
      //attach
      Tree *parent = container;
      //attach new tree
      (item->parent)=parent;
      (parent->right)=item;
      free(main);
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
clock_t start,end;
start=clock();
  Tree *left=(main->left);
  Tree *right =(main->right);
  int leftFlag=0;
  int rightFlag=0;
pCount++;
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
  if(head->value==left->value){
    free(left);
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
//reset flag
leftFlag =0;
rightFlag=0;
end =clock();
save=save+(end-start);
  return target;
}
