#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

#include <typealiases.h>

/* A directed node type. */
typedef struct _DNODE
{
	void* payload;
	struct _DNODE* prev;
	struct _DNODE* next;
	int sentinalNode;
} dnode;

dnode* CreateDNode();
void DestroyDNodeList(dnode** rootNode);
void AppendDNode(dnode* rootNode, dnode* newNode);
void ListDNodes(dnode* rootNode, void (*payloaddisplay)(dnode *));

/* Affine functions. */
void DeleteDNode(dnode** rootNode, const UINT SEQ);
void InsertDNode(dnode** rootNode, dnode* newNode, const UINT SEQ);

#endif
