#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

//https://stackoverflow.com/questions/21788598/c-inserting-into-linked-list-in-ascending-order
typedef struct node{
    float data;
    struct node *ptr;
    struct node *ptr_p;
    struct node *tail;
} node;


int pCount;
int debug=0;
clock_t save;
int counter=0;
int n_max=0;
float n_counter=0;

clock_t insert_timer=0;
node* insert(node* head, float num) {
counter++;
clock_t start,end;

    node *temp ,*tail;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    //first
    if(!head){
        head=temp;
        head->tail=temp;
    } else{
if(temp->data<=head->data){//insert head
head->ptr_p=temp;
temp->ptr=head;
temp->ptr_p=NULL;
temp->tail=head->tail;
head->tail=NULL;
head=temp;//update head
}else if(temp->data>=head->tail->data){//insert tail
temp->ptr_p=head->tail;
head->tail->ptr=temp;
temp->ptr=NULL;
head->tail=temp;//update tail
}else{
printf("data in temp %f\n",temp->data);
printf("data in head %f\n",head->data);
printf("data in tail %f\n",head->tail->data);
printf("why am i here!");
int avg =head->data+head->tail->data;
      avg=avg/2;//average
if (num>avg){
node *container=head->tail;

//search
start=clock();
while(temp->data<container->data){
n_counter++;
container=container->ptr_p;
}


end =clock();
insert_timer=insert_timer+(end-start);
//link temp
temp->ptr_p=container;
temp->ptr=container->ptr;
//update container
container->ptr->ptr_p=temp;
container->ptr=temp;
}else{
node *container=head;
//search
start=clock();

while(temp->data>container->data){
n_counter++;
container=container->ptr;
}


end =clock();
insert_timer=insert_timer+(end-start);

//link temp
temp->ptr=container;
temp->ptr_p=container->ptr_p;
//update container
container->ptr_p->ptr=temp;
container->ptr_p=temp;


}


}
    }


if (debug==2){
    node *p;
double temp =0;
int check =0;
  p = head;
printf("#INSERT:\n");
printf("#Current list:\n");


    if(head!=NULL){
 temp=p->data;

      while(p) {
         printf("#%f ", temp);
         temp=p->data;
          p = p->ptr;

      }
}


    }




    return head;
}

clock_t pop_timer=0;
node *trace=NULL;
//pop
node pop(node* head){
clock_t start,end;
start=clock();
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

end =clock();
pop_timer=pop_timer+(end-start);
node out = *head;
free(head);
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
int increment(node* head){
int avg =0;
if(head==NULL){
avg=3;
}else{
  avg =(head->tail->data-head->data);//dynamic range
}
  int out=absu(rand()+rand()-rand())%(avg+1)+head->tail->data;

  int choose=absu(rand()+rand()-rand())%(2);
if (choose==1){
  out= head->tail->data+absu(out);
}else{
  out=head->data-absu(out);
}
  //printf("%d , %d\n",out,avg);
  return out ;
}

//decompose
node* decompose(node* head,node element){
  int n =absu(rand()+rand()-rand())%(n_max-counter);//random N
  n=absu(n);
  float t =element.data;// obtain value from main node
float variable=0;
//printf("#value of n is %d\n", n);
insert_timer=0;
  for(int i=1;i<n;i++){
     variable =t+increment(head);
    head = insert(head, variable);
  }
if (n !=0){
insert_timer=insert_timer/n;
}

save =save+insert_timer;

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

save=save/9;


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
insert_timer=0;
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
if (n !=0){
insert_timer=insert_timer/n;
}
save=save+insert_timer;

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


if (div_counter !=0){
pop_timer=pop_timer/div_counter;

}
save =save+pop_timer;

//debyg
    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

     //node poped_node=pop(head);//last
//debug
    //printf("\n#POPED %f\n",poped_node.data );


    double effeciency=(save)/(double)CLOCKS_PER_SEC*1000;

    int current= n;
     printf("%d\t%lf\n", n_max, effeciency);
    return 0;
}
