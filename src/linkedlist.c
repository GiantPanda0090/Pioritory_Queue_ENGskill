#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
//https://stackoverflow.com/questions/21788598/c-inserting-into-linked-list-in-ascending-order
typedef struct node{
    float data;
    struct node *ptr;
    struct node *tail;
    int arch;
} node;

int archtecture=1;
int maxTask =1;
node* insert(node* head, float num, int arch) {
    node *temp, *prev, *next,*tail;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    temp->arch = arch;
    if(!head){
        head=temp;
        tail=temp;
    } else{
      tail=head->tail;
      int avg =head->data+tail->data;
      avg=avg/2;
        prev = NULL;
        next = head;
        if(num>avg){
            prev = tail;
            next = NULL;
            tail->ptr = temp;
            temp->ptr = NULL;
            tail=temp;
        }else{
          temp->ptr=next;
          head =temp;
        }
    }
    head->tail=tail;

    return head;
}

node *trace=NULL;
node pop(node* head){
  node *tail=head->tail;
  trace =head->ptr;
  if(trace!=NULL){
    trace->tail=head->tail;
  }
  node out = *head;
free(head);
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

int increment(){
  return rand()%(int)(1000);
}

int decompose(node* head,node element){
  element.arch=element.arch-1;
  int n =rand()%maxTask;//random N
  int t =element.data;// obtain value from main node
  for(int i=1;i<n;i++){
    head = insert(head, t+increment(),element.arch);
  }
  return 0;
}


int main(int argc, char *argv[]){

  if(argc != 4) {
      printf("usage: list <maxTask> <nrEvent> <archtecture>\n");
      exit(0);
    }

    int num;
    maxTask =atoi(argv[1]);//decompose
    int n =atoi(argv[2]);//nrEvent
    archtecture=atoi(argv[3]);//arch
    int r =0;
    clock_t timestemp,t;
    node *head, *p;
    head = NULL;
    t=clock();
    //add
    for(int i=0;i<n;i++) {
        timestemp =clock();
        head = insert(head, timestemp,archtecture);
    }
    p = head;

    //DEBUG
    /*
        printf("\n#The numbers are:\n");
        while(p) {
            printf("#%f ", p->data);
            p = p->ptr;
        }
*/
    //pop
    while(head->ptr!=NULL){
      node poped_node=pop(head);
      head=trace;

      //DEBUG
/*
      printf("\n#POPED %f\n",poped_node.data );
      p = head;
          printf("#Current list:\n");
          while(p) {
             printf("#%f ", p->data);
              p = p->ptr;
          }
          printf("\n ");
*/
      //decompose
      if(poped_node.arch>0){
     decompose(head,poped_node);
  }


  //DEBUG
  /*
  p = head;
      printf("#Current list:\n");
      while(p) {
         printf("#%f ", p->data);
          p = p->ptr;
      }
      printf("\n ");
      */
     }

    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");

     node poped_node=pop(head);//last
     /*
    printf("\n#POPED %f\n",poped_node.data );
    */
    t=clock()-t;
    float effeciency=((float)t)/CLOCKS_PER_SEC*1000;
    int current= n;
     printf("%d\t%.8f\n", current, effeciency);
    return 0;
}
