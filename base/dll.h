#ifndef _NODE_
#define _NODE_

/* A directed node type. */
typedef struct _DNODE
{
        void* payload;
        struct _DNODE* prev;
        struct _DNODE* next;
} dnode;

#endif