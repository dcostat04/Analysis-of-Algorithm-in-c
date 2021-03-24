#include<stdio.h>
#include<conio.h>
#define MAX 30
int G[MAX][MAX],parent[MAX];
int a,b,u,v,n,i,j,count=1,mindist,mincost=0;
int search(int i)
{
	while(parent[i])
	{
		i=parent[i];
	}
	return i;
}

int join(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}
void main()
{

    printf("Implementation of Kruskal's algorithm\n");
	printf("\nEnter number of nodes : ");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			scanf("%d",&G[i][j]);
			if(G[i][j]==0)
			{
				G[i][j]=999;
			}
		}
	}
	printf("\n minimum cost spanning tree \n");
	while(count<n)
	{
		mindist=999;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=n;++j)
			{
				if(G[i][j]<mindist)
				{
					mindist=G[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=search(u);
		v=search(v);
		if(join(u,v))
		{
			printf(" Edge %d:(%d,%d) Cost: %d\n",count++,a,b,mindist);
			mincost+=mindist;
		}
		G[a][b]=G[b][a]=999;
	}
	printf("\nMinimum cost = %d\n",mincost);
	getch();
}


