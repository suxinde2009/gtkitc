#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>

void btree_test_run()
{	
	/* Binary tree example. */
	InitTree();
	
	puts("\nAttempt to move to null leaves which will fail...");
	AdvanceToLeftLeaf();
	AdvanceToRightLeaf();
	
	BindNodeToLeftLeaf(CreateNodeForLeaf());
	AdvanceToLeftLeaf();
	
	DeleteTree();
}
