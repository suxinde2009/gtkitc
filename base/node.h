#ifndef _NODE_
#define _NODE_

#include <stdlib.h>

 /* Payload is the data represented in the node. */

/* An undirected node type. */
struct _UNODE
{
        void* payload;
        struct _UNODE* next;
};

/* A directed node type. */
struct _DNODE
{
        void* payload;
        struct _DNODE* prev;
        struct _DNODE* next;
};

struct _UNODE* CreateRootUNode();
void DestroyUNode(struct _UNODE* node);

#endif