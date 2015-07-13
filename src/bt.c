#include <stdio.h>
#include <stdlib.h>
#include <bt.h>
#include <sll.h>

btree* CreateLeafNode()
{
	btree* leafnode = (btree *) malloc(sizeof(btree));

	if(leafnode != NULL)
	{
		leafnode->lleaf = NULL;
		leafnode->rleaf = NULL;
		leafnode->visited = 0;

		puts("Created leaf node");
	}
	else
	{
		perror("CreateLeafNode(): Failed to create leaf node.");
	}

	return leafnode;
}

void PrintBTree(btree* rootNode, WALK wlk, void (*payloaddisplay)(btree *))
{
	btree* current;
	(void)current; /* Eliminate unimportant unused var warning. */
	
	puts("Displaying binary tree...");

	if(rootNode == NULL)
	{
		puts("Root node is null.");
		return;
	}
	
	current = rootNode;
	
	payloaddisplay(current);

	if(wlk == DEPTH_FIRST)
	{
		puts("\n** Printing depth first. **\n");
		
		while(1)
		{
			puts("Walking the left branches first.");
			if(current->lleaf)
			{
				current = current->lleaf;
				current->visited++;
				payloaddisplay(current);
				continue;
			}
		
			break;
		
		}
		
		current = rootNode;
		
		while(1)
		{
			puts("Walking the right branches next.");
			if(current->rleaf)
			{
				current = current->rleaf;
				current->visited++;
				payloaddisplay(current);
				continue;
			}
		
			break;			
		}
	
		return;
	}
	
	if(wlk == BREADTH_FIRST)
	{
		puts("\n** Printing breadth first. **\n");
		
		return;
	}
}

void AppendLeaf(btree* root, btree* newLeaf, BRANCH branch)
{
	if(root == NULL)
	{
		perror("AppendLeaf(): Root node is NULL!");
		return;
	}

	if(newLeaf == NULL)
	{
		perror("AppendLeaf(): New node is NULL!");
		return;
	}

	if(branch == RIGHT_LEAF)
	{
		puts("Adding new node to right branch.");
		root->rleaf = newLeaf;
	}
	else
	if(branch == LEFT_LEAF)
	{
		puts("Adding new node to left branch.");
		root->lleaf = newLeaf;
	}
}

int DestroyTree(btree* tree, WALK wlk)
{
	if(tree == NULL)
	{
		puts("No tree or leaves to destroy.");
		return 0;
	}

	if(tree->lleaf == NULL && tree->rleaf == NULL)
	{
		puts("Deleting root with no children.");
		free(tree);
	}

	/* We return the number of nodes that we failed to destroy. */
	return 0;
}
