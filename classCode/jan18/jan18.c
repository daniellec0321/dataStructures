#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	float f;
	char *array = (char *)malloc(25*sizeof(char));
	double d;

	fscanf(stdin, "%d %f %s %lf", &i, &f, array, &d);

	fprintf(stdout, "%d %f %s %lf\n", i, f, array, d);

	free(array);

	return 0;
}
