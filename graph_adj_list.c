#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
	int weight;				//for weighted graph
};

struct node* getnode(int x,int w)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=x;
	temp->weight=w;
	temp->next=NULL;
	return temp;
}

void add(struct node **head,int x)
{
	struct node *temp=getnode(x);
	temp->next=*head;
	*head=temp;
}

void show_list(struct node *head[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d - ",i);
		struct node *temp=head[i];
		while(temp->next!=NULL)
			printf("%d ",temp->val);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int v,e,x,y,i,w;
	scanf("%d%d",&v,&e);	// 'v' is no. of vertices & e is no. of edges
	struct node *head[v+1];
	for(i=0;i<=v;i++)
		head[i]=NULL;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&w);		// 'w' is weight of each edge
		add(&head[x],y,w);
		add(&head[y],x,w);
	}

	show_list(head,v);
	return 0;
}