//Linked list implementation of queue
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
};

struct node* getnode()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

void enqueue(struct node **f,struct node **r,int x)
{
	struct node *temp=getnode();
	temp->val=x;
	if(*f==NULL)
		*f=*r=temp;
	else
	{
		(*r)->next=temp;
		*r=temp;
	}
}

void dequeue(struct node **f,struct node **r)
{
	if(*f==NULL)
		return;
	struct node *temp=*f;
	if(*f==*r)
	{
		*f=*r=NULL;
	}
	else
	{
		*f=temp->next;
	}
	free(temp);
}

int main()
{
	struct node *front=NULL,*rear=NULL;
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enqueue(&front,&rear,x);
	}
	return 0;
}
