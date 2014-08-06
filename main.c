#include <stdio.h>
#include "./base/node.h"

int main()
{

      struct UNODE* un;
      un = CreateUNode();

      un->payload = (int *) malloc(sizeof(int));
      un->payload = (int *)1;

      printf("In payload is: %d\n", un->payload);

      DestroyUNode(un);

      return 0;
}