#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* previous;
    struct node* next;
};
struct node* head = NULL;
struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->previous = NULL;
    newNode->next = NULL;
    return newNode;
}
struct node* insert(struct node* head, int value){
    struct node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->previous = temp;
    }
    return head;
}
void printLinkedList(){
    if(head==NULL){
        printf("\nlinked list is empty");
        return;
    }
    else{

        struct node* temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
struct node* leftShift(){
    if(head==NULL || head->next == NULL){
        printf("\ncant left shift");
        exit;
    }
    else{
        int tempData = head->data;
        struct node* temp = head;
        while(temp->next!= NULL){
            temp->data = temp->next->data;    
            temp = temp->next;    
        }
        temp->data = tempData;
    }
}
struct node* rightShift(){
    if(head==NULL || head->next == NULL){
        printf("\ncant left shift");
        exit;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        int tempData = temp->data;
        while(temp->previous != NULL){
            temp->data = temp->previous->data;
            temp = temp->previous;
        }
        temp->data = tempData;
    }
}
struct node* reverse(){
    if(head==NULL){
        printf("\nlinked list is null");
        exit;
    }
    else{
        struct node* t1 = head;
        struct node* t2 = head->next;
        struct node* t3 = head->next->next;
        while(t3!=NULL){
            t1->previous = t2;
            t2->next = t1;
            t1= t2;
            t2 = t3;
            t3 = t3->next;
        }
        t1->previous = t2;
        t2->previous = NULL;
        t2->next = t1;
        head->next = NULL;
        head = t2;
    }
    return head;
}
int main(){
    head = insert(head,5);
    head = insert(head,10);
    head = insert(head,15);
    head = insert(head,20);
 //   leftShift();
 //   leftShift();
 //   rightShift();
    printLinkedList();
    head = reverse();
    printLinkedList();
}