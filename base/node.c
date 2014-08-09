#include "node.h"
#include <stdio.h>

unode* CreateRootUNode()
{
      unode* nde = (unode *) malloc(sizeof(unode));

      if(nde != NULL)
      {
          //

          puts("Created UNODE.");
          return nde;
      }
      else
          return NULL;
}

void DestroyUNode(unode* node)
{
      if(node)
      {
          puts("Destroyed UNODE.");
          free(node);
      }
}