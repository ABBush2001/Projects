#include "BinarySearchTree.h"

/******
 * In this file, provide all of the definitions of the queue functions as described in BinarySearchTree.h.
 *
 * ****/

//dynamically allocates a new binary search tree and sets its root node to NULL
BinarySearchTree newBinarySearchTree()
{
	BinarySearchTree t = (BinarySearchTree)malloc(sizeof(BinarySearchTree));
	t->root = NULL;
	return t;
}

/*dynamically allocates a new node, sets its left and right pointers to NULL, sets it accountNumber to the one given in value and sets 
accountBalance to NULL*/
NodeT *allocateNode(Element value)
{
	NodeT* temp = (NodeT *)malloc(sizeof(NodeT));
	temp->left = NULL;
	temp->right = NULL;
	temp->element.accountNumber = value.accountNumber;
	temp->element.accountBalance = 0;
	return temp;
}

/*recursively moves through the tree, if value is greater than that in the node(starting with the root node), it will move to the right
of that node, otherwise it will move to the left. If the value is equal to that in the node, function will return 0(indicating the node
already exists). Otherwise, when NULL is found, value will be inserted*/
int insert(NodeT **p, Element value)
{
	if((*p) == NULL)
	{
		*p = allocateNode(value);
		return 1;
	}

	if(value.accountNumber == (*p)->element.accountNumber)
	{
		return 0;
	}

	if(value.accountNumber < (*p)->element.accountNumber)
	{
		return insert(&((*p)->left), value);
	}

	else if(value.accountNumber > (*p)->element.accountNumber)
	{
		return insert(&((*p)->right), value);
	}

	return 0;

	
}

/*recursively searches for a node based on a given value. If the searchValue is greater than the value in the node, it will move to the right
node, otherwise it will move to the left node. If the searchValue is equal to that value in the node, it will return that node. Else if the
node is NULL, it will print that the value being searched for doesn't exist*/
NodeT *search(NodeT *p, int searchValue)
{
	if(p == NULL)
	{
		printf("%d value does not exist\n", searchValue);
		return NULL;
	}	

	if(searchValue == p->element.accountNumber)
	{
		return p;
	}

	if(searchValue < p->element.accountNumber)
	{
		return search(p->left, searchValue);
	}

	else
	{
		return search(p->right, searchValue);	
	}
}

/*recursively prints the bst in inorder*/
void printInOrder(NodeT *p)
{
	if(p == NULL)
	{
		return;
	}

	printInOrder(p->left);
	printf("%d, %0.2lf\n", p->element.accountNumber, p->element.accountBalance);
	printInOrder(p->right);
}

//recursively prints the function in preorder
void printPreOrder(NodeT *p)
{
	if(p == NULL)
	{
		return;
	}

	printf("%d, %0.2lf\n", p->element.accountNumber, p->element.accountBalance);
	printPreOrder(p->left);
	printPreOrder(p->right);
}

//function to assist the freeBinarySearchTree function. Recursively moves through the BST, freeing each node 
void BSTHelper(NodeT *p)
{
	if(p == NULL)
	{
		return;
	}

	BSTHelper(p->left);
	BSTHelper(p->right);

	free(p);
}

//calls BSTHelper to free each node, then frees the tree
void freeBinarySearchTree(BinarySearchTree tree)
{
	BSTHelper(tree->root);
	free(tree);
}
