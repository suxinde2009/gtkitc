#ifndef _BINARY_TREE_SEARCH_
#define _BINARY_TREE_SEARCH_

#include <bt.h>

typedef void (*btreeSearchAlgs)(btree* const);

typedef enum {BREADTH_FIRST, DEPTH_FIRST_PREORDER, DEPTH_FIRST_INORDER,
                DEPTH_FIRST_POSTORDER} WALK;

/* Depth first search algorithms */

void BTDFSPreOrder(btree* const root);
void BTDFSInOrder(btree* const root);
void BTDFSPostOrder(btree* const root);

/* Breadth first search algorithms */

void BTBreadthFirstSearch(btree* const root);

#endif
