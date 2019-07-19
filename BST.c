//These are types of traversal in binsry search tree
//1.Level order traversal
//2.Depth first traversal
//	a.preorder traversal
//	b.inorder traversal
//	c.postorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
	struct node *next;		// *next only used in queue in level order traversal
};

struct node *getnode(int x)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=temp->right=NULL;
	temp->val=x;
	return temp;
}

void insert(struct node **root,int x)
{
	if(*root==NULL)
		*root=getnode(x);
	else if(x<=(*root)->val)
		insert(&((*root)->left),x);
	else
		insert(&((*root)->right),x);
}

void inorder_print(struct node *root)
{
	if(root==NULL)
		return;
	inorder_print(root->left);
	printf("%d ",root->val);
	inorder_print(root->right);
}

void preorder_print(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->val);
	preorder_print(root->left);
	preorder_print(root->right);
}

void postorder_print(struct node *root)
{
	if(root==NULL)
		return;
	postorder_print(root->left);
	postorder_print(root->right);
	printf("%d ",root->val);
}


void enqueue(struct node **f,struct node **r,struct node *temp)		//queue operations for level order traversal
{
	if(*f==NULL)
	{
		*f=*r=temp;
		return;
	}
	*r->next=temp;
	*r=temp;
}
void dequeue(struct node **f,struct node **r)
{
	if(*f==NULL)	return;
	if(*f==*r)
	{
		*f=*r=NULL;
	}
	else
		*f=(*f)->next;
}
void Lev_Ord_Traversal(struct node *root)
{
	if(root==NULL)
		return;
	struct node *front=NULL,*rear=NULL;
	enqueue(&front,&rear,root);
	while(front!=NULL)
	{
		printf("%d ",front->val);
		if(front->left!=NULL)	enqueue(&front,&rear,front->left);
		if(front->right!=NULL)	enqueue(&front,&rear,front->right);
		dequeue(&front,&rear);
	}
	printf("\n");
}

int main()
{
	struct node *root=NULL;
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(&root,x);
	}
	Lev_Ord_print(root);
	inorder_print(root);
	return 0;
}
