/* Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1 */

#include<stdio.h>
int main () {
     int n;
     printf("Enter the size of array:");
     scanf("%d",&n);
     int array [n];
     printf("Enter the element for matrix:");

    
     for (int i=0;i<n;i++){
        scanf("%d",&array[i]);
     }
    
     int min = array[0];
     int max = array[0];

     for (int i=0;i<n;i++){
        if (array[i] > max){
             max = array[i];
        }

        if (array[i] < min){
             min = array[i];
        }
     }

     printf("from array\nmaximum:%d\nminimum:%d",max,min);
     
     return 0;
    }