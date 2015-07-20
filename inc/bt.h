#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
	void* payload;
	int visited;
	struct _BTREE* prev;
	struct _BTREE* lleaf;
	struct _BTREE* rleaf;
} btree;

typedef enum {BREADTH_FIRST, DEPTH_FIRST} WALK;

void InitTree();
void DeleteTree();

btree* CreateNodeForLeaf();
int BindNodeToLeftLeaf(btree* newNode);
int BindNodeToRightLeaf(btree* newNode);

int AdvanceToLeftLeaf();
int AdvanceToRightLeaf();
void ReturnToLeafRoot();

#endif
