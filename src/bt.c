#include <stdio.h>
#include <stdlib.h>
#include <bt.h>
#include <sll.h>

static btree* rootNode, *current;

void InitRoot()
{
	rootNode = (btree*) malloc(sizeof(btree));
	
	rootNode->prev = rootNode;	/* Root points to itself. */
	rootNode->payload = NULL;
	rootNode->lleaf = NULL;
	rootNode->rleaf = NULL;
	
	rootNode->visited = 0;
	
	current = rootNode;
}

void CreateLeftLeaf()
{
	
}

void CreateRightLeaf()
{
	
}

void AdvanceToLeftLeaf()
{
	
}

void AdvanceToRightLeaf()
{
	
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