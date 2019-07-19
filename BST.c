// To check whether tree is balanced or not
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

int isSubtreeLesser(struct node *root,int x)
{
	if(root==NULL)	return 1;
	if(x>=root->val && isSubtreeLesser(root->left,x) && isSubtreeLesser(root->right,x))
		return 1;
	else
		return 0;
}
int isSubtreeGreater(struct node *root,int x)
{
	if(root==NULL)	return 1;
	if(x<=root->val && isSubtreeGreater(root->left,x) && isSubtreeGreater(root->right,x))
		return 1;
	else
		return 0;
}
int isBST(struct node *root)
{
	if(root==NULL)	return 1;
	if(isSubtreeLesser(root->left,root->val) && isSubtreeGreater(root->right,root->val)
	 && isBST(root->left) && isBST(root->right))
		return 1;
	else
		return 0;
}

int isBST_faster(struct node *root,int min,int max)	   //min and max are initially -INF and +INF respectively
{
	if(root==NULL)	return 1;
	if(root->val<=min && root->val>=max 
		&& isBST(root->left,min,root->val) && isBST(root->right,root->val,max))
		return 1;
	else
		return 0;
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
	return 0;
}
