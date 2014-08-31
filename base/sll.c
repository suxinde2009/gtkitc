#include <stdio.h>
#include <stdlib.h>
#include "sll.h"

static int FreeSNode(snode* cur, snode* next)
{

      if(cur == cur->next)
      {
            printf("Deleting final SLL node [%s]\n", (char *)cur->payload);
            free(cur);
            return 1;
      }
      else
      {
            printf("Deleting intermediate SLL node [%s]\n", (char *)cur->payload);
            next = cur->next;
            free(cur);
      }

      return 0;

}

snode* CreateSNode()
{
      snode* nde = (snode *) malloc(sizeof(snode));

      if(nde != NULL)
      {

          /* Node points to inself. */
          nde->next = nde;

          puts("Created SLL node.");
          return nde;
      }
      else
          return NULL;
}

void DestroySNodeList(snode* rootNode)
{

      snode* nextNode[2];

      if(rootNode != NULL)
      {
            if(rootNode->next == rootNode)
            {
                  puts("Deleted single SLL node.");
                  free(rootNode);
                  return;
            }

            puts("Removing list of SLL nodes.");

            nextNode[0] = rootNode->next;

            printf("Removing root SLL node [%s]\n", (char *)rootNode->payload);
            free(rootNode);

            while(1)
            {
                  if(FreeSNode(nextNode[0], nextNode[1]))
                        break;

                  if(FreeSNode(nextNode[1], nextNode[0]))
                        break;
            }

      }
}

void AppendSNode(snode* rootNode, snode* newNode)
{

      /* Is the root node provided pointing to itself? */
      if(rootNode->next == rootNode)
      {
            /* We are at the end, so add node. */
            puts("Adding SLL node...");
            rootNode->next = newNode;
      }
      else
      {
            /* We are not at the last node, so find it */
            /* and append. */
            snode* tempNode = rootNode;

            /* Traverse along the nodes until last is found. */
            while(tempNode->next != tempNode)
            {
                  tempNode = tempNode->next;
            }

            /* Last node found, move to the next. */
            tempNode->next = newNode;
      }

      /* Ensure new node points to itself. */
      puts("Added intermediate SLL node.");
      newNode->next = newNode;
}

void ListSNodes(snode* rootNode, void (*payloaddisplay)(snode *))
{

      snode* nextNode;

      puts("\nListing SLL nodes...");

      if(rootNode == NULL)
      {
            perror("Empty (NULL) snode list provided.");
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