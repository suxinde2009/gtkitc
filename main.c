#include <stdio.h>
#include "./base/node.h"

int main()
{

      unode* un;
      un = CreateRootUNode();

      int testint = 13;

      un->payload = &testint;

      printf("In payload is: %d\n", *((int*)un->payload));

      DestroyUNode(un);

      return 0;
}