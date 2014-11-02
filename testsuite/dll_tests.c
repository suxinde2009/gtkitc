#include "test_data.h"
#include "dll_tests.h"
#include "../base/dll.h"

static void DisplayDNode(dnode* inNode)
{
	printf("%s [%s] -> ", (char *)inNode->payload, (char *)inNode->prev->payload);
}

void dll_test_run()
{
	dnode* dn = NULL;
	dnode* curDNode = NULL;	
	
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
}
