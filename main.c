#include <stdio.h>
#include "./base/sll.h"

void DisplaySNode(snode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

int main()
{

      const char* testdata[] = {"13", "14", "15"};

      snode* un = NULL;
      snode* curNode = NULL;

      /* Singly linked list examples. */

      puts("Singly linked list run...\n");

      un = CreateSNode();

      AppendSNode(un, CreateSNode());
      AppendSNode(un, CreateSNode());

      curNode = un;
      curNode->payload = (char *)testdata[0];
      printf("In root payload is: %s\n", (char*)curNode->payload);
      curNode = curNode->next;
      curNode->payload = (char *)testdata[1];
      printf("In next payload is: %s\n", (char*)curNode->payload);
      curNode = curNode->next;
      curNode->payload = (char *)testdata[2];
      printf("In last payload is: %s\n", (char*)curNode->payload);
      curNode = NULL;

      ListSNodes(un, DisplaySNode);

      DestroySNodeList(un);

      ListSNodes(un, DisplaySNode);

      /* Doubly linked list examples. */

      puts("Doubly linked list run...\n");

      return 0;
}