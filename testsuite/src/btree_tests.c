#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>
#include <bt_search.h>

static btree* rootNode = NULL;
static WALK walk;

void btree_test_run()
{
	btreeSearchAlgs searchFunc;

	/* Binary tree example. */
	rootNode = InitTree();
	SetPayloadRoot(testdata[5]);
	PrintNodeAddrs();

	/* Perform searches */
	walk = DEPTH_FIRST_PREORDER;

	switch(walk)
	{
		case BREADTH_FIRST:
			searchFunc = BTBreadthFirstSearch;
			break;
		case DEPTH_FIRST_PREORDER:
			searchFunc = BTDFSPreOrder;
			break;
		case DEPTH_FIRST_INORDER:
			searchFunc = BTDFSInOrder;
			break;
		case DEPTH_FIRST_POSTORDER:
			searchFunc = BTDFSPostOrder;
			break;
		default:
			searchFunc = NULL;
			DeleteTree(rootNode);
			return;
	}

	if(searchFunc != NULL)
		searchFunc(rootNode);

/*
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
*/
	DeleteTree(rootNode);
}
