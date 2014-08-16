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

void DestroyUNodeList(unode* node)
{
      if(node)
      {
            if(node->next == node)
            {
                  puts("Deleted single node.");
                  free(node);
                  return;
            }
/*
            while(1)
            {
                  unode

                  if
            }
*/
      }
}

void AppendUnode(unode* rootNode, unode* newNode)
{

      /* Is the root node provided pointing to itself? */
      if(rootNode->next == rootNode)
      {
            /* We are at the end, so add node. */
            puts("Adding node...");
            rootNode->next = newNode;
      }
      else
      {
            /* We are not at the last node, so find it */
            /* and append. */
            unode* tempNode = rootNode;

            /* Traverse along the nodes until last is found. */
            while(tempNode->next != tempNode)
            {
                  tempNode = tempNode->next;
            }

            /* Last node found, move to the next. */
            tempNode->next = newNode;
      }

      /* Ensure new node points to itself. */
      newNode->next = newNode;
}

unode* RemoveEndUnode(unode* rootNode)
{
      return NULL;
}

void ListUnodes(unode* rootNode)
{

      unode* nextNode;

      puts("\nListing nodes...");

      if(rootNode == NULL)
      {
            perror("Empty (NULL) unode list provided.");
            return;
      }

      if(rootNode == rootNode->next)
      {
            printf("%s -> ", (char *)rootNode->payload);
      }
      else
      {

            printf("%s -> ", (char *)rootNode->payload);

            nextNode = rootNode->next;

            while(1)
            {
                  if(nextNode == nextNode->next)
                  {
                        printf("%s -> ", (char *)nextNode->payload);
                        break;
                  }
                  else
                        printf("%s -> ", (char *)nextNode->payload);

                  nextNode = nextNode->next;
            }
      }

      puts("o\n");
}