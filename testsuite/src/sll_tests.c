#include <test_data.h>
#include <sll_tests.h>
#include <sll.h>

static void DisplaySNode(snode* inNode)
{
	printf("%s -> ", (char *)inNode->payload);
}

void sll_test_run()
{
	snode* un = NULL;
	snode* curSNode = NULL;
	snode* newestNode = NULL;
	
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
	
	puts("Deleting selected SLL node in list.");
	un = DeleteSNode(un, 1);

	ListSNodes(un, DisplaySNode);
	
	puts("Adding a node.");
	newestNode = CreateSNode();
	
	if(newestNode != NULL)
	{
		newestNode->payload = (char *)testdata[6];
		un = InsertSNode(un, newestNode, 1);
	}
		
	ListSNodes(un, DisplaySNode);

	DestroySNodeList(un);	
}
