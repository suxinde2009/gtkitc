#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>
#include <bt_search.h>

static btree* rootNode = NULL;
static WALK walk;

void btree_test_run()
{
	btreeSearchAlgs searchFunc;

	puts("\nInitializing environment.\n");

	/* Binary tree example. */
	rootNode = InitTree();
	SetPayloadLeafRoot(testdata[5]);
	IncrementVisited();
	PrintNode();

	/* Bind a left leaf. */
	BindNewNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	SetPayloadLeafRoot(testdata[1]);
	IncrementVisited();
	PrintNode();

	/* Return to leaf root. */
	ReturnToLeafRoot();
	IncrementVisited();
	PrintNode();

	/* Bind right leaf. */
	BindNewNodeToRightLeaf(CreateNodeForLeaf());
	AdvanceToRightLeaf();
	SetPayloadLeafRoot(testdata[6]);
	IncrementVisited();
	PrintNode();

	/* Return to root. */
	ReturnToLeafRoot();
	IncrementVisited();
	PrintNode();

	/* Zero tree visit counts. */
	/*ResetVisitCounts(rootNode);*/
	RewindToRoot();
	PrintNode();

	puts("\nTree setup complete.\n");

	/* Perform searches */
	walk = DEPTH_FIRST_POSTORDER;

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

	searchFunc(rootNode);

	puts("\nReset tree visit counts.\n");

	ResetTreeVisitCounts(rootNode);
	searchFunc(rootNode);

	PrintNode();

	DeleteTree(rootNode);
}
