#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[10][10];
int n,i,j,k;
int d[10],parent[10];
void printArray()
{
    int i;
    printf("Intial Array");
    printf("\nVertex\tDistance\tParent");
    for (i = 1; i <= n; i++) {
        if(parent[i]==0){
            printf("\n%c\t%d\t\tNULL ",i+64,d[i]);
        }
        else
            printf("\n%c\t%d\t\t%c ",i+64,d[i],parent[i]+64);
    }
    printf("\n");
}
int returnparent(int a){

    return parent[a];
}
void shortestpath(){
    printf ("\n Shortest Path\n");
    printf("\nPair\tDistance\tPaths");
    for ( i = 2; i <= n; i++)
    {
        int arr[10],count=1;

        int current = i;
        int parentofcurrent = returnparent(current);
        int dis=0;
        arr[1]=current;
        while(current!=1){

            count++;
            arr[count]=parentofcurrent;
            dis= dis + a[parentofcurrent][current];
            current=parentofcurrent;
            parentofcurrent=returnparent(current);
        }
        printf("\n%c->%c",65,i+64);
        printf("\t%d\t\t",dis);
        for (j = count; j >= 1; j--)
        {
            if(j==1)
            printf("%c",arr[j]+64);
            else
            printf("%c->",arr[j]+64);
            arr[j]=0;
        }
    }

}
int bellmanford(){
    for ( i = 1; i <= n; i++)
    {

        d[i]=9999;
        parent[i]=0;
    }
    d[1]=0;

    for ( i = 1; i < n; i++)
    {
        for ( k = 1; k <= n; k++)
        {
            for (j = 1; j <= n; j++)
            {

                if(a[k][j]!=0){
                    if (d[j]>(d[k]+a[k][j]))
                    {
                        d[j]=d[k]+a[k][j];
                        parent[j]=k;
                    }
                    // printArray();
                }
            }
        }
    }

        for ( k = 1; k <= n; k++)
        {
            for ( j = 1; j <= n; j++)
            {
                if(a[k][j]!=0){
                    if (d[j]>(d[k]+a[k][j]))
                    {
                        return 0;
                    }
                }
            }
        }
        return 1;
}
int main(){
    printf("\nEnter no of  vertices : ");
    scanf("%d",&n);
    printf("\nEnter adjacency matrix :\n");
    for ( i = 1; i <= n; i++)
    {

        for ( j = 1; j <= n; j++)
        {

            scanf("%d",&a[i][j]);
        }

    }
    for ( i = 1; i <= n; i++)
    {

        for ( j = 1; j <= n; j++)
        {

            if(a[i][j]==1){
                int temp;
                printf("\nweight  %d-%d : ",i,j);
                scanf("%d",&temp);
                a[i][j]=temp;
            }
            else
                continue;
        }

    }
    int result = bellmanford();
    if (result==1)
    {
        printArray();
        shortestpath();
    }
    else{
        printf("\nBellman Ford not working ");
    }
    return 0;
}
