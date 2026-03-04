/* Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3 */

#include<stdio.h>
int main () {
     int n;
     printf("Enter the size of array:");
     scanf("%d",&n);
     int array [n];
     printf("Enter the element for array:");

    
     for (int i=0;i<n;i++){
        scanf("%d",&array[i]);
     }

     int k=0;
     printf("Enter the position of rotate array:");
     scanf("%d",&k);
    
     int r_array[n];

     for(int i=0;i<n;i++) {
         r_array[(i+k) % n]=array[i];      
     }
    
     printf("Rotated array is:");
     for(int i=0;i<n;i++){
         printf("%d ",r_array[i]);
     }
     
     return 0;
    }