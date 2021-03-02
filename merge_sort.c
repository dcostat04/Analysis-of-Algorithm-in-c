#include<stdio.h>
#include<conio.h>

int m=1;
int s;

void merge(int ar[],int p,int q,int r )
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;


    int L[n1],R[n2];

    for(i=0;i<n1;i++)
    {
     L[i]=ar[p+i];
    }
    printf("subarray 1:");
    for (i=0; i<n1; i++)
        printf("%d ", L[i]);
         printf("\n");
    for(j=0;j<n2;j++)
    {
        R[j]=ar[q+j+1];
    }
    printf("subarray 2:");
    for (i=0; i<n2; i++)
        printf("%d ", R[i]);
         printf("\n");


    i=0;
    j=0;
    k=p;

   while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            ar[k]=L[i];
            i++;
        }
        else
        {
            ar[k]=R[j];
            j++;
        }
        k++;
    }

       while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }

    printf("MERGE %d:",m);
    for (i=p; i<r+1; i++)
        printf("%d ", ar[i]);
         printf("\n");

    m++;
    }

void merge_sort(int ar[],int p,int r)
{

    int i;
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(ar,p,q);
        merge_sort(ar,q+1,r);

        merge(ar,p,q,r);

    }
}

void print(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int i;
    printf("Enter number of elements\n");
    scanf("%d",&s);
    int ar[s];
    printf("Enter %d integers\n", s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&ar[i]);
    }
    merge_sort(ar,0,s-1);

    printf("\nThe sorted array is: \n");
    print(ar,s);
    return 0;
}
