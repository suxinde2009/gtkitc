#ifdef _NODE_
#define _NODE_

 /* Payload is the data represented in the node. */

/* An undirected node type. */
struct UNODE
{
        void* payload;
        UNODE* next;
};

/* A directed node type. */
struct DNODE
{
        void* payload;
        DNODE* prev;
        DNODE* next;
};

UNODE* CreateUNode();
void DestroyUNode(UNODE* node);

#endif