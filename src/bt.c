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
	if(current->lleaf != NULL)
	{
		puts("Attempted to create left leaf when already occupied.");
		return;		
	}
}

void CreateRightLeaf(void* pload)
{
	if(current->rleaf != NULL)
	{
		puts("Attempted to create right leaf when already occupied.");
		return;		
	}	
}

int AdvanceToLeftLeaf()
{
	if(current->lleaf == NULL)
	{
		puts("Attempted to advance to left leaf when it is NULL.");
		return 0;		
	}
	
	puts("Creating left leaf node");
	
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
	
	puts("Creating right leaf node");	
	
	current = current->rleaf;
	
	return 1;
}

void ReturnToLeafRoot()
{
	assert(current->prev == NULL && "Attempting to return to previous node that is NULL - something is wrong!");
	
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