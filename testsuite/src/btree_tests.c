#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>

void btree_test_run()
{
	/* Binary tree example. */
	InitTree();
	SetPayloadRoot(testdata[0]);
	PrintNode();
	ReturnToLeafRoot();

	puts("Adding left and right leaf to root...");
	BindNewNodeToRightLeaf(CreateNodeForLeaf());
	AdvanceToRightLeaf();
	SetPayloadRoot(testdata[1]);
	PrintNode();

	/*ReturnToLeafRoot();*/

	BindNewNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	SetPayloadRoot(testdata[2]);
	PrintNode();

	BindNewNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	SetPayloadRoot(testdata[3]);
	PrintNode();

	BindNewNodeToRightLeaf(CreateNodeForLeaf());
	AdvanceToRightLeaf();
	SetPayloadRoot(testdata[4]);
	PrintNode();
	
	DeleteTree();
}
