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

void insert_head(struct node **head,int x)
{
	struct node *temp=getnode();
	temp->val=x;

	temp->next=*head;
	*head=temp;
}

void insert(struct node **head,int x,int k)
{
	if(k==1)
	{
		insert_head(head,x);
		return;
	}
	struct node *temp=getnode();
	temp->val=x;

	struct node *p=*head;
	for(int i=1;i<k-1 && p->next!=NULL;i++)
		p=p->next;

	temp->next=p->next;//insert after pointer p
	p->next=temp;
}

void delete_head(struct node **head)
{
	if(*head==NULL)
		return;

	struct node *temp=*head;
	*head=temp->next;
	free(temp);
}

void delete(struct node **head,int k)
{
	if(*head==NULL)
		return;
	if(k==1)
	{
		delete_head(head);
		return;
	}

	struct node *p=*head;
	for(int i=1;i<k-1 && (p->next)->next!=NULL;i++)
		p=p->next;

	struct node *temp=p->next;	//delete after pointer p
	p->next=temp->next;
	free(temp);
}

int count(struct node *p)
{
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

void print(struct node *p)	//print linked list
{
	while(p!=NULL)
	{
		printf("%d ",p->val);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	int n,i;
	struct node *head=NULL,*temp=NULL;
	scanf("%d",&n);

	//taking input and creating linked list simultaneously
	head=getnode();
	temp=head;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&(temp->val));
		temp->next=getnode();
		temp=temp->next;
	}
	scanf("%d",&(temp->val));
	temp->next=NULL;

	print(head);
	return 0;
}