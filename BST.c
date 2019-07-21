//while inorder traversal it gives the next element or say successor of given element

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
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

struct node search(struct node *root,int x)
{
	if(root==NULL)
		return 0;
	if(root->val==x)
		return 1;
	else if(x<=root->val)
		return search(root->left,x);
	else
		return search(root->right,x);
}
struct node *find_Min(struct node *root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
int inorder_successor(struct node *root,int x,int a)
{
	if(root==NULL)	return -1;
	return inorder_successor(root->left,x,a);
	if(a==x)
		return root->val;
	else
		a=root->val;
	return inorder_successor(root->right,x,a);
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
	inorder_print(root);
	printf("\n%d\n",inorder_successor(root,x,-1));
	return 0;
}
