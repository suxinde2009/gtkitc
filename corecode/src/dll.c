#include <stdio.h>
#include <stdlib.h>
#include <dll.h>

static dnode* lastNode = NULL;

dnode* CreateDNode()
{
    dnode* nde = (dnode *) malloc(sizeof(dnode));

    if(nde != NULL)
    {
        /* Node points to itself. */
        nde->prev = nde;
        nde->next = nde;

        nde->sentinalNode = 1;

        puts("Created DLL node.");

        return nde;
    }
    else
        return NULL;
}

void DestroyDNodeList(dnode** rootNode)
{
    dnode* marked = NULL, *next = NULL, *prev = NULL;

    puts("Destroying dnode list.");

	if(!*rootNode)
	{
		puts("Node list is empty for DLL. Nothing to delete.");
		return;
	}

    marked = *rootNode;
    next = (*rootNode)->next;

    puts("Now clearing node list...");

    /* Delete in reverse order. */
    prev = lastNode;

    while(prev != *rootNode)
    {
        printf("Targetted node %s [%s]\n", (char *)prev->payload, (char *)prev->prev->payload);
        prev = prev->prev;
        free(prev->next);
        prev->next = NULL;
    }

    printf("Final node %s [%s]\n", (char *)prev->payload, (char *)prev->prev->payload);
    free(*rootNode);
    *rootNode = NULL;
}

void AppendDNode(dnode* rootNode, dnode* newNode)
{

      /* Is the root node also the last node? */
      if(rootNode->sentinalNode != 0)
      {
            /* We are at the end, so add node. */
            puts("Adding node...");
            rootNode->next = newNode;
            rootNode->sentinalNode = 0;
            newNode->prev = rootNode;
      }
      else
      {
            /* We are not at the last node, so find it */
            /* and append. */
            dnode* tempNode = rootNode;

            /* Traverse along the nodes until last is found. */
            while(tempNode->sentinalNode == 0)
            {
                  tempNode = tempNode->next;
            }

            /* Last node found, move to the next. */
            tempNode->next = newNode;

            /* Set the previous node for the new node. */
            newNode->prev = tempNode;
      }

      /* Ensure new node points to itself and sentinalNode set. */
      puts("Appended new node.");
      newNode->next = newNode;
      newNode->prev->sentinalNode = 0;
      newNode->sentinalNode = 1;

      lastNode = newNode;
}

void ListDNodes(dnode* rootNode, void (*payloaddisplay)(dnode *))
{

    dnode* nextNode;

    puts("\nListing DLL nodes (previous node payload in square brackets)...");

    if(!rootNode)
    {
        perror("Empty dnode list provided.");
        return;
    }

    payloaddisplay(rootNode);
    nextNode = rootNode->next;

    while(nextNode->sentinalNode == 0)
    {
        payloaddisplay(nextNode);
        nextNode = nextNode->next;
    }

    payloaddisplay(nextNode);

    puts("o\n");

}

/* Affine functions. */

void DeleteDNode(dnode** rootNode, const UINT SEQ)
{
    UINT c;
    dnode* currentNode = *rootNode, *prevNode = NULL, *nextNode = NULL;

    if((*rootNode)->sentinalNode == 1 && SEQ == 0)
    {
        free(*rootNode);
        return;
    }

    for(c = 0; c < SEQ; c++)
    {
        if(currentNode->sentinalNode != 0)
        {
            puts("Last node reached. No deletion has taken place.");
            return;
        }

        currentNode = currentNode->next;
    }

    printf("Deleting node: %s [%s]\n", (char *)currentNode->payload, (char *)currentNode->prev->payload);

    prevNode = currentNode->prev;
    nextNode = currentNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    free(currentNode);
}

void InsertDNode(dnode** rootNode, dnode* newNode, const UINT SEQ)
{

}
