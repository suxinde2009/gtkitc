#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

#include <stdlib.h>

 /* Payload is the data represented in the node. */

/* An undirected node type. */
typedef struct _SNODE
{
        void* payload;
        struct _SNODE* next;
} snode;

snode* CreateRootSNode();
void DestroySNodeList(snode* node);
void AppendSNode(snode* rootNode, snode* newNode);
void ListSNodes(snode* rootNode, void (*payloaddisplay)(snode *));

#endif