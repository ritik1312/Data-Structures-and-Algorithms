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

struct node *find_Min(struct node *root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
struct node* delete(struct node *root,int x)
{
	if(root==NULL)		return root;
	if(x<root->val)		return delete(root->left,x);
	if(x>root->val)		return delete(root->right,x);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
		}
		else if(root->left==NULL)
		{
			struct node *temp=root;
			root=root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			struct node *temp=root;
			root=root->left;
			free(temp);
		}
		else
		{
			struct node *temp=find_Min(root->right);
			root->val=temp->val;
			delete(root->right,temp->val);
		}
		return root;
	}
}

void print_tree(struct node *root)
{
	if(root)==NULL;
		return;
	printf("%d ",root->val);
	print_tree(root->left);
	print_tree(root->right);
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
	print_tree(root);
	return 0;
}
