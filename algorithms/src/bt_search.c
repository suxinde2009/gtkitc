#include <stdio.h>
#include <typealiases.h>
#include <bt.h>
#include <bt_search.h>

/* Depth first search algorithms */

typedef void (*leafAdvanceFunc)(btree* const);

static leafAdvanceFunc fn = NULL;

void BTDFSPreOrder(btree* const root)
{
    fn = BTDFSPreOrder;

    if(root)
    {
        printf("Preorder: %s (%d)\n", (char*) root->payload, root->visited);
        fn(root->lleaf);
        fn(root->rleaf);
    }
}

void BTDFSInOrder(btree* const root)
{
    fn = BTDFSInOrder;

    if(root)
    {
        fn(root->lleaf);
        printf("Inorder: %s (%d)\n", (char*) root->payload, root->visited);
        fn(root->rleaf);
    }
}

void BTDFSPostOrder(btree* const root)
{
    fn = BTDFSPostOrder;

    if(root)
    {
        fn(root->lleaf);
        fn(root->rleaf);
        printf("Postorder: %s (%d)\n", (char*) root->payload, root->visited);
    }
}

/* Breadth first search algorithms */

void BTBreadthFirstSearch(btree* const root)
{
    puts("Called BTBreadthFirstSearch()");

}
