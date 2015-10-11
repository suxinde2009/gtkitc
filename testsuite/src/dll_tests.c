#include <test_data.h>
#include <dll_tests.h>
#include <dll.h>

static void DisplayDNode(dnode* inNode)
{
	printf("%s [%s] -> ", (char *)inNode->payload, (char *)inNode->prev->payload);
}

void dll_test_run()
{
	dnode* dn = NULL;
	dnode* curDNode = NULL;
	dnode* newestNode = NULL;

	/* Doubly linked list example. */

	puts("\nDoubly linked list run...\n=========================\n");

	dn = CreateDNode();

	AppendDNode(dn, CreateDNode());
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
	curDNode = curDNode->next;
	curDNode->payload = (char *)testdata[3];
	printf("In last payload is: %s\n", (char*)curDNode->payload);
	curDNode = NULL;

	ListDNodes(dn, DisplayDNode);

	puts("Deleting selected DLL node in list.");
	DeleteDNode((dnode **)&dn, 1);

	ListDNodes(dn, DisplayDNode);

	puts("Adding a node.");
	newestNode = CreateDNode();

	if(newestNode != NULL)
	{
		newestNode->payload = (char *)testdata[6];
		InsertDNode((dnode**)&dn, newestNode, 1);
	}

	ListDNodes(dn, DisplayDNode);

	DestroyDNodeList(dn);
}
