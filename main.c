#include <stdio.h>
#include "./base/sll.h"
#include "./base/dll.h"

static void DisplaySNode(snode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

static void DisplayDNode(dnode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

int main()
{

      const char* testdata[] = {"13", "14", "15"};

      snode* un = NULL;
      snode* curSNode = NULL;

      dnode* dn = NULL;
      dnode* curDNode = NULL;

      /* Singly linked list examples. */

      puts("Singly linked list run...\n");

      un = CreateSNode();

      AppendSNode(un, CreateSNode());
      AppendSNode(un, CreateSNode());

      curSNode = un;
      curSNode->payload = (char *)testdata[0];
      printf("In root payload is: %s\n", (char*)curSNode->payload);
      curSNode = curSNode->next;
      curSNode->payload = (char *)testdata[1];
      printf("In next payload is: %s\n", (char*)curSNode->payload);
      curSNode = curSNode->next;
      curSNode->payload = (char *)testdata[2];
      printf("In last payload is: %s\n", (char*)curSNode->payload);
      curSNode = NULL;

      ListSNodes(un, DisplaySNode);

      DestroySNodeList(un);

      ListSNodes(un, DisplaySNode);

      /* Doubly linked list examples. */

      puts("Doubly linked list run...\n");

      dn = CreateDNode();

      AppendDNode(dn, CreateDNode());
      AppendDNode(dn, CreateDNode());

      curDNode = dn;
      curDNode->payload = (char *)testdata[0];
      printf("In root payload is: %s\n", (char*)curDNode->payload);
      curDNode = curDNode->next;
      curDNode->payload = (char *)testdata[1];
      printf("In next payload is: %s\n", (char*)curDNode->payload);
      curDNode = curDNode->next;
      curDNode->payload = (char *)testdata[2];
      printf("In last payload is: %s\n", (char*)curDNode->payload);
      curDNode = NULL;

      ListDNodes(dn, DisplayDNode);

      DestroyDNodeList(dn);

      return 0;
}