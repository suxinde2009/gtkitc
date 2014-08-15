#include "node.h"
#include <stdio.h>

unode* CreateRootUNode()
{
      unode* nde = (unode *) malloc(sizeof(unode));

      if(nde != NULL)
      {

          /* Root node points to inself. */
          nde->next = nde;

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

void AppendUnode(unode* rootNode, unode* newNode)
{

      // Is the root node provided pointing to itself?
      if(rootNode->next == rootNode)
      {
            // We are at the end, so add node.
            rootNode->next = newNode;
      }
      else
      {
            // We are not at the last node, so find it
            // and append.
            unode* tempNode = rootNode;

            // Traverse along the nodes until last is found.
            while(tempNode->next != tempNode)
            {
                  tempNode = tempNode->next;
            }

            // Last node found, move to the next.
            tempNode->next = newNode;
      }

      // Ensure new node points to itself.
      newNode->next = newNode;
}

unode* RemoveEndUnode(unode* rootNode)
{
      return NULL;
}

void ListUnodes(unode* rootNode)
{
      puts("Listing nodes...");

      if(rootNode == NULL)
      {
            perror("Empty (NULL) unode list provided.");
            return;
      }

      printf("%s -> ", (char *)rootNode->payload);

      puts("o\n");
}