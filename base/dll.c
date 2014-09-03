#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

static int FreeDNode(dnode* cur, dnode* next)
{

      if(cur == cur->next)
      {
            printf("Deleting final DLL node [%s]\n", (char *)cur->payload);
            free(cur);
            return 1;
      }
      else
      {
            printf("Deleting intermediate DLL node [%s]\n", (char *)cur->payload);
            next = cur->next;
            free(cur);
      }

      return 0;

}

dnode* CreateDNode()
{
     dnode* nde = (dnode *) malloc(sizeof(dnode));

      if(nde != NULL)
      {

          /* Node points to inself. */
          nde->prev = nde;
          nde->next = nde;

          puts("Created DLL node.");
          return nde;
      }
      else
          return NULL;
}

void DestroyDNodeList(dnode* rootNode)
{
     dnode* nextNode[2];

      if(rootNode != NULL)
      {
            if(rootNode->next == rootNode)
            {
                  puts("Deleted single DLL node.");
                  free(rootNode);
                  return;
            }

            puts("Removing list of DLL nodes.");

            nextNode[0] = rootNode->next;

            printf("Removing root DLL node [%s]\n", (char *)rootNode->payload);
            free(rootNode);

            while(1)
            {
                  if(FreeDNode(nextNode[0], nextNode[1]))
                        break;

                  if(FreeDNode(nextNode[1], nextNode[0]))
                        break;
            }

      }
}

void AppendDNode(dnode* rootNode, dnode* newNode)
{

      /* Is the root node provided pointing to itself? */
      if(rootNode->next == rootNode)
      {
            /* We are at the end, so add node. */
            puts("Adding node...");
            rootNode->next = newNode;
            newNode->prev = rootNode;
      }
      else
      {
            /* We are not at the last node, so find it */
            /* and append. */
            dnode* tempNode = rootNode;

            /* Traverse along the nodes until last is found. */
            while(tempNode->next != tempNode)
            {
                  tempNode = tempNode->next;
            }

            /* Last node found, move to the next. */
            tempNode->next = newNode;

            /* Set the previous node for the new node. */
            newNode->prev = tempNode;
      }

      /* Ensure new node points to itself. */
      puts("Added intermediate node.");
      newNode->next = newNode;
}

void ListDNodes(dnode* rootNode, void (*payloaddisplay)(dnode *))
{

      /* TODO: Also list in reverse order. */

      dnode* nextNode;

      puts("\nListing DLL nodes (previous node payload in square brackets)...");

      if(rootNode == NULL)
      {
            perror("Empty (NULL) dnode list provided.");
            return;
      }

      if(rootNode == rootNode->next)
      {
            payloaddisplay(rootNode);
      }
      else
      {

            payloaddisplay(rootNode);

            nextNode = rootNode->next;

            while(1)
            {
                  if(nextNode == nextNode->next)
                  {
                        payloaddisplay(nextNode);
                        break;
                  }
                  else
                        payloaddisplay(nextNode);

                  nextNode = nextNode->next;
            }
      }

      puts("o\n");

}