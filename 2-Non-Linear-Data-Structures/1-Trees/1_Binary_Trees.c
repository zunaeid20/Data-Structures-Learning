// Binary_Trees

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

void printInorder(struct node *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    printf("%d->", root->data);
    printInorder(root->right);
}

void printPreorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d->", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void printPostorder(struct node *root){
    if(root==NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d->", root->data);
}

int main(){
    struct node *root=createNode(10);
    root->left=createNode(20);
    root->right=createNode(30);
    root->left->left=createNode(40);
    root->left->right=createNode(50);
    printInorder(root);
    printf("\n");
    printPreorder(root);
    printf("\n");
    printPostorder(root);
    printf("\n");
    return 0;
}
