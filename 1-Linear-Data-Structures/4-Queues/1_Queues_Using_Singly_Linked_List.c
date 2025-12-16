// Queues_Using_Singly_Linked_List

#include<stdio.h>
#include<stdlib.h> // Be careful

struct student{
    int data;
    struct student *next;
};

struct student *start=NULL;

// Display all elements (printForward)
void display(){
    printf("Queue elements: ");
    struct student *i=start;
    //----------(Part-1: Empty queue)
    if(i==NULL){
        printf("Queue is empty.\n");
    }
    //----------(Part-2: Not empty queue)
    else{
        while(i!=NULL){
            printf("%d->", i->data);
            i=i->next;
        }
    }
    printf("\n");
}

// Enqueue operation (insertEnd)
void enqueue(){
    struct student *newnode;
    int value;
    printf("Enter the data to enqueue: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    struct student *i=start;
    //----------(Part-1: Empty queue)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty queue)
    else{ // 1 Change
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=newnode;
    }
}

// Dequeue Operation (deleteBeginning)
void dequeue(){
    //----------(Part-1: Empty queue)
    if(start==NULL){
        printf("Queue Underflow! Nothing to dequeue.\n");
    }
    //----------(Part-2: Both one node and several nodes)
    else{
        struct student *temp=start;
        start=start->next;
        free(temp);
    }
}

// Check if queue is empty
void isEmpty(){
    if(start==NULL){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue is NOT empty.\n");
    }
}

// Get Front Element
void frontElement(){
    if(start==NULL){
        printf("Queue is empty. No front element.\n");
    }
    else{
        printf("Front element: %d\n", start->data);
    }
}

// Get Rear Element
void rearElement(){
    if(start==NULL){
        printf("Queue is empty. No rear element.\n");
    }
    else{
        struct student *i=start;
        while(i->next!=NULL){
            i=i->next;
        }
        printf("Rear element is: %d\n", i->data);
    }
}

// Count queue elements (countNodes)
void countNodes(){
    int count=0;
    struct student *i=start;
    while (i!=NULL){
        count++;
        i=i->next;
    }
    printf("Total elements in queue: %d\n", count);
}

int main(){

    enqueue();
    display();
    enqueue();
    display();
    enqueue();
    display();

    dequeue();
    display();

    isEmpty();

    frontElement();

    rearElement();

    countNodes();

    return 0;
}
