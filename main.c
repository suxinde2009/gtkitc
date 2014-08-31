#include <stdio.h>
#include "./base/sll.h"

void DisplaySNode(snode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

int main()
{

      const char* testchar[] = {"13", "14", "15"};

      /* Singly linked list examples. */

      snode* un = NULL;
      snode* curNode = NULL;

      un = CreateRootSNode();

      AppendSNode(un, CreateRootSNode());
      AppendSNode(un, CreateRootSNode());

      curNode = un;
      curNode->payload = (char *)testchar[0];
      printf("In root payload is: %s\n", (char*)curNode->payload);
      curNode = curNode->next;
      curNode->payload = (char *)testchar[1];
      printf("In next payload is: %s\n", (char*)curNode->payload);
      curNode = curNode->next;
      curNode->payload = (char *)testchar[2];
      printf("In last payload is: %s\n", (char*)curNode->payload);
      curNode = NULL;

      ListSNodes(un, DisplaySNode);

      DestroySNodeList(un);

      ListSNodes(un, DisplaySNode);

      /* Doubly linked list examples. */

      return 0;
}