#include <stdio.h>
#include "./base/sll.h"

void DisplayUNode(unode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

int main()
{

      const char* testchar[] = {"13", "14", "15"};
      unode* un = NULL;
      unode* curNode = NULL;

      un = CreateRootUNode();

      AppendUnode(un, CreateRootUNode());
      AppendUnode(un, CreateRootUNode());

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

      ListUnodes(un, DisplayUNode);

      DestroyUNodeList(un);

      ListUnodes(un, DisplayUNode);

      return 0;
}