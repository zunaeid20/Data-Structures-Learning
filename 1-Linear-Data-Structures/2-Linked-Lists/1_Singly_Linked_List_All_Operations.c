// Singly_Linked_List_All_Operations

#include<stdio.h>
#include<stdlib.h> // Be careful

struct student{
    int data;
    struct student *next;
};

struct student *start=NULL;

// Singly_Linked_List_Traversal
void printForward(){
    printf("Forward Traversal: ");
    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        printf("List is empty.\n");
    }
    //----------(Part-2: Not empty linked list)
    else{
        while(i!=NULL){
            printf("%d->", i->data);
            i=i->next;
        }
    }
    printf("\n");
}

// Singly_Linked_List_Insertion (Beginning)
void insertBeginning(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the beginning: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty linked list)
    else{ // 2 Changes
        newnode->next=i;
        start=newnode;
    }
}

// Singly_Linked_List_Insertion (End)
void insertEnd(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the end: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty linked list)
    else{ // 1 Change
        while(i->next!=NULL){
            i=i->next;
        }
        i->next=newnode;
    }
}

// Singly_Linked_List_Insertion (Specific Position)
void insertAny(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in any position: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;

    //----------(Part-1: Getting the data part of the specific node from the user)
    int x;
    printf("Enter the data part after which you want to insert: ");
    scanf("%d", &x);
    struct student *i=start;
    //----------(Part-2: Empty linked list)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-3: Not empty linked list)
    else{
        //----------(Part-3.1: Traversing the linked list and finding the specific node)
        while(i!=NULL && i->data!=x){
            i=i->next;
        }
        //----------(Part-3.2: The specific node is not available)
        if(i==NULL){
            printf("Node not found.\n");
            free(newnode);
        }
        //----------(Part-3.3: Available in the beginning or end or middle)
        else{ // 2 Changes
            newnode->next=i->next;
            i->next=newnode;
        }
    }
}

// Singly_Linked_List_Deletion (Beginning)
void deleteBeginning(){
    printf("We are going to delete from the beginnning!\n");
    //----------(Part-1: Empty linked list)
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
    }
    //----------(Part-2: Both one node and several nodes)
    else{
        struct student *temp=start;
        start=start->next;
        free(temp);
    }
}

// Singly_Linked_List_Deletion (End)
void deleteEnd(){
    printf("We are going to delete from the end!\n");
    //----------(Part-1: Empty linked list)
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
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

// Singly_Linked_List_Deletion (Specific Position)
void deleteAny(){
    printf("We are going to delete from any position!\n");
    //----------(Part-1: Getting the data part of the specific node from the user)
    int x;
    printf("Enter the data part of the node you want to delete: ");
    scanf("%d", &x);
    //----------(Part-2: Empty linked list)
    if(start==NULL){
        printf("There is no elements in the Linked List.\n");
    }
    //----------(Part-3: Not empty linked list)
    else{
        struct student *i=start;
        //----------(Part-3.1: Available in the beginning)
        if(i->data==x){
            struct student *temp=start;
            start=start->next;
            free(temp);
        }
        //----------(Part-3.2: Available in the end or middle)
        else{
            while(i->next!=NULL && i->next->data!=x){
                i=i->next;
            }
            struct student *temp=i->next;
            i->next=i->next->next;
            free(temp);
        }
    }
}

// Singly_Linked_List_Searching
void searchNode(){
    int key;
    printf("Enter the data value to search: ");
    scanf("%d", &key);
    struct student *i=start; // Begin from the start of the list
    int position=1; // To keep track of node position
    while (i!=NULL){
        if (i->data==key){
            printf("Node with data %d found at position %d.\n", key, position);
            return; // Exit after finding the node
        }
        i=i->next;
        position++;
    }
    printf("Node with data %d not found in the list.\n", key);
}

// Singly_Linked_List_Counting Nodes
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
    
    printForward();

    insertBeginning();
    printForward();

    insertEnd();
    printForward();

    insertAny();
    printForward();

    deleteBeginning();
    printForward();

    deleteEnd();
    printForward();

    deleteAny();
    printForward();

    searchNode();

    countNodes();

    return 0;
}