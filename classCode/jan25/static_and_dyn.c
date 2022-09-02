#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[] = {6, 7, 8};
	int i;

	printf("a = %p\t&a = %p\n", a, &a);

	for (i=0; i<3; i++) {
		printf("a[%d] = %d\t&a[%d] = %p\n", i, a[i], i, &a[i]);
	}
	putchar('\n');

	int *b = (int *)malloc(3 * sizeof(int));
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;

	printf("b = %p\t&b = %p\n", b, &b);

	for (i=0; i<3; i++) {
		printf("b[%d] = %d\t&b[%d] = %p\n", i, b[i], i, &b[i]);
	}
	putchar('\n');


	return 0;
}
