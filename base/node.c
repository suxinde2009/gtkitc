#include "node.h"
#include <stdio.h>
#include <stdlib.h>

struct UNODE* CreateUNode()
{
      struct UNODE* nde = (struct UNODE *) malloc(sizeof(struct UNODE));

      if(nde != NULL)
      {
          puts("Created UNODE.");
          return nde;
      }
      else
          return NULL;
}

void DestroyUNode(struct UNODE* node)
{
      if(node)
      {
          puts("Destroyed UNODE.");
          free(node);
      }
}