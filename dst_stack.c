#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
};

struct node* getnode()
{
	struct node *temp=getnode();
	temp->next=NULL;
	return temp;
}

void push(struct node **top,int x)
{
	struct node *temp=getnode();
	temp->val=x;

	temp->next=*top;
	*top=temp;
}

void pop(struct node **top)
{
	if(*top==NULL)
		return;
	struct node *temp=*top;
	*top=temp->next;
	free(temp);
}

int main()
{
	struct node *top=NULL;
	return 0;
}