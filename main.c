#include <stdio.h>
#include "./base/node.h"

int main()
{

      unode* un = NULL;

      un = CreateRootUNode();

      const char* testchar = "13";

      un->payload = (char *)testchar;

      printf("In payload is: %s\n", (char*)un->payload);

      ListUnodes(un);

      DestroyUNode(un);

      return 0;
}