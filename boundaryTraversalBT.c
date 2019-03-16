#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

bool isLeaf(struct Node* node){
    if(node->left==NULL && node->right == NULL)
        return true;
    else
        return false;
}
struct Node* printLeaves(struct Node* current, int ll, int lr){
    if(current!=NULL){
        if(isLeaf(current)){
            if(current->data != ll && current->data != lr)
                printf("%d ", current->data);
        }
        printLeaves(current->left, ll, lr);
        printLeaves(current->right, ll, lr);
    }
}
struct Node* printRightBoundary(struct Node* current, bool flag){
    if(current!=NULL){
        if(current->left!=NULL && current->right!=NULL){
            if(current->left->left==NULL && current->left->right==NULL)
                flag=false;
        }
        if(current->left!=NULL && flag==true)
            printRightBoundary(current->left, flag);
        printRightBoundary(current->right, flag);
        printf("%d ", current->data);
    }
}
struct Node* printLeftBoundary(struct Node* current, bool flag, int* lf){
    if(current!=NULL){
        if(current->left==NULL && current->right==NULL){
            *lf = current->data;
        }
        printf("%d ", current->data);
        if(current->left!=NULL){
            printLeftBoundary(current->left, flag, lf);
        }
        else if(current->left==NULL && current->right!=NULL){
            printLeftBoundary(current->right, flag, lf);
        }
    }
}
int getlongestright(struct Node* current, int lr){
    if(current==NULL){
        return lr;
    }
    if(current->left == NULL && current->right == NULL){
        lr = current->data;
        return lr;
    }
    if(current->left!=NULL){
        lr = getlongestright(current->left, lr);
    }
    if(current->right!=NULL)
        lr = getlongestright(current->right, lr);
    return lr;
}
void printBoundary(Node *root)
{
     struct Node* temp = root;
/*     while(temp->left!=NULL){
         printf("%d ", temp->data);
         temp = temp->left;
     }
     printf("%d ", temp->data);  */
     
     int longestLeft = root->data;
     bool flag=true;
     printf("%d ", root->data);
     printLeftBoundary(root->left, flag, &longestLeft);
     int longestRight = root->data; 
     longestRight = getlongestright(root->right, longestRight);
     
     printLeaves(root, longestLeft, longestRight);
     flag=true;
     printRightBoundary(root->right, flag);
}