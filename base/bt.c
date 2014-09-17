#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

btree* CreateLeafNode()
{
      btree* leafnode = (btree *) malloc(sizeof(btree));

      if(leafnode != NULL)
      {
            leafnode->lleaf = NULL;
            leafnode->rleaf = NULL;

            puts("Created leaf node");
      }
      else
      {
            puts("Failed to create leaf node.");
      }

      return leafnode;
}

void PrintBTree(btree* rootNode, void (*payloaddisplay)(btree *))
{
      puts("Displaying binary tree...");

      if(rootNode == NULL)
      {
            puts("Root node is null.");
      }
}

void AppendLeaf(btree* root, btree* newLeaf, BRANCH branch)
{

}

int DestroyTree(btree* tree)
{
      if(tree == NULL)
      {
            puts("No tree or leaves to destroy.");
            return 0;
      }

      if(tree->lleaf == NULL && tree->rleaf == NULL)
      {
            puts("Deleting root with no children.");
            free(tree);
      }

      /* We return the number of nodes that we failed to detroy. */
      return 0;
}