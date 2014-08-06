#ifndef _NODE_
#define _NODE_

#include <stdlib.h>

 /* Payload is the data represented in the node. */

/* An undirected node type. */
struct UNODE
{
        void* payload;
        struct UNODE* next;
};

/* A directed node type. */
struct DNODE
{
        void* payload;
        struct DNODE* prev;
        struct DNODE* next;
};

struct UNODE* CreateUNode();
void DestroyUNode(struct UNODE* node);

#endif