#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int arr[50][2];
int level=0;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* assignhd(struct Node* root, int hd, int *min, int *max){
    if(root!=NULL){
        if(hd< *min)
            *min=hd;
        if(hd>*max)
            *max=hd;
        arr[level][0] = root->data;
        arr[level][1] = hd;
        level++;
        assignhd(root->left, hd-1, min, max);
        assignhd(root->right, hd+1, min, max);
    }
}
int flagArr[50];
int ind=0;
bool inFlagArr(int target){
    int i;
    for(i=0; i<ind; i++){
        if(flagArr[i]==target)
            return true;
    }
    flagArr[ind] = target;
    ++ind;
    return false;
}
void topView(struct Node *root)
{
    int min=50, max=-1;
    assignhd(root, 0, &min, &max);
    int longestleft=0, longestright=0;
    struct Node* temp = root;
    while(temp->left!=NULL){
        --longestleft;
        temp = temp->left;
    }
    
    temp = root;
    while(temp->right!=NULL){
        ++longestright;
        temp = temp->right;
    }
    
    int i;
    for(i=0; i<level; i++){
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    printf("longest %d %d\n", longestleft, longestright);  
    for(i=0; i<level; i++){
        if(arr[i][1]<=longestleft && !inFlagArr(arr[i][1]))
            printf("%d ", arr[i][0]);
        if(arr[i][1]<=longestright && !inFlagArr(arr[i][1]))
            printf("%d ", arr[i][0]);
        if(arr[i][1]==min && !inFlagArr(arr[i][1]))
            printf("%d ", arr[i][0]);
        if(arr[i][1]==max && !inFlagArr(arr[i][1]))
            printf("%d ", arr[i][0]);
    }
}

int main(){
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(40);
    root->left->right = newNode(60);
    root->right = newNode(30);
    topView(root);
}
 