

typedef struct _tree_node
{

    struct _tree_node *left;
    int data;
    struct _tree_node *right;
}tree_node;

// for Binary Search Tree
void insertNode(int data)
{






}

//Traversals

//DFS

//Preorder

void preorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		printf("%d", root->data);
		preorder_r(root->left);
		preorder_r(root->right);

	}

}

void inorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		preorder_r(root->left);
		printf("%d", root->data);
		preorder_r(root->right);

	}

}

void postorder_r(tree_node *root)
{
	if(root!=NULL)
	{
		
		preorder_r(root->left);
		preorder_r(root->right);
		printf("%d", root->data);

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