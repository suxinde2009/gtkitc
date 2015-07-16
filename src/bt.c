#include <stdio.h>
#include <stdlib.h>
#include <bt.h>
#include <sll.h>

/* Support functions. */

static void _traverseLeftLeaf(btree** node)
{
	if(*node == NULL)
		return;
	
	puts("Walking left leaf...");
	(*node)->previous = *node;
	*node = (*node)->lleaf;
	(*node)->visited++;	
}

static void _traverseRightLeaf(btree** node)
{
	if(*node == NULL)
		return;
		
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
			_traverseLeftLeaf((btree*)&current);
			_printNodeDetail(current);
			_traverseLeftLeaf((btree*)&current);
			_printNodeDetail(current);
		}
		else
		if(current->rleaf != NULL)
		{
			/*_traverseRightLeaf(current);*/
			_printNodeDetail(current);		
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
