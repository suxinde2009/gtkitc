#include <stdio.h>
#include <stdlib.h>
#include <dll.h>

static UINT nodeCount = 0;

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
        /* Node points to itself. */
        nde->prev = nde;
        nde->next = nde;

        nodeCount++;

        puts("Created DLL node.");

        return nde;
    }
    else
        return NULL;
}

void DestroyDNodeList(dnode* rootNode)
{
/*
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
*/
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
/*
      dnode* nextNode;

      puts("\nListing DLL nodes (previous node payload in square brackets)...");

      if(!rootNode)
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
*/
}

/* Affine functions. */

void DeleteDNode(dnode** rootNode, const UINT sequence)
{
/*
	int count = 0;
	int exceeded = 0;

	if(!*rootNode)
	{
		puts("Node list is empty for DLL. Nothing to delete.");
		return NULL;
	}
*/
}

void InsertDNode(dnode** rootNode, dnode* newNode, const UINT SEQ)
{
	UINT count;
	dnode* prevMarker, *nextMarker, *currentMarker;

    if(SEQ > nodeCount)
    {
        puts("Node sequence beyond upper bound.");
        return;
    }

    /* Creating new dll because it wasn't initialized in the first place. */
	if(!*rootNode)
    {
        puts("Creating new DLL because root node is NULL.");

        *rootNode = newNode;
        (*rootNode)->next = *rootNode;

		return;
    }

	printf("Inserting new DLL node at position [%d]\n", SEQ);

    /* If sequence is zero we insert at the start of the list. */
    if(SEQ == 0)
    {
        nextMarker = *rootNode;
        prevMarker = newNode;

        prevMarker->next = nextMarker;
        nextMarker->prev = prevMarker;
        *rootNode = prevMarker;

        return;
    }

    /* Otherwise we insert somewhere after the beginning. */
    if(*rootNode == (*rootNode)->next)
    {
        puts("There is only one node in list! Cannot insert.");

        return;
    }

    /* Point to the root. */
    currentMarker = *rootNode;

    for(count = 1; count < SEQ; count++)
    {
        /* Advance currentMarker. */
        currentMarker = currentMarker->next;

        printf("We are at node [%s]\n", (char *)currentMarker->payload);
    }

    /* Insert new node. */
    puts("Inserting new node...");
    nextMarker = currentMarker->next;
    currentMarker->next = newNode;
    newNode->prev = currentMarker;
    newNode->next = nextMarker;
    nextMarker->prev = newNode;
}
