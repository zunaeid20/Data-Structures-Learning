//Arrays_Insertion

/*Array Insertion refers to adding a new element at a specific position within an existing array.
However, since arrays in C have fixed size, insertion doesn’t technically increase the array length — 
instead, we shift elements to make room for the new value.*/

#include<stdio.h>
int main(){
    int n;
    printf("Insert the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Insert the elements of the array according to its size: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x, y;
    printf("Provide an integer number to insert: ");
    scanf("%d", &x);
    printf("Provide the position where you want to insert: ");
    scanf("%d", &y);
    n=n+1; //We are increasing the size of the array by 1. Because we want to insert 1 element in the array.
    for(int i=n-1; i>y; i--){
        arr[i]=arr[i-1];
    }
    arr[y]=x;
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}