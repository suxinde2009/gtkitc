#include <stdio.h>
#include "./base/node.h"

int main()
{

      struct UNODE* un;
      un = CreateUNode();

      DestroyUNode(un);

      return 0;
}