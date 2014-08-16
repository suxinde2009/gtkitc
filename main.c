#include <stdio.h>
#include "./base/node.h"

int main()
{

      const char* testchar[] = {"13", "14"};
      unode* un = NULL;

      un = CreateRootUNode();

      un->payload = (char *)testchar[0];

      AppendUnode(un, CreateRootUNode());

      un->next->payload = (char *)testchar[1];

      printf("In root payload is: %s\n", (char*)un->payload);
      printf("In next payload is: %s\n", (char*)un->next->payload);

      ListUnodes(un);

      DestroyUNodeList(un);

      return 0;
}