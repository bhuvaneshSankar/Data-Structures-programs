#include<stdio.h>
#include<stdlib.h>

int arr[];
int level=0;
struct Node{
    int data;
    int hd;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    newNode->hd=0;
    return newNode;
}
struct Node* assignhd(struct Node* current, int hd){
    if(current!=NULL){
        current->hd = hd;
        assignhd(current->left, hd-1);
        assignhd(current->right, hd+1);
    }
}
struct Node* preorder(struct Node* current){
    if(current!=NULL){
        printf("%d ", current->hd);
        preorder(current->left);
        preorder(current->right);
    }
}
struct Node* gethdArr(struct Node* current){
    if(current!=NULL){
        gethdArr(current->left);
        arr[level++] = current->hd;
        gethdArr(current->right);
    }
}
struct Node* printTree(struct Node* current, int targethd){
    if(current!=NULL){
        if(current->hd == targethd)
            printf("%d ", current->data);
        printTree(current->left, targethd);
        
        printTree(current->right, targethd);
    }
}
void printVerticalOrder(struct Node* root, int minRange, int maxRange){
    int i;
    for(i=minRange; i<=maxRange; i++){
        printTree(root, i);
    }
}
int main(){
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    
    assignhd(root,0);
  //  preorder(root);
    gethdArr(root);
    int i ;
    int minRange = arr[0];
    int maxRange = arr[level-1];
  //  printf("%d %d", minRange, maxRange);
    printVerticalOrder(root, minRange, maxRange);
  //  for(i=0; i<level; i++)
  //      printf("%d ", arr[i]);

}






/* below is the code that i have put in gfg for this problem.  the requirement is to complete the verticalOrder fn which is 
provided with root ptr.  struct Node has elements => data, left, right. Not allowed to modify the struct Node.*/


/* int arr[1000][2];
int level=0;
struct Node* assignhd(struct Node* root, int hd, int *min, int *max){
    if(root!=NULL){
        if(hd< *min)
            *min=hd;
        if(hd>*max)
            *max=hd;
        assignhd(root->left, hd-1, min, max);
        assignhd(root->right, hd+1, min, max);
    }
}
struct Node* printTree(struct Node* root, int target, int hd){
    if(root!=NULL){
        if(hd==target){
            printf("%d ", root->data);
        }
        printTree(root->left, target, hd-1);
        printTree(root->right, target, hd+1);
    }
}
void verticalOrder(Node *root)
{
    //Your code here
    int min=1000, max=-1;
    assignhd(root,0, &min, &max);
    int i;
    for(i=min; i<=max; i++){
        printTree(root, i, 0);
    }
}  */