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

void reverse_list(struct node **head)
{
	if(*head==NULL)
		return;
	struct node *curr,*prev,*forw;
	prev=NULL;
	curr=*head;
	while(curr!=NULL)
	{
		forw=curr->next;
		curr->next=prev;
		curr=forw;
		prev=curr;
	}
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