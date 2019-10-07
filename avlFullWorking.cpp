#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};

struct node* root = NULL;

struct node* createNode(int data){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;

    return newnode;
}

int max(int a, int b){
    return a>b ? a:b ;
}
int height(struct node* temp){
    if(temp==NULL)
        return 0;
    
    return temp->height;
}

struct node* rotateRight(struct node* z){
    struct node* y = z->left;
    struct node* x = y->right;

    y->right = z;
    z->left = x;

    //update heights
    z->height = max(height(z->left), height(z->right));
    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(x->right));
    
    return y;
}

struct node* rotateLeft(struct node* z){
    struct node* y = z->right;
    struct node* x = y->left;

    y->left = z;
    z->right = x;

    //update heights
    z->height = max(height(z->left), height(z->right));
    y->height = max(height(y->left), height(y->right));
    x->height = max(height(x->left), height(x->right));

    return y;
}

struct node* insert(struct node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    root->height = max(height(root->left), height(root->right));
    int h1, h2;
    if(root->left == NULL){
        h1 = 0;
    }
    else{
        h1 = root->left->height;
    }
    if(root->right == NULL){
        h2 = 0;
    }
    else{
        h2 = root->right->height;
    }
 
    int balanceFactor = h1-h2;
    if(balanceFactor>1){
        if(data<=root->left->data){             // leftleft case
            return rotateRight(root);
        }
        else{
            root->left = rotateLeft(root->left);  //leftright case
            return rotateRight(root);
        }
    }
    else if(balanceFactor<-1){
        if(data>=root->right->data){            // rightright case
            return rotateLeft(root);
        }
        else{
            root->right = rotateRight(root->right);  //rightleft case
            return rotateLeft(root);
        }
    }
    return root;
}

int getMax(struct node* root){
    while(root->right!=NULL){
        root = root->right;
    }

    return root->data;
}

struct node* deleteNode(struct node* root, int data){
    if(root->data == data){
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
            int max = getMax(root->left);
            root->data = max;
            root->left = deleteNode(root->left, max);
        }
    }
    else if(root->data < data){
        root->right = deleteNode(root->right, data);
    }
    else if(root->data > data){
        root->left = deleteNode(root->left, data);
    }
    root->height = max(height(root->left), height(root->right));
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    int balanceFactor = h1-h2;
    if(balanceFactor<-1 || balanceFactor>1){
    struct node *z, *y, *x;                 // z is the root itself, y is the greatest height child of z, x is the greatest height child of y
    if(h1>h2)
        y = root->left;
    else    
        y = root->right;
    h1 = height(y->left);
    h2 = height(y->right);
    if(h1>h2)
        x = y->left;
    else    
        x = y->right;
    z=root;
    if(balanceFactor>1){
        
        if(y->left == x){
            return rotateRight(z);
        }
        else{
            root->left = rotateLeft(y);
            return rotateRight(z);
        }
    }
    else if(balanceFactor<-1){
        if(y->right == x){
            return rotateLeft(z);
        }
        else{
            root->right = rotateRight(y);
            return rotateLeft(z);
        }
    }
    }
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        cout<<height(root)<<endl;
        inorder(root->right);
    }
}
int main(){
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 120);
    root = insert(root, 70);
    

    root = insert(root, 150);
    root = insert(root, 30);
    root = insert(root, 110);
    root = insert(root, 400);
    root = insert(root, 10);
 //   root = insert(root, 500);
 //   root = insert(root, 60);
    inorder(root);
    cout<<endl;
    root = deleteNode(root, 70);
    cout<<"root "<<root->data<<endl;
    inorder(root);
    root = deleteNode(root, 30);
    cout<<"root "<<root->data<<endl;
    inorder(root);
    root = deleteNode(root, 400);
    cout<<"root "<<root->data<<endl;
    inorder(root);
    root = deleteNode(root, 150);
    root = deleteNode(root, 50);
    root = deleteNode(root, 10);
    cout<<"root "<<root->data<<endl;
    inorder(root);
}