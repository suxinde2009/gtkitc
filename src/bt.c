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

void WalkBTree(btree* rootNode, WALK wlk, void (*payloaddisplay)(btree *))
{
	btree* current;
	
	puts("Displaying binary tree...");

	if(rootNode == NULL)
	{
		puts("Root node is null.");
		return;
	}
	
	current = rootNode;
	
	payloaddisplay(current);
	
	current->visited++;

	if(wlk == DEPTH_FIRST)
	{
		puts("\n** Walking depth first. **\n");
		
		if(current->lleaf != NULL)
		{
			puts("Walking left branch...");
			current->previous = current;
			current = current->lleaf;
			current->visited++;
		}
		else
		if(current->rleaf != NULL)
		{
			puts("Walking right branch...");
			current->previous = current;
			current = current->rleaf;
			current->visited++;			
		}
	}
	
	if(wlk == BREADTH_FIRST)
	{
		puts("\n** Walking breadth first. **\n");
	
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
