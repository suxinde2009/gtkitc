#ifndef _NODE_
#define _NODE_

#include <stdlib.h>

 /* Payload is the data represented in the node. */

/* An undirected node type. */
typedef struct _UNODE
{
        void* payload;
        struct _UNODE* next;
} unode;

/* A directed node type. */
typedef struct _DNODE
{
        void* payload;
        struct _DNODE* prev;
        struct _DNODE* next;
} dnode;

unode* CreateRootUNode();
void DestroyUNode(unode* node);

#endif