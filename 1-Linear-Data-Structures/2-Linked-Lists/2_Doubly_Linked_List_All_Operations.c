//Doubly_Linked_List_All_Operations

#include<stdio.h>
#include<stdlib.h>//Be careful

struct student {
    int data;
    struct student *next;
    struct student *prev; // Added for doubly linked list
};

struct student *start=NULL;

//Doubly_Linked_List_Traversal (Forward)
void printDoublyLinkedList(){
    struct student *i=start;
    printf("Forward Traversal: ");
    while(i!=NULL){
        printf("%d->", i->data);
        i=i->next;
    }
    printf("\n");
}

//Doubly_Linked_List_Traversal (Backward)
void printReverse(){
    struct student *i=start;
    if(i==NULL){
        printf("List is empty.\n");
        return;
    }
    while(i->next!=NULL){
        i=i->next;
    }
    printf("Reverse Traversal: ");
    while(i!=NULL){
        printf("%d->", i->data);
        i=i->prev;
    }
    printf("\n");
}

//Doubly_Linked_List_Insertion (Beginning)
void insertBeginning(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the beginning: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(start==NULL){
        start=newnode;
    }
    else{
        newnode->next=start;
        start->prev=newnode;
        start=newnode;
    }
}

//Doubly_Linked_List_Insertion (End)
void insertEnd(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the end: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    if(start==NULL){
        start=newnode;
    }
    else{
        struct student *i=start;
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=newnode;
        newnode->prev=i;
    }
}

//Doubly_Linked_List_Insertion (Specific Position)
void insertAny(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in any position: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    int x;
    printf("Enter the data part after which you want to insert: ");
    scanf("%d", &x);
    struct student *i=start;
    if(i==NULL){
        start=newnode;
    }
    else{
        while(i!=NULL && i->data!=x){
            i=i->next;
        }
        if(i==NULL){
            printf("Node not found.\n");
            free(newnode);
            return;
        }
        newnode->next=i->next;
        newnode->prev=i;
        if(i->next!=NULL)
            i->next->prev=newnode;
        i->next=newnode;
    }
}

//Doubly_Linked_List_Deletion (Beginning)
void deleteBeginning(){
    printf("We are going to delete from the beginning!\n");
    if(start==NULL){
        printf("There are no elements in the Linked List.\n");
    }
    else{
        struct student *temp=start;
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
        free(temp);
    }
}

//Doubly_Linked_List_Deletion (End)
void deleteEnd(){
    printf("We are going to delete from the end!\n");
    if(start==NULL){
        printf("There are no elements in the Linked List.\n");
    }
    else if(start->next==NULL){
        free(start);
        start=NULL;
    }
    else{
        struct student *i=start;
        while(i->next!=NULL){
            i=i->next;
        }
        i->prev->next=NULL;
        free(i);
    }
}

//Doubly_Linked_List_Deletion (Specific Position)
void deleteAny(){
    printf("We are going to delete from any position!\n");
    int x;
    printf("Enter the data part of the node you want to delete: ");
    scanf("%d", &x);
    if(start==NULL){
        printf("There are no elements in the Linked List.\n");
        return;
    }

    struct student *i=start;
    while(i!=NULL && i->data!=x){
        i=i->next;
    }
    if(i==NULL){
        printf("Node not found.\n");
        return;
    }

    if(i==start){
        start=start->next;
        if(start!=NULL)
            start->prev=NULL;
    }
    else{
        if(i->prev!=NULL)
            i->prev->next=i->next;
        if(i->next!=NULL)
            i->next->prev=i->prev;
    }
    free(i);
}

//Doubly_Linked_List_Searching
void searchNode(){
    int key;
    printf("Enter the data value to search: ");
    scanf("%d", &key);
    struct student *i=start;
    int position=1;
    while(i!=NULL){
        if(i->data==key){
            printf("Node with data %d found at position %d.\n", key, position);
            return;
        }
        i=i->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", key);
}

//Doubly_Linked_List_Counting Nodes
void countNodes(){
    int count=0;
    struct student *i=start;
    while(i!=NULL){
        count++;
        i=i->next;
    }
    printf("Total number of nodes in the linked list: %d\n", count);
}

int main(){
    struct student *s1, *s2, *s3;
    s1=(struct student*)malloc(sizeof(struct student));
    s2=(struct student*)malloc(sizeof(struct student));
    s3=(struct student*)malloc(sizeof(struct student));

    s1->data=10;
    s1->prev=NULL;
    s1->next=s2;

    s2->data=20;
    s2->prev=s1;
    s2->next=s3;

    s3->data=30;
    s3->prev=s2;
    s3->next=NULL;

    start=s1;

    printDoublyLinkedList();
    insertBeginning();
    printDoublyLinkedList();
    insertEnd();
    printDoublyLinkedList();
    insertAny();
    printDoublyLinkedList();
    deleteBeginning();
    printDoublyLinkedList();
    deleteEnd();
    printDoublyLinkedList();
    deleteAny();
    printDoublyLinkedList();
    searchNode();
    countNodes();
    printReverse(); // Optional reverse traversal display
    return 0;
}