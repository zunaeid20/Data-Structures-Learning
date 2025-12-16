// Binary_Search_Trees

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int x){
    struct node *newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node *insertBST(struct node *root, int x){
    if(root==NULL){
        return createNode(x);
    }
    if(x>root->data){
        root->right=insertBST(root->right, x);
    }
    else if(x<root->data){
        root->left=insertBST(root->left, x);
    }
    return root;
}

void printInorder(struct node *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    printf("%d->", root->data);
    printInorder(root->right);
}

struct node *findMin(struct node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node *deleteBST(struct node *root, int x){
    if(root==NULL){
        return NULL;
    }
    if(x>root->data){
        root->right=deleteBST(root->right, x);
    }
    else if(x<root->data){
        root->left=deleteBST(root->left, x);
    }
    else{
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        else{
            struct node *temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteBST(root->right, temp->data);
        }
    }
    return root;
}

int main(){
    struct node* root=NULL;
    root=insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 10);
    insertBST(root, 1);
    insertBST(root, 7);
    insertBST(root, 12);
    printInorder(root);
    printf("\n");
    deleteBST(root, 5);
    printInorder(root);
    printf("\n");
    return 0;
}
