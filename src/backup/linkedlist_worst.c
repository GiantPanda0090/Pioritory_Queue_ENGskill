#define _POSIX_C_SOURCE 199309L
#define BILLION 1000000000L


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <sys/time.h>
#include <unistd.h>


//https://stackoverflow.com/questions/21788598/c-inserting-into-linked-list-in-ascending-order
typedef struct node{
    double data;
    struct node *ptr;
    struct node *ptr_p;
    struct node *tail;
} node;


int pCount;
int debug=0;
double insert_t,pop_t,search_t=0;
double enqueue_t,dequeue_t=0;
int insert_counter=0;
int enqueue_counter=0;
int dequeue_counter=0;
double rest_t=0;

int counter=0;
int n_max=0;
float n_counter=0;


node* insert(node* head, double num) {
counter++;
    insert_t=0;
    search_t=0;
    struct timespec start,end,start_search,end_search;

    node *temp ,*tail;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;

    //first
    if(!head){
        //add
        clock_gettime(CLOCK_MONOTONIC,&start);

        head=temp;
        head->tail=temp;

        clock_gettime(CLOCK_MONOTONIC,&end);
        insert_t=(double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
        insert_counter++;
    } else{
if(temp->data<=head->data){//insert head

    //add
    clock_gettime(CLOCK_MONOTONIC,&start);

    head->ptr_p=temp;
temp->ptr=head;
temp->ptr_p=NULL;
temp->tail=head->tail;
head->tail=NULL;
head=temp;//update head

    clock_gettime(CLOCK_MONOTONIC,&end);
    insert_t=(double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    insert_counter++;
}else if(temp->data>=head->tail->data){//insert tail

    //add
    clock_gettime(CLOCK_MONOTONIC,&start);

    temp->ptr_p=head->tail;
head->tail->ptr=temp;
temp->ptr=NULL;
head->tail=temp;//update tail

    clock_gettime(CLOCK_MONOTONIC,&end);
    insert_t=(double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    insert_counter++;

}else{

int avg =head->data+head->tail->data;
      avg=avg/2;//average

if (num>avg){
node *container=head->tail;

//search
    clock_gettime(CLOCK_MONOTONIC,&start_search);

while(temp->data<container->data){
n_counter++;
container=container->ptr_p;
}

    clock_gettime(CLOCK_MONOTONIC,&end_search);
    search_t=(double)(BILLION * (end_search.tv_sec - start_search.tv_sec) + end_search.tv_nsec - start_search.tv_nsec);


    //add
    clock_gettime(CLOCK_MONOTONIC,&start);

//link temp
temp->ptr_p=container;
temp->ptr=container->ptr;
//update container
container->ptr->ptr_p=temp;
container->ptr=temp;

    clock_gettime(CLOCK_MONOTONIC,&end);
    insert_t=(double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    insert_counter++;


}else{
node *container=head;

//search
    clock_gettime(CLOCK_MONOTONIC,&start_search);

while(temp->data>container->data){
n_counter++;
container=container->ptr;
}

    clock_gettime(CLOCK_MONOTONIC,&end_search);
    search_t=(double)(BILLION * (end_search.tv_sec - start_search.tv_sec) + end_search.tv_nsec - start_search.tv_nsec);



    //add
    clock_gettime(CLOCK_MONOTONIC,&start);

//link temp
temp->ptr=container;
temp->ptr_p=container->ptr_p;
//update container
container->ptr_p->ptr=temp;
container->ptr_p=temp;

    clock_gettime(CLOCK_MONOTONIC,&end);
    insert_t=(double)(BILLION * (start.tv_sec - end.tv_sec) + start.tv_nsec - end.tv_nsec);
    insert_counter++;


}

}
    }

    return head;
}

node *trace=NULL;
//pop
node pop(node* head){
    struct timespec start,end;
    pop_t=0;

    clock_gettime(CLOCK_MONOTONIC,&start);

if(debug==1){

if (head->ptr_p!=NULL){
      printf("#Head is%f:\n",head->data);
}
}


trace=head->ptr;
if(trace!=NULL){
head->ptr->tail=head->tail;
}



if(debug==1){
if(head->tail==NULL){
 printf("\n\n#Error Report!\n");
      printf("trace->tail is empty\n");
      printf("#trace is%f:\n",trace->data);
 printf("Because of: \n");

 printf("Head->tail is empty\n");
      printf("#Head is%f:\n",head->data);
      printf("#Head->tail is%f:\n",head->tail->data);


//exit(-1);
}
    }


node out = *head;


free(head);
    clock_gettime(CLOCK_MONOTONIC,&end);
    pop_t=(double)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);

    dequeue_t=dequeue_t+pop_t;
    dequeue_counter++;
pCount++;
  return out;
}


//free the malloced memory to avoid memory leakage
void free_list(node *head) {
    node *prev = head;
    node *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->ptr;
        free(prev);
    }
}



int n=9;



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

//increment generator
double increment(node* head,double t){

    double avg =0.0;
    double diff=0.0;
    double prob=(rand() / (double)RAND_MAX);
if(head==NULL){
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC,&time);
    double time_diff=(double)(BILLION * (time.tv_sec)+ time.tv_nsec);
    double timestemp=time_diff;


    timestemp =timestemp+((timestemp-t)*(rand()/(double) RAND_MAX));
avg=((double)timestemp)*prob;
}else{
if(head->tail->data-head->data!=0.0){
node *p2=head;
node *p1=head;
while(p2 != NULL && p2 ->ptr != NULL){
    p2=p2->ptr->ptr;
    p1=p1->ptr;

}
double middle_range=(p1->ptr->data)-(p1->ptr_p->data);

    double min = (p1 ->ptr_p->data) - t;
    double max = (p1 ->ptr->data) - t;
    avg=min + (middle_range*prob);


}else{
  avg =(head->data)*prob;//dynamic range
}
}
    double out =absu(avg);

    return out ;
}

//decompose
node* decompose(node* head,node element){
  int n =1+rand()%(n_max-counter);//random N
  n=absu(n);
  double t =element.data;// obtain value from main node
double variable=0;
//printf("#value of n is %d\n", n);
    int decom_t=0;

    for(int i=1;i<n;i++){
     variable =t+increment(head,t);
      head = insert(head, variable);
        decom_t=decom_t+(insert_t+search_t);

    }

    if(n!=0){
        decom_t=decom_t/n;
        rest_t=rest_t+decom_t;
        enqueue_counter++;

    }

  return head;
}

//test 
int test(){
float insert_list[]={0,1,1.1,1.2,5,4,6,5.4,3.5};
float answer_list[]={0,1,1.1,1.2,3.5,4,5,5.4,6};
 node *head, *p;
    head = NULL;
      printf("#size of insert_list is %d ", (int)sizeof(insert_list));
for(int i=0;i<9;i++) {        
       head = insert(head, insert_list[i]);
      printf("#inserting %f \n", insert_list[i]);
    }
    p = head;

int i_check=0;
 while(head->ptr!=NULL){
      node poped_node=pop(head);

      printf("#poping %f \n", poped_node.data);
      head=trace;
float var =0;
 if(counter<n_max){
     head= decompose(head,poped_node);
  }
/*
if(var<answer_list[0]
      if(poped_node.data!=answer_list[i_check]){
                printf("List pop error \n");
                
           return 0;
         }
*/
      i_check++;
}

printf("test pass");
return 1;
}







//main
int main(int argc, char *argv[]){
  if(argc != 4) {
      printf("usage: list  <nrEvent>  <debug>\n");
      exit(0);
    }
int num;

    n_max =atoi(argv[1]);//nrEvent
    debug=atoi(argv[2]); //debug
int seed=atoi(argv[3]);
    int r =0;
    struct timespec time;
    uint64_t time_diff;
    time_t rand_t;
    node *head, *p;
    head = NULL;
   srand(seed);
  int n =rand()%((n_max-counter));//random N
      n=absu(n);
    while(n==0){
      n =(rand())%((n_max-counter));
    }

    //initial Q
    double previous_timestemp=0;
    int init_t=0;

    //add
    for(int i=0;i<n;i++) {
       clock_gettime(CLOCK_MONOTONIC,&time);
        time_diff=(BILLION * (time.tv_sec)+ time.tv_nsec);
        double timestemp=(double)time_diff;

        timestemp =timestemp+((timestemp-previous_timestemp)*(rand()/(double) RAND_MAX));
        head = insert(head,timestemp);
        previous_timestemp=timestemp;
        init_t=init_t+(insert_t+search_t);


        //DEBUG
if(debug==1){
if(head->tail==NULL){
 printf("\n\n#Error Report!\n");
      printf("HEAD->tail is empty\n");
      printf("#HEAD is%f:\n",head->data);
return 0;
}
    }
    }

    enqueue_t=enqueue_t+(init_t/n);


    p = head;

    //DEBUG
int check=1;
double temp=0;
if (debug==1){
  p = head;
printf("#Current list:\n");
    if(head!=NULL){
 temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
}
}

    //pop
    while(head!=NULL){
      node poped_node=pop(head);
      head=trace;


      //DEBUG
if (debug==1){
      printf("\n#POPED %f\n",poped_node.data );

 check=1;
  p = head;
      printf("#Current list:\n");
    if(head!=NULL){
     temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
}
}

      //decompose
      if(counter<=n_max){
     head=decompose(head,poped_node);
  }

if (debug==1){
  //DEBUG
 check=1;
  p = head;
      printf("#Current list:\n");
    if(head!=NULL){
 temp=p->data;

      while(p) {
         printf("#%f ", p->data);
if (temp> p->data){
      printf("\n\n#Error Report!\n");
      printf("#Temp is %f:\n",temp);
      printf("#p.data is %f:\n",p->data);
check =0;
}
if(check==0){
      printf("\n#Rest of the list:\n");
}
         temp=p->data;
          p = p->ptr;

      }
if (check==0){
      printf("#WARNING TEST FAILED!!!!!!!!!!\n");
return 0;
}
      printf("\n ");
}
}


     }
    enqueue_t=enqueue_t+(rest_t/enqueue_counter);




//debyg
    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

     //node poped_node=pop(head);//last
//debug
    //printf("\n#POPED %f\n",poped_node.data );









    int current= n;
    printf("%d\t%lf\t%lf\n", n_max, (enqueue_t/2.0),(dequeue_t/dequeue_counter));
    return 0;
}
