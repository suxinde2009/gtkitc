#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bt.h>
#include <sll.h>

static btree* leafnode;

/* Support functions. */

static void _traverseLeftLeaf(btree** node)
{
	if(*node == NULL)
	{
		puts("Left leaf node is NULL.");
		return;
	}
	
	puts("Walking left leaf...");
	(*node)->previous = *node;
	*node = (*node)->lleaf;
	(*node)->visited++;	
}

static void _traverseRightLeaf(btree** node)
{
	if(*node == NULL)
	{
		puts("Right leaf node is NULL.");
		return;
	}
		
	puts("Walking right leaf...");
	(*node)->previous = *node;
	*node = (*node)->rleaf;
	(*node)->visited++;	
}

static void _printNodeDetail(btree* node)
{
	if(node == NULL)
		return;
	
	printf("\n		Root[%s] Visits[%d]\nLL[%s] Visits[%d]		RL[%s] Visits[%d]\n",
		(const char*) node->payload, node->visited,
		(const char*) node->lleaf->payload, node->lleaf->visited,
		(const char*) node->rleaf->payload, node->rleaf->visited);
}

btree* CreateLeafNode()
{
	leafnode = (btree *) malloc(sizeof(btree));

	if(leafnode != NULL)
	{
		leafnode->payload = NULL;
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

void WalkBTree(btree* node, WALK wlk)
{
	
	puts("Displaying binary tree...");

	if(node == NULL)
	{
		puts("Root node is null.");
		return;
	}
	
	/*_printNodeDetail(current);*/
	
	node->visited++;

	if(wlk == DEPTH_FIRST)
	{
		puts("\n** Walking depth first. **\n");
		
		if(node->lleaf != NULL)
		{
			_traverseLeftLeaf((btree*)&node);
			/*_printNodeDetail(node);*/
		}
		else
		if(node->rleaf != NULL)
		{
			/*_traverseRightLeaf(node);*/
			/*_printNodeDetail(node);*/		
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
