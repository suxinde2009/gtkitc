#include <stdio.h>
#include "./base/sll.h"
#include "./base/dll.h"
#include "./base/bt.h"

static void DisplaySNode(snode* inNode)
{
      printf("%s -> ", (char *)inNode->payload);
}

static void DisplayDNode(dnode* inNode)
{
      printf("%s [%s] -> ", (char *)inNode->payload, (char *)inNode->prev->payload);
}

static void DisplayBTreeLeaf(btree* inLeaf)
{
      printf("[root: %s] [lleaf: %s] [rleaf: %s]", (char *)inLeaf->payload,
            (char *)inLeaf->lleaf->payload, (char *)inLeaf->rleaf->payload);
}

int main()
{

      const char* testdata[] = {"Marleine", "Mary", "Butcher", "Derek", "Andrew", "Dean", "Neil"};

      snode* un = NULL;
      snode* curSNode = NULL;

      dnode* dn = NULL;
      dnode* curDNode = NULL;

      btree* bt = NULL;

      /* Singly linked list example. */

      puts("\nSingly linked list run...\n=========================\n");

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

      /* Doubly linked list example. */

      puts("\nDoubly linked list run...\n=========================\n");

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

      puts("\nBinary tree run...\n==================\n");

      bt = CreateLeafNode();

      AppendLeaf(bt, CreateLeafNode(), RIGHT_LEAF);
      AppendLeaf(bt, CreateLeafNode(), LEFT_LEAF);
      
      bt->payload = (char *)testdata[0];
      printf("In root payload is: %s\n", (char*)bt->payload);
      bt->lleaf->payload = (char *)testdata[1];
      printf("In left leaf is: %s\n", (char*)bt->lleaf->payload);
      bt->rleaf->payload = (char *)testdata[2];
      printf("In right leaf is: %s\n", (char*)bt->rleaf->payload);

      PrintBTree(bt, BREADTH_FIRST, DisplayBTreeLeaf);

      DestroyTree(bt, BREADTH_FIRST);

      return 0;
}
