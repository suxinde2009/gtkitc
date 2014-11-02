#include <stdio.h>
#include "./testsuite/sll_tests.h"
#include "./base/dll.h"
#include "./base/bt.h"


static void DisplayDNode(dnode* inNode)
{
	printf("%s [%s] -> ", (char *)inNode->payload, (char *)inNode->prev->payload);
}

static void DisplayBTreeLeaf(btree* inLeaf)
{
	if(!inLeaf->lleaf && !inLeaf->rleaf)
	{
		puts("NULL leaf nodes encountered.");
		return;
	}
	
	printf("[root: %s](%d) [lleaf: %s](%d) [rleaf: %s](%d)\n", 
		(char *)inLeaf->payload, inLeaf->visited,
		(char *)inLeaf->lleaf->payload, inLeaf->lleaf->visited,
		(char *)inLeaf->rleaf->payload, inLeaf->rleaf->visited);
}

int main()
{

	const char* testdata[] = {"0", "1", "2", "3", "4", "5", "6"};


	dnode* dn = NULL;
	dnode* curDNode = NULL;

	btree* bt = NULL;

	sll_test_run();

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
	
	/* Binary tree example. */

	puts("\nBinary tree run...\n==================\n");

	bt = CreateLeafNode();

	/* Root assignments. */
	AppendLeaf(bt, CreateLeafNode(), RIGHT_LEAF);
	AppendLeaf(bt, CreateLeafNode(), LEFT_LEAF);

	bt->payload = (char *)testdata[0];
	printf("In root payload is: %s\n", (char*)bt->payload);
	bt->lleaf->payload = (char *)testdata[1];
	printf("In left leaf is: %s\n", (char*)bt->lleaf->payload);
	bt->rleaf->payload = (char *)testdata[2];
	printf("In right leaf is: %s\n", (char*)bt->rleaf->payload);
	
	/* Left leaf assignments. */
	AppendLeaf(bt->lleaf, CreateLeafNode(), RIGHT_LEAF);
	AppendLeaf(bt->lleaf, CreateLeafNode(), LEFT_LEAF);	
	
	bt->lleaf->lleaf->payload = (char *)testdata[3];
	printf("In lleaf-lleaf payload is: %s\n", (char*)bt->lleaf->lleaf->payload);
	bt->lleaf->rleaf->payload = (char *)testdata[4];
	printf("In lleaf-rleaf payload is: %s\n", (char*)bt->lleaf->rleaf->payload);
	
	/* Right leaf assignments. */
	AppendLeaf(bt->rleaf, CreateLeafNode(), RIGHT_LEAF);
	AppendLeaf(bt->rleaf, CreateLeafNode(), LEFT_LEAF);	
	
	bt->rleaf->lleaf->payload = (char *)testdata[5];
	printf("In rleaf-lleaf payload is: %s\n", (char*)bt->rleaf->lleaf->payload);
	bt->rleaf->rleaf->payload = (char *)testdata[6];
	printf("In rleaf-rleaf payload is: %s\n", (char*)bt->rleaf->rleaf->payload);	

	PrintBTree(bt, DEPTH_FIRST, DisplayBTreeLeaf);

	DestroyTree(bt, DEPTH_FIRST);

	return 0;
}
