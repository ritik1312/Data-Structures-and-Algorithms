#include <stdio.h>
#define MaxInt 1000 


int top=-1;
int a[MaxInt];

void push(int x)
{
	if(top==MaxInt-1)
	{
		printf("Stack overflow\n");
		return;
	}
	a[++top]=x;
}

void pop()
{
	if(top==-1)
	{
		printf("Stack underflow\n");
		return;
	}
	top--;
}

int Top()
{
	if(top!=-1)
		return a[top];
}

void print()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		push(x);
	}
	print();
	return 0;
}