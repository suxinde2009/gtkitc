#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#include <typealiases.h>

/* Binary tree node. */
typedef struct _BTREE
{
	void* payload;
	UINT visited;
	struct _BTREE* prev;
	struct _BTREE* lleaf;
	struct _BTREE* rleaf;
} btree;

/* Tree creation and destruction functionality. */
btree* InitTree();
void ResetTreeVisitCounts(btree* root);
void IncrementVisited();
void ZeroVisited();
void RewindToRoot();
void DeleteTree(btree* root);

btree* CreateNodeForLeaf();
int BindNewNodeToLeftLeaf(btree* newNode);
int BindNewNodeToRightLeaf(btree* newNode);

int SetPayloadLeafRoot(const char* p);
int SetPayloadLeftLeaf(const char* p);
int SetPayloadRightLeaf(const char* p);

/* Tree traversal functionality. */
UINT AdvanceToLeftLeaf();
UINT AdvanceToRightLeaf();
void ReturnToLeafRoot();
btree* GetCurrentNodeAddr();

/* Print node/leaf info. */
void PrintNode();
void PrintNodeAddrs();

#endif
