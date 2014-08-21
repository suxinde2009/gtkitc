#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

#include <stdlib.h>

 /* Payload is the data represented in the node. */

/* An undirected node type. */
typedef struct _UNODE
{
        void* payload;
        struct _UNODE* next;
} unode;

unode* CreateRootUNode();
void DestroyUNodeList(unode* node);

void AppendUnode(unode* rootNode, unode* newNode);
int RemoveNthUnode(unode* rootNode, unsigned int nodeSeq);

void ListUnodes(unode* rootNode, void (*payloaddisplay)(unode *));

#endif