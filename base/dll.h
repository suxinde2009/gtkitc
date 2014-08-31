#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

/* A directed node type. */
typedef struct _DNODE
{
        void* payload;
        struct _DNODE* prev;
        struct _DNODE* next;
} dnode;

dnode* CreateRootDNode();
void DestroyDNodeList(dnode* node);
void AppendDNode(dnode* rootNode, dnode* newNode);
void ListDNodes(dnode* rootNode, void (*payloaddisplay)(dnode *));

#endif