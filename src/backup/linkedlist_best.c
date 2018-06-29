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
    float data;
    struct node *ptr;
    struct node *ptr_p;
    struct node *tail;
} node;


int pCount;
int debug=0;
int insert_t,pop_t,search_t;
int enqueue_t,dequeue_t;
int insert_counter=0;
int enqueue_counter=0;
int dequeue_counter=0;
int search_counter=0;

int pop_counter=0;
int counter=0;
int n_max=0;
float n_counter=0;

//insertion
node* insert(node* head, double num) {
    insert_t=0;
    search_t=0;
    counter++;
    struct timespec start,end,start_search,end_search;


    node *temp ,*tail;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    //first
    if(!head){
        //add
        clock_gettime(CLOCK_REALTIME,&start);

        head=temp;
        head->tail=temp;

        clock_gettime(CLOCK_REALTIME,&end);
        insert_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
        insert_counter++;

    } else{
        if(temp->data<=head->data){//insert head

            //add
            clock_gettime(CLOCK_REALTIME,&start);


            head->ptr_p=temp;
            temp->ptr=head;
            temp->ptr_p=NULL;
            temp->tail=head->tail;
            head->tail=NULL;
            head=temp;//update head

            clock_gettime(CLOCK_REALTIME,&end);
            insert_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
            insert_counter++;

        }else if(temp->data>=head->tail->data){//insert tail

            //add
            clock_gettime(CLOCK_REALTIME,&start);

            temp->ptr_p=head->tail;
            head->tail->ptr=temp;
            temp->ptr=NULL;
            head->tail=temp;//update tail

            clock_gettime(CLOCK_REALTIME,&end);
            insert_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
            insert_counter++;

        }else{
            int avg =head->data+head->tail->data;
            avg=avg/2;//average


            if (num>avg){
                node *container=head->tail;


//search
                clock_gettime(CLOCK_REALTIME,&start_search);

                while(temp->data<container->data){
                    n_counter++;
                    container=container->ptr_p;
                }

                clock_gettime(CLOCK_REALTIME,&end_search);
                search_t=(long long unsigned int)(BILLION * (end_search.tv_sec - start_search.tv_sec) + end_search.tv_nsec - start_search.tv_nsec);
                search_counter++;


//add
                clock_gettime(CLOCK_REALTIME,&start);

                temp->ptr_p=container;
                temp->ptr=container->ptr;
//update container
                container->ptr->ptr_p=temp;
                container->ptr=temp;

                clock_gettime(CLOCK_REALTIME,&end);
                insert_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
                insert_counter++;


            }else{
                node *container=head;

//search
                clock_gettime(CLOCK_REALTIME,&start_search);

                while(temp->data>container->data){
                    n_counter++;
                    container=container->ptr;
                }

                clock_gettime(CLOCK_REALTIME,&end_search);
                search_t=(long long unsigned int)(BILLION * (end_search.tv_sec - start_search.tv_sec) + end_search.tv_nsec - start_search.tv_nsec);
                search_counter++;


                //add
                clock_gettime(CLOCK_REALTIME,&start);

//link temp
                temp->ptr=container;
                temp->ptr_p=container->ptr_p;
//update container
                container->ptr_p->ptr=temp;
                container->ptr_p=temp;

                clock_gettime(CLOCK_REALTIME,&end);
                insert_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
                insert_counter++;


            }



        }
    }
    enqueue_t=enqueue_t+(insert_t+search_t);
    enqueue_counter++;
    return head;
}

clock_t pop_timer=0;
node *trace=NULL;
//pop
node pop(node* head){

if(debug==1){
if (head->ptr_p!=NULL){
      printf("#Head is%f:\n",head->data);
}
}
    struct timespec start,end;
    pop_t=0;


    clock_gettime(CLOCK_REALTIME,&start);


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


    clock_gettime(CLOCK_REALTIME,&end);
    pop_t=(long long unsigned int)(BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec);
    pop_counter++;

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
//https://stackoverflow.com/questions/22268815/absolute-value-of-int-min
unsigned int absu(int value) {
    return (value < 0) ? -((unsigned int)value) : (unsigned int)value;
}

//increment generator
int increment(node* head,int t){
    int avg =0;
    int x=0;
    int x_tail=0;
    if(head==NULL){
        avg=3;
        x =avg*((double)rand() / (double)RAND_MAX );
        x_tail =avg*((double)rand() / (double)RAND_MAX );

    }else{
        avg =(head->tail->data-head->data);//dynamic range
        x =(0)+((head->data)-t)*((double)rand() / (double)RAND_MAX );
        x_tail =((head->tail->data)-t)+((head->data)-t)*((double)rand() / (double)RAND_MAX );


    }

  int choose=absu(rand()+rand()-rand())%(2);
    int out=0;
if (choose==1){
  out=absu(x_tail);
}else{
  out=absu(x);
}
  //printf("%d , %d\n",out,avg);
  return absu(out) ;
}

//decompose
node* decompose(node* head,node element){
  int n =absu(rand()+rand()-rand())%(n_max-counter);//random N
  n=absu(n);
  float t =element.data;// obtain value from main node
float variable=0;
//printf("#value of n is %d\n", n);
  for(int i=1;i<n;i++){
     variable =t+increment(head,t);
    head = insert(head, variable);
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
    clock_t timestemp;
    time_t rand_t;
    node *head, *p;
    head = NULL;
   srand(seed);
  int n =absu(rand()+rand()-rand())%(n_max-counter);//random N
      n=absu(n);
    while(n==0){
      n =(rand()+rand()-rand())%(n_max-counter);
    }

    //add
    for(int i=0;i<n;i++) {
        timestemp =clock();
        head = insert(head, timestemp);
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


    p = head;

    //DEBUG
int check=1;
float temp=0;
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


int div_counter=0;
pop_timer=0;
    //pop
    while(head!=NULL){
      node poped_node=pop(head);
div_counter++;
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
      if(counter<n_max){
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




//debyg
    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

     //node poped_node=pop(head);//last
//debug
    //printf("\n#POPED %f\n",poped_node.data );

    printf("%d\t%d\t%d\n", n_max, (enqueue_t/enqueue_counter),(dequeue_t/dequeue_counter));
    return 0;
}
