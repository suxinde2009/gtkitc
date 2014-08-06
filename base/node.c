#include "node.h"

UNODE* CreateUNode()
{
      nde = (UNODE *) malloc(sizeof(UNODE));

      if(nde != NULL)
          return nde;
      else
          return NULL;
}

void DestroyUNode(UNODE* node)
{
      if(node)
          free(node);
}