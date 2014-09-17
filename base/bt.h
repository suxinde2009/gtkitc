#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
      void* payload;
      struct _BTREE* lleaf;
      struct _BTREE* rleaf;
} btree;

typedef enum {_LEFT, _RIGHT} BRANCH;

btree* CreateLeafNode();
void PrintBTree(btree* rootNode, void (*payloaddisplay)(btree *));
void AppendLeaf(btree* root, btree* newLeaf, BRANCH branch);
int DestroyTree(btree* tree);

#endif