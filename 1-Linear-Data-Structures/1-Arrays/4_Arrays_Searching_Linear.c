//Arrays_Serching (Linear)

/*Array Searching refers to locating the position of a specific element (key) within an array.
There are two primary searching techniques:

# Linear Search – Sequentially checks each element.

# Binary Search – Works on sorted arrays and follows a divide-and-conquer approach.*/

#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array according to its size: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the value that you want to search: ");
    scanf("%d", &x);
    int position=-1;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            position=i;
            break;
        }
    }
    if(position!=-1){
        printf("The position of the value %d is %d in the array.\n", x, position);
    }
    else{
        printf("The value %d is not available in the array.\n", x);
    }
    return 0;
}