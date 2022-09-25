#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node* getnode()
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	return temp;
}

void reverse_list(struct node **head)		//list reversal using loop
{
	struct node *curr,*prev,*forw;
	prev=NULL;
	curr=*head;
	while(curr!=NULL)
	{
		forw=curr->next;
		curr->next=prev;
		prev=curr;
		curr=forw;
	}
	*head=prev;
}

void reverse_list_rec(struct node **head,struct node *p)		//list reversal using recursion
{
	if(p->next==NULL)
	{
		*head = p;
		return;
	}
	reverse_list_rec(head,p->next);
	struct node *q=p->next;
	q->next=p;
	p->next=NULL;
}

void print(struct node *p)
{
	if(p==NULL)
		return;
	printf("%d ",p->val);
	print(p->next);
}

void revprint(struct node *p)		// print the list in reverse order and not reverses the list
{
	if(p==NULL)
		return;
	print(p->next);
	printf("%d ",p->val);
}

int main()
{
	int n,i;
	scanf("%d",&n);

	struct node *head=getnode();
	struct node *temp=head;
	for(i=0;i<n-1;i++)
	{
		scanf("%d",&(temp->val));
		temp->next=getnode();
		temp=temp->next;
	}
	scanf("%d",&(temp->val));
	temp->next==NULL;

	print(head);
	reverse_list(&head);
	print(head);
	return 0;
}
