#include <stdio.h>
#include <unistd.h>
#include <sll_tests.h>
#include <dll_tests.h>
#include <btree_tests.h>

int main(int argc, char** argv)
{
	int options;

	while((options = getopt(argc, argv, "sdb")) != -1)
	{
		switch (options)
		{
			case 's':
				sll_test_run();
				break;
			case 'd':
				dll_test_run();
				break;
			case 'b':
				btree_test_run();
				break;
			case '?':
				puts("Use options s, d or b.");
				break;
		}
	}

	return 0;
}
