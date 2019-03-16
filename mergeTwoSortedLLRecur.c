#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* h1 = NULL;
struct node* h2 = NULL;

struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}
struct node* mergeLL(struct node* r1, struct node* r2){
    
    struct node* current = NULL;
    if(r1==NULL)
        return r2;
    if(r2==NULL)
        return r1;
    

    if(r1->data<r2->data){
        current =r1;
        current->next = mergeLL(r1->next, r2);
    }
    else{
        current = r2;
        current->next = mergeLL(r1, r2->next);
    }
  //  return current;
}
void printLL(struct node* current){
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}


int main(){
    h1 = createnode(5);
    h1->next = createnode(10);
    h1->next->next = createnode(15);

    h2 = createnode(2);
    h2->next = createnode(12);
    h2->next->next = createnode(20);

    struct node* mergehead = NULL;
    mergehead = mergeLL(h1, h2);
  
    printLL(mergehead);
}