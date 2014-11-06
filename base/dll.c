#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

/* Marked nodes and previous nodes for deletion and appending nodes. */
static dnode* markedNode, *prevNode, *nextNode;

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

/* Affine functions. */

dnode* DeleteDNode(dnode* rootNode, const unsigned int sequence)
{
	int count = 0;
	int exceeded = 0;
	
	if(rootNode == NULL)
	{
		puts("Node list is empty for DLL. Nothing to delete.");
		return NULL;
	}
	
	if(rootNode == rootNode->next)
	{
		puts("Only DLL root node exists.");
		
		/* Check to see if we intended to delete this node. */
		if(sequence == 0)
		{
			puts("Deleting root node as sequence is 0.");
			free(rootNode);
		}
		
		return rootNode;
	}
	
	/* We have more than one node in the list. */
	if(sequence == 0)
	{
		/* We remove the root node. */
		markedNode = rootNode->next;
		markedNode->prev = markedNode;
		
		free(rootNode);
		
		rootNode = markedNode;
		
		return rootNode;
	}
	else
	{
		markedNode = rootNode;
		
		while(1)
		{
			if(count == sequence)
			{
				if(markedNode->next != markedNode)
				{
					/* Remove the intermediate node. */			
					prevNode = markedNode->prev;
					nextNode = markedNode->next;
					
					prevNode->next = nextNode;
					nextNode->prev = prevNode;
					
				}
				else
				{
					/* Last node encountered points to itself! */
					prevNode = markedNode->prev;
					prevNode->next = prevNode;
				}
				
				free(markedNode);
				
				return rootNode;				
			}
			
			if(exceeded)
			{
				perror("Requested DLL node to be deleted is past end of list.");
				break;
			}
			
			markedNode = markedNode->next;
			count++;
			
			if(markedNode == markedNode->next)
				exceeded = 1;						
		}
	}
	
	return rootNode;
}

dnode* InsertDNode(dnode* rootNode, dnode* newNode, const unsigned int sequence)
{
	return rootNode;
}
