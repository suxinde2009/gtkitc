#include <stdio.h>
#include <limits.h>
#include "sll.h"

static int FreeUNode(unode* cur, unode* next)
{

      if(cur == cur->next)
      {
            printf("Deleting final node [%s]\n", (char *)cur->payload);
            free(cur);
            return 1;
      }
      else
      {
          printf("Deleting intermediate node [%s]\n", (char *)cur->payload);
          next = cur->next;
          free(cur);
      }

      return 0;

}

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

void DestroyUNodeList(unode* rootNode)
{

      unode* nextNode[2];

      if(rootNode != NULL)
      {
            if(rootNode->next == rootNode)
            {
                  puts("Deleted single node.");
                  free(rootNode);
                  return;
            }

            puts("Removing list of nodes.");

            nextNode[0] = rootNode->next;

            printf("Removing root node [%s]\n", (char *)rootNode->payload);
            free(rootNode);

            while(1)
            {
                  if(FreeUNode(nextNode[0], nextNode[1]))
                        break;

                  if(FreeUNode(nextNode[1], nextNode[0]))
                        break;
            }

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
      puts("Added intermediate node.");
      newNode->next = newNode;
}

int RemoveNthUnode(unode* rootNode, unsigned int nodeSeq)
{
      unsigned int count = 0;
      unode* currentNode;
      unode* lastNode;

      currentNode = rootNode;
      lastNode = currentNode;

      while(1)
      {
            if(count == nodeSeq)
            {
                  /* Removing node */


                  break;
            }

            count++;
      }

      return 0;
}

void ListUnodes(unode* rootNode, void (*payloaddisplay)(unode *))
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