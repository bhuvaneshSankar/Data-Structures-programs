#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* head = NULL;


struct node* createnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node* preOrder(struct node* current){
    if(current!=NULL){
        printf("%d ", current->data);
        preOrder(current->left);
        preOrder(current->right);
    }
}
bool checkSym(struct node* temp1, struct node* temp2, bool flag){
    printf("%d %d\n", temp1->data, temp2->data);
    if(temp1==NULL && temp2==NULL){
        return flag;
    }
    if(temp1->left==NULL && temp2->right!=NULL){
        flag=false;
        return flag;
    } 
    if(temp1->left!=NULL && temp2->right == NULL){
        flag=false;
        return flag;
    }
    if(temp1->right==NULL && temp2->left!=NULL){
        flag=false;
        return flag;
    }
    if(temp1->right!=NULL && temp2->left==NULL){
        flag=false;
        return flag;
    }
    if(temp1->data != temp2->data){
        flag=false;
        return flag;
    }
    if(temp1->left!=NULL && temp2->right!=NULL && flag==true){
       flag =  checkSym(temp1->left, temp2->right, flag);
    }
    if(temp1->right!=NULL && temp2->left!=NULL && flag==true){
       flag =  checkSym(temp1->right, temp2->left, flag);
    }
    return flag;
    
}
int main(){
    head = createnode(0);
    head->left = createnode(1);
    head->right = createnode(1);
    head->left->left = createnode(3);
    head->left->right = createnode(2);
  //  head->right->left=createnode(2);
 //   head->right->right  = createnode(3);
 //   preOrder(head);
    bool flag = true;
    flag = checkSym(head->left, head->right, flag);
    if(flag==true)
        printf("symmetric");
    else 
        printf("not symmetric");
}