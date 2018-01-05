#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
//https://stackoverflow.com/questions/21788598/c-inserting-into-linked-list-in-ascending-order
typedef struct node{
    float data;
    struct node *ptr;
    int arch;
} node;

int archtecture=1;
int maxTask =1;

node* insert(node* head, float num, int arch) {
    node *temp, *prev, *next;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
    temp->arch = arch;
    if(!head){
        head=temp;
    } else{
        prev = NULL;
        next = head;
        while(next && next->data<=num){
            prev = next;
            next = next->ptr;
        }
        if(!next){
            prev->ptr = temp;
        } else{
            if(prev) {
                temp->ptr = prev->ptr;
                prev-> ptr = temp;
            } else {
                temp->ptr = head;
                head = temp;
            }
        }
    }
    return head;
}

node *trace=NULL;
node pop(node* head){
  trace =head->ptr;
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
        //printf("Enter a number");
        //scanf("%d",&num);
        timestemp =clock();
        head = insert(head, timestemp,archtecture);
    }
    p = head;

    //DEBUG
      //  printf("\n#The numbers are:\n");
        while(p) {
          //  printf("#%f ", p->data);
            p = p->ptr;
        }

    //pop
    while(head->ptr!=NULL){
      node poped_node=pop(head);
      head=trace;


      //printf("\n#POPED %f\n",poped_node.data );
      //DEBUG
      //p = head;
        //  printf("#Current list:\n");
        //  while(p) {
          //    printf("#%f ", p->data);
          //    p = p->ptr;
          //}
          //printf("\n ");

      //decompose
      if(poped_node.arch>0){
     decompose(head,poped_node);
  }
     }

    // printf("#LAST ONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
     node poped_node=pop(head);//last
     //printf("\n#POPED %f\n",poped_node.data );


  //  printf("\n New node");
  //  scanf("%d",&r );
  //  insert(head, r);
    //free_list(head);
    t=clock()-t;
    float effeciency=((float)t)/CLOCKS_PER_SEC*1000;
    int current= n;
     printf("%d\t%.8f\n", current, effeciency);
    return 0;
}
