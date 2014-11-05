#ifndef _SINGLY_LINKED_LIST_
#define _SINGLY_LINKED_LIST_

/* Payload is the data represented in the node. */

/* An undirected node type. */
typedef struct _SNODE
{
	void* payload;
    struct _SNODE* next;
} snode;

snode* CreateSNode();
void DestroySNodeList(snode* node);
void AppendSNode(snode* rootNode, snode* newNode);
void ListSNodes(snode* rootNode, void (*payloaddisplay)(snode *));

/* Affine functions. */
snode* DeleteSNode(snode* rootNode, const unsigned int sequence);
snode* InsertSNode(snode* rootNode, snode* newNode, const unsigned int sequence);

#endif
