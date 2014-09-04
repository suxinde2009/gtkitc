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
            return NULL;
      }

      return leafnode;
}

int DestroyTree(btree* tree)
{

      /* We return the number of nodes that we failed to detroy. */
      return 0;
}