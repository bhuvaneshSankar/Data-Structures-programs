#include<stdio.h>   /*serialization - storing a binary tree into an array, deserialization - array to binary tree */
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node* left;
    struct node* right;
};
int it=0;
struct node* head = NULL;
struct node* desHead = NULL;
struct node* createNode(char val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* createBinaryTree(char arr[], int n, int i, struct node* head){
    if(i<n){
     //   printf("%d ", i);
        struct node* temp = createNode(arr[i]);
        head = temp;
        head->left = createBinaryTree(arr, n, 2*i+1, head->left);
        head->right = createBinaryTree(arr, n, 2*i+2, head->right);
        i++;
    }
    return head;
}
void inorder(struct node* head){
    if(head!=NULL){
        inorder(head->left);
        printf("%c ", head->data);
        inorder(head->right);
    }
}

char* serialize(struct node* head, char serializeArr[], int len){
    if(head == NULL){
        serializeArr[it++] = '-';
        return;
    }
    else{
        serializeArr[it++] = head->data;
        head->left = serialize(head->left, serializeArr, len);
        head->right = serialize(head->right, serializeArr, len);
    }
    return serializeArr;
}
int desIndex=0;
struct node* deserialize(char serializedArr[], struct node* desHead, int len ){
//    printf("%d ", desIndex);
    if(desIndex==len || serializedArr[desIndex]=='-'){
        desIndex += 1;
        return NULL;
    }
    else{
    struct node* temp = createNode(serializedArr[desIndex]);
    desHead = temp;
    desIndex+=1;
    desHead->left = deserialize(serializedArr, desHead->left, len);
    desHead->right = deserialize(serializedArr, desHead->right, len);
    
    }
    return desHead;
}
void printSerializedTree(char arr[], int len){
    int i;
    for(i=0; i<len; i++){
        printf("%c ", arr[i]);
    }
}

int main(){
    char arr[] = "hello";
    int len = strlen(arr);
    head = createBinaryTree(arr, len, 0, head);
    inorder(head);
    char serializeArr[100];
    serialize(head, serializeArr, 100);
    printf("\n");
    printSerializedTree(serializeArr, it);
    desHead = deserialize(serializeArr, desHead, it);
    printf("\n");
    inorder(desHead);
}