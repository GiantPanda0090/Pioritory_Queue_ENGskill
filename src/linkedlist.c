#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


typedef struct node{
  int data;
  struct node * next;
}node;

node * createLinkedList(int n);
void displayList(node * head);
int main(){

  int n =0;
  node * HEAD=NULL;
  printf("\n How many nodes do you want to have in the linkedlist?");
  scanf("%d",&n );

HEAD=createLinkedList(n);
displayList(HEAD);
printf("\n");

  return 0;
}
node * createLinkedList(int n){
  int i=0;
  node * head=NULL;
  node * temp=NULL;
  node * p=NULL;

for(int i=0;i<n;i++){
  temp = (node*)malloc(sizeof(node));
  printf("\n enter data");
  scanf("%d",&(temp -> data));
  temp->next=NULL;
  if (head==NULL){
    head=temp;
  }
  else{
    p=head;
    while(p->next!=NULL)
      p=p->next;
    p->next=temp;

  }
}
return head;
}

void displayList(node * head){
  node * p=head;
  while( p!=NULL){
    printf("\t%d",p->data );
    p=p->next;

  }
}
