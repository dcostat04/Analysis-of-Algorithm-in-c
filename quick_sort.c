#include <stdio.h>
#include <stdlib.h>
int call=0;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void display(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d \t",arr[i]);
}
int partition(int arr[],int p,int r){
        int x = arr[r];
        int i=p-1;
        int j;
        for(j=p;j<=r-1;j++)
            {
                if(arr[j]<x)
                {
                    i++;
                    swap(&arr[i],&arr[j]);
                    printf("\nSwapped array: \n");
                    display(arr,r+1);
                }
            }
        swap(&arr[i+1],&arr[r]);
        printf("\nPartition index: %d \t \n",i+1);
        return i+1;
}
void quick_sort(int arr[],int p,int r)
{
    printf("\nCall: %d \n",call);
    display(arr,r+1);
    call++;
    if(p<r)
        {
            int q = partition(arr,p,r);
            quick_sort(arr,p,q-1);
            quick_sort(arr,q+1,r);
        }
}
int main()
{
    int n, i;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int  arr[n];
    printf("Enter %d integers\n", n);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("\nThe sorted array is: \n");
    display(arr,n);
    printf("\nCalls to stack: %d",call);
}
