#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
	void* payload;
	struct _BTREE* lleaf;
	struct _BTREE* rleaf;
} btree;

typedef enum {LEFT_LEAF, RIGHT_LEAF} BRANCH;
typedef enum {BREADTH_FIRST, DEPTH_FIRST} WALK;

btree* CreateLeafNode();
void PrintBTree(btree* rootNode, WALK wlk, void (*payloaddisplay)(btree *));
void AppendLeaf(btree* root, btree* newLeaf, BRANCH branch);
int DestroyTree(btree* tree, WALK wlk);

#endif
