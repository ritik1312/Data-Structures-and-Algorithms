//Adjacency list representation of weighted undirected graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int val;				//for weighted graph
	struct node *next;
};
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
	temp->next=*head;
	*head=temp;
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
	*f=(*f)->next;
	free(temp);
}
void BFS(struct node *head[],int v,int s)
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
	for(i=1;i<v;i++)
	{
		if(!visited[i])
			printf("%d ",i);
	}
}

void show_list(struct node *head[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d - ",i);
		struct node *temp;
		for(temp=head[i];temp->next!=NULL;temp=temp->next)
		{
		    printf("%d ",temp->val);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int v,e,x,y,i;
	scanf("%d%d",&v,&e);	// 'v' is no. of vertices & e is no. of edges
	struct node *head[v+1];
	for(i=0;i<=v;i++)
		head[i]=NULL;
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y);		// 'w' is weight of each edge
		add(&head[x],y);
		add(&head[y],x);
	}

	show_list(head,v);
	return 0;
}
