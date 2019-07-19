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

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int height(struct node *root)
{
    if(root==NULL)
        return -1;
    return 1+max(height(root->left),height(root->right));
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
	printf("\n%d\n",height(root));
	return 0;
}