#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


int main()
{
	//open the file
	FILE *fp;
	fp = fopen("largeInput.txt", "r");

	if(fp == NULL)
	{
		printf("Error: file could not be opened\n");
	}	

	else
	{
		BinarySearchTree tree = newBinarySearchTree();

		char buffer[100];
		char word[10];
		int val;
		double bal;

		//reads in line, checks first word, works off of that
		while(fgets(buffer, 100, fp) != NULL)
		{
			sscanf(buffer, "%s", word);
			
			//if CREATE, create new node and put into tree
			if(strcmp(word, "CREATE") == 0)
			{
				sscanf(buffer, "%s %d", word, &val);
				Element n;
				n.accountNumber = val;
				n.accountBalance = 0;

				//create double pointer equal to root node, call insert function
				NodeT **p = &(tree->root);
				insert(p, n);
				
			}

			//if PRINT, read in another string value
			if(strcmp(word, "PRINT") == 0)
			{
				char word2[10];
				sscanf(buffer, "%s %s", word, word2);

				//if PREORDER, call preorder function
				if(strcmp(word2, "PREORDER") == 0)
				{
					printPreOrder(tree->root);
				}

				//if INORDER, call inorder function
				if(strcmp(word2, "INORDER") == 0)
				{
					printInOrder(tree->root);
				}
			}

			//if SALE, read in an int and a double
			if(strcmp(word, "SALE") == 0)
			{
				sscanf(buffer, "%s %d %lf", word, &val, &bal);
				
				//search tree for node, if found, insert bal into account balance
				NodeT *p = search(tree->root, val);

				if(p == NULL)
				{
					printf("The account number %d does not exist\n", val);
				}

				else
				{
					p->element.accountBalance = p->element.accountBalance +  bal;
				}
			}
		}

		//free the tree
		freeBinarySearchTree(tree);	

	
	}

	//close the file
	fclose(fp);


	return 0;
}
