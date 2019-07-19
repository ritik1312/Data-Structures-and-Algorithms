//Binary Search Tree(BST) is a type of tree in which the value of each node is always greater than all the nodes in its left 
//subtree and smaller than all the nodes in its right subtree.
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

int search(struct node *root,int x)
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

int max_val(struct node *root)
{
	if(root==NULL)
		return -1;
	while(root->right!=NULL)
		root=root->right;
	return root->val;
}

int min_val(struct node *root)
{
	if(root==NULL)
		return -1;
	while(root->left!=NULL)
		root=root->left;
	return root->val;
}

int max(int a,int b)	// for height function
{
    if(a>b)	return a;
    else
        return b;
}
int height(struct node *root)
{
    if(root==NULL)
        return -1;
    return 1+max(height(root->left),height(root->right));
}

void print_leaves(struct node *root)
{
	if(root==NULL)
		return;
	print_leaves(root->left);
	if(root->left==NULL && root->right==NULL)
		printf("%d ",root->val);
	print_leaves(root->right);
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
	printf("\n%d\n",height(root));
	return 0;
}
