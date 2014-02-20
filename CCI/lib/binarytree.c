

#include <stdio.h>
#include <stdlib.h>

typedef struct _tree_node
{

    struct _tree_node *left;
    int data;
    struct _tree_node *right;
}tree_node;


tree_node* newNode(int data)
{
	tree_node *new_node=calloc(1,sizeof(tree_node));
	new_node->data=data;
	new_node->left=NULL;
	new_node->right=NULL;

	return new_node;
}

// for Binary Search Tree
tree_node* insertNode_r(tree_node* root,int data)
{
	if(root==NULL)
		return newNode(data);
	else
	{
		if(data <= root->data)
			root->left=insertNode_r(root->left,data);
		else
			root->right=insertNode_r(root->right,data);

		return root;

	}

}


//Min value in a binary search tree
int minValue_r(tree_node *root)
{
	if(root->left!=NULL)
	{	

		return minValue_r(root->left);

	}
	else
		return (root->data);


}

int minValue_i(tree_node *root)
{
	while(root->left!=NULL)
	{

		root=root->left;


	}
	return root->data;
}




//Count the size of tree
int size_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		return 1+size_r(root->left)+size_r(root->right);

	}
	else
		return 0;
}

int maxDepth_r(tree_node *root)
{

	int hleft=0,hright=0;

	if(root!=NULL)
	{

		
		hleft=maxDepth_r(root->left);
		hright=maxDepth_r(root->right);
		if(hleft >= hright) 
			return hleft+1;
		else
			return hright+1;


	}
	else
		return 0;
}


//Traversals

//DFS

//Preorder
void preorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		printf("%d -> ", root->data);
		preorder_r(root->left);
		preorder_r(root->right);

	}

}

void inorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		preorder_r(root->left);
		printf("%d -> ", root->data);
		preorder_r(root->right);

	}

}

void inorder_test(tree_node *root)
{
	if(root!=NULL)
	{
		
		preorder_r(root->left);
		printf("%d -> ", root->data);
		if(root->left)
			printf("l:%d -> ", (root->left)->data);
		if(root->right)
			printf("r:%d -> ", (root->right)->data);

		printf("\n");
		preorder_r(root->right);

	}

}


void postorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		preorder_r(root->left);
		preorder_r(root->right);
		printf("%d -> ", root->data);

	}

}

//Recusrive Lookup for a binary search tree
int lookup_r(tree_node *root,int target)
{

	if(root == NULL)		//1. Base case
		return 0;
	else
	{
		if(root->data==target)		//2. Data found
		{
			printf("Found data\n");
			return 1;


		}
		else					//3. Recurse down tree
		{
			if(target < root->data) 
				return lookup_r(root->left,target);
			else
				return lookup_r(root->right,target);


		}

	}

}


void freeTree(tree_node *root)
{
	if(root!=NULL)
	{
		
		freeTree(root->left);
		free(root->left);
		printf("%d", root->data);
		freeTree(root->right);

	}

}