// adjacency matrix of weighted graph
#include <stdio.h>
#include <math.h>

void show_matrix(int *a,int v)
{
	int i,j;
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			printf("%d ",*((a+i*v)+j));
		}
		printf("\n");
	}
}

int main()
{
	int v,e,x,y,i,j,w;
	scanf("%d%d",&v,&e);
	int a[v][v];
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
			a[i][j]=-1;
	}
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y,&w);
		a[x-1][y-1]=w;
		a[y-1][x-1]=w;
	}
	show_matrix((int*)a,v);
	return 0;
}