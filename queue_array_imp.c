#include <stdio.h>
#define MaxInt 1000 


int front=rear=-1;
int a[MaxInt];

int isEmpty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}

void enqueue(int x)
{
	if(rear==MaxInt-1)
	{
		printf("Queue overflow\n");
		return;
	}
	if(rear==-1)
		front++;
	a[++rear]=x;
}

void dequeue()
{
	if(front==-1)
	{
		printf("Queue underflow\n");
		return;
	}
	if(front==rear)
		front=rear=-1;
	else
		front++;
}

int Front()
{
	if(front!=-1)
		return a[front];
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