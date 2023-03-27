#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Problem 84 of leetcode
int max (int [],int) ;
int main (){
    int n ;
    printf("How Many Num in array : ") ;
    scanf("%d",&n) ;
    int *Arr = malloc(sizeof(int)*n) ;
    for (size_t i = 0; i < n; i++)
        scanf("%d",&*(Arr+i)) ;
    printf("Maximum %d",max(Arr,n)) ;
}
int max (int arr[] , int n) {
    int max1 , max2=0;
    for (size_t i = 0; i < n; i++)
    {
        max1 = arr[i] ;
        for (size_t j = i+1; j < n; j++)
        {
            if (arr[i] <= arr[j])
                max1 +=arr[i] ;
            else 
            break;
        }
        if(max1 > max2)
        max2 = max1 ;
    }
    return max2 ;
}