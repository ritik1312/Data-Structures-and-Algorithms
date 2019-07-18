#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
	struct node *prev;
};

struct node* getnode()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void print(struct node *p)
{
	while(p!=NULL)
	{
		printf("%d ",p->val);
		p=p->next;
	}
	printf("\n");
}

void revprint(struct node *p)
{
	if(p==NULL)
		return;
	while(p->next!=NULL)
		p=p->next;
	while(p!=NULL)
	{
		printf("%d ",p->val);
		p=p->prev;
	}
	printf("\n");
}

void insertAtHead(struct node **head,int x)
{
	struct node *temp=getnode();
	temp->val=x;

	if(*head==NULL)
	{
		*head=temp;
		return;
	}

	temp->next=*head;
	(*head)->prev=temp;
	*head=temp;
}

void reverse(struct node **head)
{
	struct node *p=*head,*temp;
	while(p!=NULL)
	{
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		*head=p;
		p=temp;
	}
}

int main()
{
	int n,i;
	scanf("%d",&n);

	struct node *temp,*head=getnode();
	temp=head;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&(temp->val));
		temp->next=getnode();
		(temp->next)->prev=temp;
		temp=temp->next;
	}
	scanf("%d",&(temp->val));
	return 0;
}