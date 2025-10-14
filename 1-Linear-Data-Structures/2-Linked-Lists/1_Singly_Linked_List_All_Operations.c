//Singly_Linked_List_All_Operations

#include<stdio.h>
#include<stdlib.h>//Be careful

struct student {
    int data;
    struct student *next;
};

struct student *start=NULL;

//Singly_Linked_List_Traversal
void printSinglyLinkedList(){
    struct student *i=start;
    while(i!=NULL){
        printf("%d->", i->data);
        i=i->next;//Be careful
    }
    printf("\n");//Be careful
}

//Singly_Linked_List_Insertion (Beginning)
void insertBeginning(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the beginning: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    newnode->next=start;
    start=newnode;
}

//Singly_Linked_List_Insertion (End)
void insertEnd(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the end: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    struct student *i=start;
    if(i==NULL){
        start=newnode;
    }
    else{
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=newnode;
    }
}

//Singly_Linked_List_Insertion (Specific Position)
void insertAny(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in any position: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    int x;
    printf("Enter the data part after which you want to insert: ");
    scanf("%d", &x);
    struct student *i=start;
    if(i==NULL){
        start=newnode;
    }
    else{
        while(i->data!=x){
            i=i->next;
        }
        newnode->next=i->next;
        i->next=newnode;
    }
}

//Singly_Linked_List_Deletion (Beginning)
void deleteBeginning(){
    printf("We are going to delete from the beginnning!\n");
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
    }
    else{
        struct student *temp=start;
        start=temp->next;
        free(temp);
    }
}

//Singly_Linked_List_Deletion (End)
void deleteEnd(){
    printf("We are going to delete from the end!\n");
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
    }
    else if(start->next==NULL){
        start=NULL;
    }
    else{
        struct student *i=start;
        while(i->next->next!=NULL){
            i=i->next;
        }
        i->next=NULL;
    }
}

//Singly_Linked_List_Deletion (Specific Position)
void deleteAny(){
    printf("We are going to delete from any position!\n");
    int x;
    printf("Enter the data part of the node you want to delete: ");
    scanf("%d", &x);
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
    }
    else if(start->data==x){
        start=start->next;
    }
    else{
        struct student *i=start;
        while(i->next->data!=x){
            i=i->next;
        }
        i->next=i->next->next;
    }
}

//Singly_Linked_List_Searching
void searchNode(){
    int key;
    printf("Enter the data value to search: ");
    scanf("%d", &key);
    struct student *i=start;//Begin from the start of the list
    int position=1;//To keep track of node position
    while (i!=NULL){
        if (i->data==key){
            printf("Node with data %d found at position %d.\n", key, position);
            return;//Exit after finding the node
        }
        i=i->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", key);
}

//Singly_Linked_List_Counting Nodes
void countNodes(){
    int count=0;
    struct student *i=start;
    while (i!=NULL){
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
    s1->next=s2;
    s2->data=20;
    s2->next=s3;
    s3->data=30;
    s3->next=NULL;
    start=s1;
    printSinglyLinkedList();
    insertBeginning();
    printSinglyLinkedList();
    insertEnd();
    printSinglyLinkedList();
    insertAny();
    printSinglyLinkedList();
    deleteBeginning();
    printSinglyLinkedList();
    deleteEnd();
    printSinglyLinkedList();
    deleteAny();
    printSinglyLinkedList();
    searchNode();
    countNodes();
    return 0;
}