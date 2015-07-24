#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>

void btree_test_run()
{
	/* Binary tree example. */
	InitTree();
	SetPayloadRoot(testdata[0]);
	PrintNodeAddrs();
	PrintNode();
	ReturnToLeafRoot();

	puts("Adding left and right leaf to root...");
	BindNewNodeToRightLeaf(CreateNodeForLeaf());
	AdvanceToRightLeaf();

	PrintNodeAddrs();
	SetPayloadRoot(testdata[1]);
	PrintNode();

	ReturnToLeafRoot();

	BindNewNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	SetPayloadRoot(testdata[2]);

	PrintNodeAddrs();
	PrintNode();

	BindNewNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	SetPayloadRoot(testdata[3]);

	PrintNodeAddrs();
	PrintNode();

	BindNewNodeToRightLeaf(CreateNodeForLeaf());
	AdvanceToRightLeaf();
	SetPayloadRoot(testdata[4]);

	PrintNodeAddrs();
	PrintNode();

	DeleteTree();
}
