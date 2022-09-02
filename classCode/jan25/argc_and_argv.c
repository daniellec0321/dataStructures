#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	// printing argc & argv
	printf("argc = %d \t &argc = %p\n", argc, &argc);
	printf("argv = %p \t &argv = %p\n", argv, &argv);

	// printing argv locations
	int i;
	for (i=0; i<argc; i++) {
		printf("argv[%d] = %p \t &argv[%d] = %p\n", i, argv[i], i, &argv[i]);	
	}

	return 0;
}
