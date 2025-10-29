// Doubly_Linked_List_All_Operations

#include<stdio.h>
#include<stdlib.h> // Be careful

struct student{
    int data;
    struct student *next;
    struct student *prev; // Added for doubly linked list
};

struct student *start=NULL;

// Doubly_Linked_List_Traversal (Forward)
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

// Doubly_Linked_List_Traversal (Backward)
void printBackward(){
    printf("Backward Traversal: ");
    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        printf("List is empty.\n");
    }
    //----------(Part-2: Not empty linked list)
    else{
        //----------(Part-2.1: Traversing to the last node)
        while(i->next!=NULL){
            i=i->next;
        }
        //----------(Part-2.2: Printing backward)
        while(i!=NULL){
            printf("%d->", i->data);
            i=i->prev;
        }
    }
    printf("\n");
}

// Doubly_Linked_List_Insertion (Beginning)
void insertBeginning(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the beginning: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    
    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty linked list)
    else{ // 3 Changes
        newnode->next=i;
        i->prev=newnode;
        start=newnode;
    }
}

// Doubly_Linked_List_Insertion (End)
void insertEnd(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the end: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    struct student *i=start;
    //----------(Part-1: Empty linked list)
    if(i==NULL){
        start=newnode;
    }
    //----------(Part-2: Not empty linked list)
    else{ // 2 Changes
        while(i->next!=NULL){
            i=i->next;
        }
        newnode->prev=i;
        i->next=newnode;
    }
}

// Doubly_Linked_List_Insertion (Specific Position)
void insertAny(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in any position: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;

    //----------(Part-1: Getting the data part of the specific node from the user)
    int x;
    printf("Enter the data part of the node after which you want to insert: ");
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
        //----------(Part-3.3: Available in the end)
        else if(i->next==NULL){
            newnode->prev=i;
            i->next=newnode;
        }
        //----------(Part-3.4: Available in the beginning or middle)
        else if(i->next!=NULL){ // 4 changes
            newnode->next=i->next;
            i->next->prev=newnode;
            newnode->prev=i;
            i->next=newnode;
        }
    }
}

// Doubly_Linked_List_Deletion (Beginning)
void deleteBeginning(){
    printf("We are going to delete from the beginning!\n");
    //----------(Part-1: Empty linked list)
    if(start==NULL){
        printf("There are no elements in the Linked List.\n");
    }
    //----------(Part-2: Both one node and several nodes)
    else{
        struct student *temp=start;
        start=start->next;
        if(start!=NULL){
            start->prev=NULL;
        }
        free(temp);
    }
}

// Doubly_Linked_List_Deletion (End)
void deleteEnd(){
    printf("We are going to delete from the end!\n");
    //----------(Part-1: Empty linked list)
    if(start==NULL){
        printf("There are no elements in the Linked List.\n");
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

// Doubly_Linked_List_Deletion (Specific Position)
void deleteAny(){
    printf("We are going to delete from any position!\n");
    //----------(Part-1: Getting the data part of the specific node from the user)
    int x;
    printf("Enter the data part of the node you want to delete: ");
    scanf("%d", &x);
    struct student *i=start;
    //----------(Part-2: Empty linked list)
    if(i==NULL){
        printf("There are no elements in the Linked List.\n");
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
        }
        //----------(Part-3.3: Available in the beginning)
        else if(i==start){
            struct student *temp=start;
            //----------(Part-3.3.1: Beginning but there is only one node in the linked list (It can be assumed as end as well))
            start=start->next;
            //----------(Part-3.3.2: Beginning but there are more than one node in the linked list)
            if(start!=NULL){
                start->prev=NULL;
            }
            free(temp);
        }
        //----------(Part-3.4: Available in the end)
        else if(i->next==NULL){
            i->prev->next=NULL;
            free(i);
        }
        //----------(Part-3.5: Available in the middle)
        else{
            struct student *temp=i;
            i->prev->next=i->next;
            i->next->prev=i->prev;
            free(temp);
        }
    }
}

// Doubly_Linked_List_Searching
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

// Doubly_Linked_List_Counting Nodes
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
    
    printBackward();
    return 0;
}