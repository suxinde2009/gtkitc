#include <stdio.h>
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
            nextNode[1] = nextNode[0]->next;

            printf("Node [%s]\n", (char *)rootNode->payload);
            printf("Node [%s]\n", (char *)nextNode[0]->payload);
            printf("Node [%s]\n", (char *)nextNode[1]->payload);

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