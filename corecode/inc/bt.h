#ifndef _BINARY_TREE_
#define _BINARY_TREE_

/* Binary tree node. */
typedef struct _BTREE
{
	void* payload;
	unsigned int visited;
	struct _BTREE* prev;
	struct _BTREE* lleaf;
	struct _BTREE* rleaf;
} btree;

void PrintNodeAddrs();

btree* InitTree();
void DeleteTree(btree* root);

btree* CreateNodeForLeaf();
int BindNewNodeToLeftLeaf(btree* newNode);
int BindNewNodeToRightLeaf(btree* newNode);

unsigned int AdvanceToLeftLeaf();
unsigned int AdvanceToRightLeaf();
void ReturnToLeafRoot();

int SetPayloadRoot(const char* p);
int SetPayloadLeftLeaf(const char* p);
int SetPayloadRightLeaf(const char* p);

void PrintNode();

#endif
