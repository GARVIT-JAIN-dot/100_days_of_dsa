/* Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs. */

#include<stdio.h>
int main () {
     int n;
     printf("Enter the size of array:");
     scanf("%d",&n);
     int array[n];
     printf("Enter the element for array:");

    
     for (int i=0;i<n;i++){
        scanf("%d",&array[i]);
     }

     int min=array[0]+array[1];
     int num1=array[0];
     int num2=array[1];


     for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++)
        {
            int sum = array[i]+array[j];
            int abs_sum = sum;
            if(abs_sum<0) 
                abs_sum =-abs_sum;
        
            int abs_min=min;
            if(abs_min<0) {
                abs_min=-abs_min;
            }
            if (abs_sum<abs_min)
            {
                min=sum;
                num1=array[i];
                num2=array[j];
            }
        }
     }
    
     printf("pair of elements whose sum is closest to zero is:%d and %d",num1,num2);
     
     return 0;
    }