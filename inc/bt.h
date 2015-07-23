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
int BindNewNodeToLeftLeaf(btree* newNode);
int BindNewNodeToRightLeaf(btree* newNode);

int AdvanceToLeftLeaf();
int AdvanceToRightLeaf();
void ReturnToLeafRoot();

int SetPayloadRoot(const char* p);
int SetPayloadLeftLeaf(const char* p);
int SetPayloadRightLeaf(const char* p);

void PrintNode();

#endif
