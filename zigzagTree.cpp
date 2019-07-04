#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
stack<struct node*> current, nxt;
struct node* createNode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
}
struct node* insert(int data, struct node* root){
    if(root == NULL){
    return createNode(data);
    }
    else if(data<root->data){
    root->left = insert(data, root->left);
    }
    else if(data>root->data){
        root->right = insert(data, root->right);
    }
    return root;
}
void swap(){
    stack<struct node*> temp;
    while(!nxt.empty()){
        temp.push(nxt.top());
        nxt.pop();
    }
    while(!temp.empty()){
        current.push(temp.top());
        temp.pop();
    }
}
void spiralTraversal(struct node* root, int level){
        while(!current.empty()){
            struct node* temp = current.top();
            current.pop();
            cout<<temp->data<<" ";
            if(level%2==0){
                if(temp->left!=NULL)
                    nxt.push(temp->left);
                if(temp->right!=NULL)
                    nxt.push(temp->right);
            }
            else{
                if(temp->right!=NULL)
                    nxt.push(temp->right);
                if(temp->left!=NULL)
                    nxt.push(temp->left);    
            }
        }
        swap(current, nxt);       
        if(!current.empty())
            spiralTraversal(root, level+1);
}
void inorder(struct node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}
int main(){
    root = insert(50, root);
    root = insert(25, root);
    root = insert(200, root);
    root = insert(15, root);
    root = insert(35, root);
    root = insert(100, root);
    root = insert(211, root);
    root = insert(5, root);
    root = insert(20, root);
    root = insert(30, root);
    root = insert(40, root);
    root = insert(3, root);
    root = insert(10, root);
    root = insert(17, root);
    root = insert(23, root);
    current.push(root);
    spiralTraversal(root, 0);
}
