//Adjacency list representation of weighted undirected graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int val;				//for weighted graph
	struct node *next;
};

struct node* getnode(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->val=x;
	temp->next=NULL;
	return temp;
}

void add(struct node **head,int x)
{
	struct node *temp=getnode(x);
	if(*head==NULL)
	{
	    *head=temp;
	    return;
	}
	struct node *p=*head;
	while(p->next!=NULL)
	    p=p->next;
	p->next=temp;
}

void enqueue(struct node **f,struct node **r,int x)
{
	struct node *temp=getnode(x);
	if(*f==NULL)
	{
		*f=*r=temp;
		return;
	}
	(*r)->next=temp;
	*r=temp;
}
void dequeue(struct node **f,struct node **r)
{
	if(*f==NULL)	return;
	struct node *temp=*f;
	if(*f==*r)
	{
		*f=*r=NULL;
	}
	else
	    *f=(*f)->next;
 	free(temp);
}
void BFT(struct node *head[],int v,int s)	//Breadth first traversal
{
	int i,x;
	bool visited[v+1];
	for(i=0;i<=v;i++)
		visited[i]=false;

	struct node *front=NULL,*rear=NULL,*j=NULL;
	visited[s]=true;
	enqueue(&front,&rear,s);
	while(front!=NULL)
	{
		x=front->val;
		printf("%d ",x);

		for(j=head[x];j!=NULL;j=j->next)
		{
			if(!visited[j->val])
			{
				visited[j->val]=true;
				enqueue(&front,&rear,j->val);
			}
		}
		dequeue(&front,&rear);
	}
	for(i=1;i<=v;i++)
	{
		if(!visited[i])
			printf("%d ",i);
	}
	printf("\n");
}

void DF_Print(struct node **head,int v,bool a[])
{
	a[v]=true;
	printf("%d ",v);
	struct node *i;
	for(i=head[v];i!=NULL;i=i->next)
	{
		if(!a[i->val])
			DF_Print(head,i->val,a);
	}
}

void DFT(struct node *head[],int v,int s)	//Depth first traversal
{
	int i;
	bool visited[v+1];
	for(i=0;i<=v;i++)
		visited[i]=false;
	DF_Print(head,s,visited);
}

void show_list(struct node *head[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d - ",i);
		struct node *temp;
		for(temp=head[i];temp!=NULL;temp=temp->next)
		{
		    printf("%d ",temp->val);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int v,e,x,y,i,s;
	scanf("%d%d",&v,&e);	// 'v' is no. of vertices & e is no. of edges
	struct node *head[v+1];
	for(i=0;i<=v;i++)
		head[i]=NULL;
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);		// 'w' is weight of each edge
		add(&head[x],y);
		add(&head[y],x);
	}
	scanf("%d",&s);
	DFT(head,v,s);
	return 0;
}
