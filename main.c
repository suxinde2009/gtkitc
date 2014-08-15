#include <stdio.h>
#include "./base/node.h"

int main()
{

      unode* un = NULL;

      un = CreateRootUNode();

      const char* testchar[] = {"13", "14", "15"};

      un->payload = (char *)testchar[0];

      AppendUnode(un, CreateRootUNode());

      printf("In payload is: %s\n", (char*)un->payload);

      ListUnodes(un);

      DestroyUNodeList(un);

      return 0;
}