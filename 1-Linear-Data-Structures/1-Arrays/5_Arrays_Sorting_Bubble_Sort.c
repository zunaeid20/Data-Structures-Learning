//Arrays_Sorting (Bubble Sort)

/*Array Sorting refers to arranging elements of an array in a specific order:

# Ascending order (smallest → largest)

# Descending order (largest → smallest)


Common sorting algorithms for learning purposes:

# Bubble Sort – Simple, compares adjacent elements and swaps them.

# Selection Sort – Finds the minimum (or maximum) and places it in the correct position.

# Insertion Sort – Builds a sorted portion one element at a time.*/

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
    int temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){/*Condition can be changed for optimization by: j<n-1-i.
                                    Because when one of the largest element is moved to the last we don't need to check it again.*/
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    return 0;
}