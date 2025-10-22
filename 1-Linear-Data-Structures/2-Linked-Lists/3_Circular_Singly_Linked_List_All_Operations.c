//Circular_Singly_Linked_List_All_Operations

#include<stdio.h>
#include<stdlib.h>//Be careful

struct student {
    int data;
    struct student *next;
};

struct student *start=NULL;

//Circular_Singly_Linked_List_Traversal
void printCircularSinglyLinkedList(){
    if(start==NULL){
        printf("List is empty.\n");
        return;
    }
    struct student *i=start;
    do{
        printf("%d->", i->data);
        i=i->next;
    } while(i!=start);
    printf("(back to start)\n");
}

//Circular_Singly_Linked_List_Insertion (Beginning)
void insertBeginning(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the beginning: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;

    if(start==NULL){
        start=newnode;
        newnode->next=start;
    }
    else{
        struct student *i=start;
        while(i->next!=start){
            i=i->next;
        }
        newnode->next=start;
        i->next=newnode;
        start=newnode;
    }
}

//Circular_Singly_Linked_List_Insertion (End)
void insertEnd(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in the end: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;

    if(start==NULL){
        start=newnode;
        newnode->next=start;
    }
    else{
        struct student *i=start;
        while(i->next!=start){
            i=i->next;
        }
        i->next=newnode;
        newnode->next=start;
    }
}

//Circular_Singly_Linked_List_Insertion (Specific Position)
void insertAny(){
    struct student *newnode;
    int value;
    printf("Enter the data part of the newnode to insert in any position: ");
    scanf("%d", &value);
    newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=value;

    int x;
    printf("Enter the data part after which you want to insert: ");
    scanf("%d", &x);

    if(start==NULL){
        start=newnode;
        newnode->next=start;
        return;
    }

    struct student *i=start;
    do{
        if(i->data==x){
            newnode->next=i->next;
            i->next=newnode;
            return;
        }
        i=i->next;
    } while(i!=start);

    printf("Node not found.\n");
    free(newnode);
}

//Circular_Singly_Linked_List_Deletion (Beginning)
void deleteBeginning(){
    printf("We are going to delete from the beginning!\n");
    if(start==NULL){
        printf("There is no element in the Linked List.\n");
    }
    else if(start->next==start){
        free(start);
        start=NULL;
    }
    else{
        struct student *i=start;
        while(i->next!=start){
            i=i->next;
        }
        struct student *temp=start;
        start=start->next;
        i->next=start;
        free(temp);
    }
}

//Circular_Singly_Linked_List_Deletion (End)
void deleteEnd(){
    printf("We are going to delete from the end!\n");
    if(start==NULL){
        printf("There is no element in the Linked List.\n");
    }
    else if(start->next==start){
        free(start);
        start=NULL;
    }
    else{
        struct student *i=start;
        while(i->next->next!=start){
            i=i->next;
        }
        free(i->next);
        i->next=start;
    }
}

//Circular_Singly_Linked_List_Deletion (Specific Position)
void deleteAny(){
    printf("We are going to delete from any position!\n");
    if(start==NULL){
        printf("There is no element in the Linked List.\n");
        return;
    }

    int x;
    printf("Enter the data part of the node you want to delete: ");
    scanf("%d", &x);

    struct student *i=start, *temp=NULL;

    if(start->data==x){
        deleteBeginning();
        return;
    }

    do{
        if(i->next->data==x){
            temp=i->next;
            i->next=temp->next;
            free(temp);
            return;
        }
        i=i->next;
    } while(i!=start);

    printf("Node not found.\n");
}

//Circular_Singly_Linked_List_Searching
void searchNode(){
    if(start==NULL){
        printf("List is empty.\n");
        return;
    }
    int key;
    printf("Enter the data value to search: ");
    scanf("%d", &key);
    struct student *i=start;
    int position=1;
    do{
        if(i->data==key){
            printf("Node with data %d found at position %d.\n", key, position);
            return;
        }
        i=i->next;
        position++;
    } while(i!=start);
    printf("Node with data %d not found in the list.\n", key);
}

//Circular_Singly_Linked_List_Counting Nodes
void countNodes(){
    if(start==NULL){
        printf("Total number of nodes: 0\n");
        return;
    }
    int count=0;
    struct student *i=start;
    do{
        count++;
        i=i->next;
    } while(i!=start);
    printf("Total number of nodes in the linked list: %d\n", count);
}

int main(){
    struct student *s1, *s2, *s3;
    s1=(struct student*)malloc(sizeof(struct student));
    s2=(struct student*)malloc(sizeof(struct student));
    s3=(struct student*)malloc(sizeof(struct student));
    s1->data=10;
    s2->data=20;
    s3->data=30;
    s1->next=s2;
    s2->next=s3;
    s3->next=s1; // Makes it circular
    start=s1;
    printCircularSinglyLinkedList();
    insertBeginning();
    printCircularSinglyLinkedList();
    insertEnd();
    printCircularSinglyLinkedList();
    insertAny();
    printCircularSinglyLinkedList();
    deleteBeginning();
    printCircularSinglyLinkedList();
    deleteEnd();
    printCircularSinglyLinkedList();
    deleteAny();
    printCircularSinglyLinkedList();
    searchNode();
    countNodes();
    return 0;
}