/*
Binary tree tests


*/


#include "../lib/binarytree.c"

int main(void)
{


	tree_node *root=NULL;
	tree_node *root1=NULL;
	int path[100];

	
	root=insertNode_r(root,7);
	root=insertNode_r(root,2);
	root=insertNode_r(root,3);
	root=insertNode_r(root,1);
	root=insertNode_r(root,11);

	root1=insertNode_r(root1,7);
	root1=insertNode_r(root1,2);
	root1=insertNode_r(root1,3);
	root1=insertNode_r(root1,1);
	root1=insertNode_r(root1,11);
	root1=insertNode_r(root1,11);
	inorder_r(root);
	printf("\n");
	inorder_r(root1);
	printf("\n");
	

	printf("\n%d\t%d\t%d\n",size_r(root),
		maxDepth_r(root),minValue_i(root));

	printPathSum(root,0);

	
	
	printf("%s\n",sameTree(root,root1)?"Same":"Not Same");
	
	printf("%d\n", numOfPerms(4));


	freeTree(root);



}