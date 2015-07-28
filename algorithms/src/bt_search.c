#include <stdio.h>
#include <typealiases.h>
#include <bt.h>
#include <bt_search.h>

/* Depth first search algorithms */

void BTDFSPreOrder(btree* const root)
{
    int checkedRootRightLeaf = 0;

    puts("Called BTDFSPreOrder()");

    PrintNodeAddrs();

    if(root->lleaf == NULL && root->rleaf == NULL)
    {
        PrintNode();
        return;
    }

    while((root->prev != root) && checkedRootRightLeaf)
    {
        checkedRootRightLeaf = 1;
    }
}

void BTDFSInOrder(btree* const root)
{
    puts("Called BTDFSInOrder()");

}

void BTDFSPostOrder(btree* const root)
{
    puts("Called BTDFSPostOrder()");

}

/* Breadth first search algorithms */

void BTBreadthFirstSearch(btree* const root)
{
    puts("Called BTBreadthFirstSearch()");

}
