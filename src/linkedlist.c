#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct node{
    int data;
    struct node *ptr;
} node;

node* insert(node* head, int num) {
    node *temp, *prev, *next;
    temp = (node*)malloc(sizeof(node));
    temp->data = num;
    temp->ptr = NULL;
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

int main(){
    int num;
    int n =0;
    int r =0;
    node *head, *p;
    head = NULL;
    printf("\n How many nodes do you want to have in the linkedlist?");
    scanf("%d",&n );
    for(int i=0;i<n;i++) {
        printf("Enter a number");
        scanf("%d",&num);
        if(num) {
            head = insert(head, num);
        }
    }
    p = head;
    printf("\nThe numbers are:\n");
    while(p) {
        printf("%d ", p->data);
        p = p->ptr;
    }
    printf("\n New node");
    scanf("%d",&r );
    free_list(head);
    return 0;
}
