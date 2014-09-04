#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
      void* payload;
      struct _BTREE* lleaf;
      struct _BTREE* rleaf;
} btree;

btree* CreateLeafNode();

#endif