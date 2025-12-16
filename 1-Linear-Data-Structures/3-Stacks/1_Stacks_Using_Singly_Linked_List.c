// Stacks_Using_Singly_Linked_List

#include<stdio.h>
#include<stdlib.h> // Be careful

struct student{
    int data;
    struct student *next;
};

struct student *start=NULL;

// Display all elements (printForward)
void display(){
    printf("Stack elements: ");
    struct student *i=start;
    //----------(Part-1: Empty stack)
    if(i==NULL){
        printf("Stack is empty.\n");
    }
    //----------(Part-2: Not empty stack)
    else{
        while(i!=NULL){
            printf("%d->", i->data);
            i=i->next;
        }
    }
    printf("\n");
}

// Push operation (insertEnd)
void push(){
    struct student *newnode;
    int value;
    printf("Enter the data to push: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    struct student *i=start;
    //----------(Part-1: Empty stack)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty stack)
    else{ // 1 Change
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=newnode;
    }
}

// Pop operation (deleteEnd)
void pop(){
    //----------(Part-1: Empty stack)
    if(start==NULL){
        printf("Stack Underflow! Nothing to pop.\n");
    }
    //----------(Part-2: One node)
    else if(start->next==NULL){
        struct student *temp=start;
        start=NULL;
        free(temp);
    }
    //----------(Part-3: Several node)
    else{
        struct student *i=start;
        while(i->next->next!=NULL){
            i=i->next;
        }
        struct student *temp=i->next;
        i->next=NULL;
        free(temp);
    }
}

// Check if stack is empty
void isEmpty(){
    if(start==NULL){
        printf("Stack is empty.\n");
    }
    else{
        printf("Stack is NOT empty.\n");
    }
}

// Peek operation (Top element)
void peek(){
    if(start==NULL){
        printf("Stack is empty. No top element.\n");
    }
    else{
        struct student *i=start;
        while(i->next!=NULL){
            i=i->next;
        }
        printf("Top element is: %d\n", i->data);
    }
}

// Count stack elements (countNodes)
void countNodes(){
    int count=0;
    struct student *i=start;
    while (i!=NULL){
        count++;
        i=i->next;
    }
    printf("Total elements in stack: %d\n", count);
}

int main(){

    push();
    display();
    push();
    display();
    push();
    display();

    pop();
    display();

    isEmpty();
    
    peek();

    countNodes();

    return 0;
}
