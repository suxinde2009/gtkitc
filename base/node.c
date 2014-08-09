#include "node.h"
#include <stdio.h>

struct _UNODE* CreateRootUNode()
{
      struct _UNODE* nde = (struct _UNODE *) malloc(sizeof(struct _UNODE));

      if(nde != NULL)
      {
          puts("Created UNODE.");
          return nde;
      }
      else
          return NULL;
}

void DestroyUNode(struct _UNODE* node)
{
      if(node)
      {
          puts("Destroyed UNODE.");
          free(node);
      }
}