//Linked list implementation of stack
//Stack is a type of linked list with restriction that element can be inserted and removed from one end only.
//It works on LIFO(Last In First Out)
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
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		push(&top,x);
	}
	return 0;
}
