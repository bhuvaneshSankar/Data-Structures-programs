#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* createNode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void printLinkedList(){
    struct node* temp = head;
    if(temp==NULL){
        printf("linkedlist is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void insertNode(int data){
    struct node* newnode = createNode(data);
    if(head==NULL){
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void reversell(){
    struct node* t1 = head;
    struct node* t2 = head->next;
    struct node* t3 = head->next->next;
    t1->next = NULL;
    while(t3!=NULL){
        t2->next = t1;
        t1 = t2;
        t2 = t3;
        t3 = t2->next;
    }
    t2->next = t1;
    head = t2;
    
}
bool isPresent(int* temp, int arr[], int len){
    int i;
    for(i=0; i<len; i++){
        if(arr[i]==temp)
            return true;
    }
    return false;
}
bool loopPresent(struct node* head){
    int *arr[100], index=0;
    struct node* temp = head;
    arr[index++] =  temp;
    temp = temp->next;
    while(temp != NULL){
        if(isPresent((int*)temp, arr, index))
            return true;
        arr[index++] =  &temp;
        temp = temp->next;

    }
}
int main(){
    insertNode(5);
    insertNode(10);
    insertNode(7);
    insertNode(18);
    printLinkedList();
    printf("\n");
    reversell();
    printLinkedList();
    if(loopPresent(head)==true)
        printf("\nloop present");
    else
            printf("\nno loop present");
    
}