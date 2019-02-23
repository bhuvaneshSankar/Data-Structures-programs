#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct node* insertNode(struct node* root, int value){
    if(root == NULL){
        struct node* newNode = createNode(value);
        return newNode;
    }
    if(root->data<value){
        root->right = insertNode(root->right, value);
    }
    else if(root->data>value){
        root->left = insertNode(root->left, value);
    }
    return root;
}

void preOrderTraversal(struct node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int findMax(struct node* root){
    if(root == NULL){
        printf("tree empty");
        return -1;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root->data;
}

int findMin(struct node* root){
    if(root == NULL){
        printf("tree empty");
        return -1;
    }
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;
}

struct node* deleteNode(struct node* root, int target){
    if(root == NULL){
        printf("tree empty");
        return root;
    }
    if(root->data == target){
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;

        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            int minimum = findMin(root->right);
            root->data = minimum;
            root->right = deleteNode(root->right, minimum);
        }
    }
    else if(root->data < target){
        root->right = deleteNode(root->right, target);
    }
    else if(root->data > target){
        root->left = deleteNode(root->left, target);
    }
    return root;
}

int maxDepth(struct node*  root){
    if(root == NULL)
        return 0;
    else{
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);

        if(ldepth>rdepth)
            return ldepth+1;
        else
            return rdepth+1;
        
    }
}
int main(){
    struct node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 5);
    root = insertNode(root, 2);
    root = insertNode(root, 14);
    root = insertNode(root, 20);
    root = insertNode(root, 17);
    root = insertNode(root, 23);
    root = insertNode(root, 4);
    int max = findMax(root);
    int min = findMin(root);
 //   printf("\nmax = %d, min = %d", max, min);
  //  deleteNode(root, 15);
 //   deleteNode(root, 14);
  //  preOrderTraversal(root);
    printf("%d ", maxDepth(root));
}
