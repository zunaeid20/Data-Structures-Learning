//Arrays_Traversal

/*Array Traversal refers to the process of accessing each element of an array exactly once, 
usually to display, modify, or use the elements for computation.

# The traversal is generally done using loops such as for, while, or do-while.

# The index starts from 0 and goes up to n-1 where n is the size of the array.*/

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
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
