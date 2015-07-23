#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bt.h>
#include <sll.h>

static btree* rootNode = NULL, *current = NULL;

void InitTree()
{
	assert((rootNode == NULL) && "Attempted to reinitialize tree!");

	puts("Initializing tree");

	rootNode = (btree*) malloc(sizeof(btree));

	rootNode->prev = rootNode;	/* Root points to itself. */
	rootNode->payload = NULL;
	rootNode->lleaf = NULL;
	rootNode->rleaf = NULL;

	rootNode->visited = 0;

	current = rootNode;
}

btree* CreateNodeForLeaf()
{
	btree* node = (btree*) malloc(sizeof(btree));

	node->lleaf = NULL;
	node->rleaf = NULL;
	node->payload = NULL;
	node->prev = NULL;

	(node) ? puts("New node created for leaf.") : puts("Failed to create new node for leaf.");

	return node;
}

int BindNewNodeToLeftLeaf(btree* newNode)
{
	current->prev = current;
	current->lleaf = newNode;

	return 0;
}

int BindNewNodeToRightLeaf(btree* newNode)
{
	current->prev = current;
	current->rleaf = newNode;

	return 0;
}

int AdvanceToLeftLeaf()
{
	if(current->lleaf == NULL)
	{
		puts("Attempted to advance to left leaf when it is NULL.");
		return 0;
	}

	puts("Advancing left leaf node");

	current->visited++;
	current = current->lleaf;

	return 1;
}

int AdvanceToRightLeaf()
{
	if(current->rleaf == NULL)
	{
		puts("Attempted to advance to right leaf when it is NULL.");
		return 0;
	}

	puts("Advancing right leaf node");

	current->visited++;
	current = current->rleaf;

	return 1;
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

void DeleteTree()
{
	puts("Deleting tree");

	if(current != NULL && current->prev == current)
	{
		puts("Deleting root");
		free(rootNode);
	}
}

int SetPayloadRoot(const char* p)
{
	if(!current->payload)
	{
		current->payload = (void *)p;
		return 1;
	}

	return 0;
}

int SetPayloadLeftLeaf(const char* p)
{
	if(!current->payload)
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
