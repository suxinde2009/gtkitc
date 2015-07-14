#include <test_data.h>
#include <btree_tests.h>
#include <bt.h>

static void DisplayBTreeLeaf(btree* inLeaf)
{
	if(!inLeaf->lleaf && !inLeaf->rleaf)
	{
		puts("NULL leaf nodes encountered.");
		return;
	}
	
	printf("           [root: %s](%d)\n [lleaf: %s](%d)    [rleaf: %s](%d)\n", 
		(char *)inLeaf->payload, inLeaf->visited,
		(char *)inLeaf->lleaf->payload, inLeaf->lleaf->visited,
		(char *)inLeaf->rleaf->payload, inLeaf->rleaf->visited);
}

void btree_test_run()
{
	btree* bt = NULL;
	
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
	
	/* Let's add a few more! */
	AppendLeaf(bt->rleaf->lleaf, CreateLeafNode(), RIGHT_LEAF);
	AppendLeaf(bt->rleaf->lleaf, CreateLeafNode(), LEFT_LEAF);
	
	bt->rleaf->lleaf->lleaf->payload = (char *)testdata[7];
	bt->rleaf->lleaf->rleaf->payload = (char *)testdata[8];
	printf("In rleaf-lleaf-lleaf payload is: %s\n", (char*)bt->rleaf->lleaf->lleaf->payload);
	printf("In rleaf-lleaf-rleaf payload is: %s\n", (char*)bt->rleaf->lleaf->rleaf->payload);

	WalkBTree(bt, DEPTH_FIRST, DisplayBTreeLeaf);

	DestroyTree(bt, DEPTH_FIRST);
}
