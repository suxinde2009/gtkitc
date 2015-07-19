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

void CreateLeftLeaf(void* pload)
{
	
}

void CreateRightLeaf(void* pload)
{
	
}

int AdvanceToLeftLeaf()
{
	return 0;
}

int AdvanceToRightLeaf()
{
	return 0;
}

void ReturnToLeafRoot()
{
	
}

void DeleteTree()
{
	if(rootNode != NULL)
	{
		free(rootNode);
	}
}