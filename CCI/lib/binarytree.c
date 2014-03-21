

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
	if(root==NULL) return -1;

	if(root->left!=NULL)
	{	

		return minValue_r(root->left);

	}
	else
		return (root->data);


}

int minValue_i(tree_node *root)
{
	if(root==NULL) return -1;

	while(root->left!=NULL)
	{

		root=root->left;


	}
	return root->data;
}


int maxValue_i(tree_node *root)
{
	if(root==NULL) return -1;
	
	while(root->right!=NULL)
	{
		root=root->right;
	}

	return (root->data);

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

//Preorder-> Root,Left,Right
void preorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		printf("%d -> ", root->data);
		preorder_r(root->left);
		preorder_r(root->right);

	}

}


//Inorder - Left,Root,Right
void inorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		inorder_r(root->left);
		printf("%d -> ", root->data);
		inorder_r(root->right);

	}

}

//Postorder Left,right,Root
void postorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		postorder_r(root->left);
		postorder_r(root->right);
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

//Print all path sums
void printPathSum(tree_node *root,int sum)
{
	sum+=root->data;
	if(root->left==NULL && root->right==NULL)
		printf("S=%d\n",sum);
	else
	{
		if(root->left!=NULL)
			printPathSum(root->left,sum);
		
		if(root->right!=NULL)
			printPathSum(root->right,sum);


	}

}

int hasPathSum(tree_node *root,int sum)
{
	if(root==NULL)
	{
		return !(sum); 
		// return (sum==0)?1:0;

		// if(sum==0)
		// {
		// 	// printf("Found\n");
		// 	return 1;
		// }
			
		// else
		// {
		// 	return 0;
		// }
			
	}
	else
	{
		sum-=root->data;
		return (hasPathSum(root->left,sum) || 
					hasPathSum(root->right,sum));



	}
}

void printArray(int path[],int pathLen)
{

	int i;
	for(i=0;i<pathLen;i++)
	{
		printf("%d -> ",path[i] );

	}
	printf("\n");

}


void printPaths(tree_node *root,int path[],int pathLen)
{
	
	if(root==NULL) return;

	path[pathLen++]=root->data;

	if(root->left==NULL && root->right==NULL)
	{
		printArray(path,pathLen);

	}
		
	else
	{
		
		// if(root->left!=NULL)
			printPaths(root->left,path,pathLen);
		// if(root->right!=NULL)
			printPaths(root->right,path,pathLen);		
	}


}

void mirror(tree_node *root)
{
	if(root==NULL)
		return;
	else
	{
		tree_node *tmp_node;
		tmp_node=root->left;
		root->left=root->right;
		root->right=tmp_node;
		mirror(root->left);
		mirror(root->right);

	}
}

void doubleTree(tree_node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		tree_node *dup_node=newNode(root->data);
		dup_node->left=root->left;
		root->left=dup_node;
		root->left->data=root->data;
		doubleTree(root->left->left);
		doubleTree(root->right);



	}


}


int sameTree(tree_node *a, tree_node *b)
{
	if(a==NULL && b==NULL)
		return 1;
	else if(a!=NULL & b!= NULL)
	{
	

		
		return ((a->data==b->data) && 
			sameTree(a->left,b->left) && 
			sameTree(a->right,b->right));



		// if(a->data==b->data)
		// {
		// 	return (sameTree(a->left,b->left) && sameTree(a->right,b->right));

		// }


	}
	

	return 0;




}


int countTrees(int numKeys)
{
	

	
}


int numOfPerms(int numOfNodes)
{
	if(numOfNodes == 1)
	{
		return 1;
	}
		
	numOfNodes--;

	return ((numOfPerms(numOfNodes)*(2*numOfNodes+2) *
		(2*numOfNodes+1))/((numOfNodes+1)*(numOfNodes+2)));


}



int isBST1(tree_node *root)
{

	


	
}

void freeTree(tree_node *root)
{
	
	if(root!=NULL)
	{
		
		freeTree(root->left);
		freeTree(root->right);
		free(root);


	}

}

