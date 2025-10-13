//Arrays_Deletion

/*Array Deletion refers to the removal of an element from a specific position in the array.
Since arrays are static structures in C (fixed size), deletion doesn’t shrink the array’s allocated memory — 
it simply shifts elements leftward to fill the gap created by the removed element.*/

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
    printf("Enter the value you want to delete: ");
    scanf("%d", &x);
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            for(int j=i; j<n-1; j++){
                arr[j]=arr[j+1];
            }
            n--;
        }
    }
    for(int i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}