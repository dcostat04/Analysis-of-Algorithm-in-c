#include <stdio.h>
int main()
{
    int a[100], n, i, j,min,temp,c=0,s=0;

    printf("Enter number of elements\n");
    scanf("%d", &n);

    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
            scanf("%d", &a[i]);
    }
    for(i = 0; i < n - 1; i++)
    {
        min=i;
        for(j = i + 1; j < n; j++)
        {
            if(a[min] > a[j])
            {min=j;}
            c++;
        }

        if(min != i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
            s++;
        }
        printf("\nPass %d:",i);
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[j]);
        }
    }
printf("\nArray after sorting is:\n");
for(i = 0; i < n; i++)
    printf("  %d\n", a[i]);

printf("Number of comparisons:%d \n",c);
printf("Number of swaps:%d \n",s);
return 0;
}
