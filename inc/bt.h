#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
	void* payload;
	int visited;
	struct _BTREE* previous;
	struct _BTREE* lleaf;
	struct _BTREE* rleaf;
} btree;

typedef enum {LEFT_LEAF, RIGHT_LEAF} BRANCH;
typedef enum {BREADTH_FIRST, DEPTH_FIRST} WALK;

btree* CreateLeafNode();
void WalkBTree(btree* rootNode, WALK wlk);
void AppendLeaf(btree* root, btree* newLeaf, BRANCH branch);
int DestroyTree(btree* tree, WALK wlk);

#endif
