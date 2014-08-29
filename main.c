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

      un = CreateRootUNode();

      un->payload = (char *)testchar[0];

      AppendUnode(un, CreateRootUNode());
      AppendUnode(un, CreateRootUNode());

      un->next->payload = (char *)testchar[1];
      un->next->next->payload = (char *)testchar[2];

      ListUnodes(un, DisplayUNode);

      printf("In root payload is: %s\n", (char*)un->payload);
      printf("In next payload is: %s\n", (char*)un->next->payload);
      printf("In next payload is: %s\n", (char*)un->next->next->payload);

      ListUnodes(un, DisplayUNode);

      DestroyUNodeList(un);

      ListUnodes(un, DisplayUNode);

      return 0;
}