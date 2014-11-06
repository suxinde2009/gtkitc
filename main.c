#include <stdio.h>
#include "./testsuite/sll_tests.h"
#include "./testsuite/dll_tests.h"
#include "./testsuite/btree_tests.h"

int main()
{
	/*sll_test_run();*/
	dll_test_run();
	/*btree_test_run();*/

	return 0;
}
