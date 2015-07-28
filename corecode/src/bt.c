#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <bt.h>
#include <sll.h>

static btree* current = NULL;

void PrintNodeAddrs()
{
	printf("prev: %p curr: %p\n", (void *)current->prev, (void *)current);
}

btree* InitTree()
{
	btree* root = NULL;

	puts("Initializing tree");

	root = (btree*) malloc(sizeof(btree));

	memset(root, 0, sizeof(btree));

	root->prev = root;	/* Root points to itself. */

	current = root;

	return root;
}

btree* CreateNodeForLeaf()
{
	btree* node = (btree*) malloc(sizeof(btree));

	memset(node, 0, sizeof(btree));

	(node) ? puts("New node created for leaf.") : puts("Failed to create new node for leaf.");

	return node;
}

int BindNewNodeToLeftLeaf(btree* newNode)
{
	if(newNode == NULL)
		return 0;

	newNode->prev = current;
	current->lleaf = newNode;

	return 1;
}

int BindNewNodeToRightLeaf(btree* newNode)
{
	if(newNode == NULL)
		return 0;

	newNode->prev = current;
	current->rleaf = newNode;

	return 1;
}

unsigned int AdvanceToLeftLeaf()
{
	if(current->lleaf == NULL)
	{
		puts("Attempted to advance to left leaf when it is NULL.");
		return 0;
	}

	puts("Advancing left leaf node");

	current->visited++;
	current = current->lleaf;

	return current->visited;
}

unsigned int AdvanceToRightLeaf()
{
	if(current->rleaf == NULL)
	{
		puts("Attempted to advance to right leaf when it is NULL.");
		return 0;
	}

	puts("Advancing right leaf node");

	current->visited++;
	current = current->rleaf;

	return current->visited;
}

void ReturnToLeafRoot()
{
	if(current == current->prev)
	{
		puts("At root of entire tree, so cannot back up!");
		return;
	}

	puts("Backing up to leaf root.");
	current = current->prev;
}

void DeleteTree(btree* root)
{
	puts("Deleting tree");

	if(current != NULL && current->prev == current)
	{
		puts("Deleting root");
		free(root);
	}
}

int SetPayloadRoot(const char* p)
{
	if(current->payload == 0)
	{
		current->payload = (void *)p;
		return 1;
	}

	return 0;
}

int SetPayloadLeftLeaf(const char* p)
{
	if(current->payload == 0)
	{
		current->payload = (void *)p;
		return 1;
	}

	return 0;
}

int SetPayloadRightLeaf(const char* p)
{
	if(!current->payload)
	{
		current->payload = (void *)p;
		return 1;
	}

	return 0;
}

void PrintNode()
{
	printf("Root: %s (%d), Left: %s (%d), Right: %s (%d)\n",
		(current) ? (char*) current->payload : "*",
		(current) ? current->visited : -1,
		(current->lleaf) ? (char*) current->lleaf->payload : "*",
		(current->lleaf) ? current->lleaf->visited : -1,
		(current->rleaf) ? (char*) current->rleaf->payload : "*",
		(current->rleaf) ? current->rleaf->visited : -1);
}
