#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include <typealiases.h>

/* A directed node type. */
typedef struct _DNODE
{
	void* payload;
	struct _DNODE* prev;
	struct _DNODE* next;
} dnode;

dnode* CreateDNode();
void DestroyDNodeList(dnode* node);
void AppendDNode(dnode* rootNode, dnode* newNode);
void ListDNodes(dnode* rootNode, void (*payloaddisplay)(dnode *));

/* Affine functions. */
dnode* DeleteDNode(dnode* rootNode, const UINT sequence);
dnode* InsertDNode(dnode* rootNode, dnode* newNode, const UINT sequence);

#endif
