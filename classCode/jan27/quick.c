#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define length1 8
#define length2 9

void printArray(int* array, int length){

    int iter;
    for(iter = 0; iter < length; ++iter){

        fprintf( stdout, "%d ", *(array + iter) );
    }

    fprintf( stdout, "\n" );
}


void shuffle(int *array, int array_len)
{
    if (array_len > 1)
    {
        int iter;
        for (iter = 0; iter < array_len - 1; ++iter)
        {
            int denominator = RAND_MAX / (array_len - iter) + 1;
            int jter = iter + (int)rand() / denominator;

            // Swap the values at iter and jter
            int temp = array[jter];
            array[jter] = array[iter];
            array[iter] = temp;
        }
    }
}

// Put the exchange function here
void exchange( int* array, int a, int b)
{
	int temp = *(array + a);
	*(array + a) = array[b];
	*(array + b) = temp;

	return;
}



// Put the partition code here
int partition(int* array, int lo, int hi )
{
	int pivot = lo;
	int i = pivot + 1;
	int j = hi;

	int pivot_value = *(array+pivot);

	while (1) {
		while(array[i] < pivot_value) {
			if (i==hi) break;
			++i;
		}

		while(pivot_value < array[j]) {
			if(j==lo) break;
			--j;
		}

		if (i>=j) break;
		exchange(array, i, j);
	}

	if (lo != j) {
		exchange(array, lo, j);
	}

	return j;
}

void quick_sort_recursive(int* array, int lo, int hi, int array_len )
{
	if (hi >= lo) return;

	if (hi == lo+1) {
		if (array[hi] < array[lo]) {
			exchange(array, lo, hi);
		}
	}

	int j = partition(array, lo, hi);

	quick_sort_recursive(array, lo, j-1, array_len);
	quick_sort_recursive(array, j+1, hi, array_len);

	return;	
}

void quick_sort(int *array, int array_len)
{
	printf("Initialize the quick sort...\n");
	quick_sort_recursive(array, 0, array_len-1, array_len);

	return;
}


int main( const int argc, const char* argv[] )
{

    /* Seed the random number generator */
    srand( (unsigned int)time(0) );

    int* array = (int *)malloc( (long unsigned int)(argc - 1) * sizeof(int) );

    int iter;
    for( iter = 1; iter < argc; ++iter){

        /* Convert and store input values */
        array[ iter - 1 ] = atoi( argv[iter] );

    }

    /* Print the initiali arrays */
    fprintf( stdout, "Initial Array  : " );
    printArray(array, argc - 1);

    shuffle( array, argc - 1 );

    fprintf( stdout, "Shuffled Array : " );
    printArray(array, argc - 1 );

    quick_sort(array, argc - 1);
    fprintf( stdout, "Sorted Array   : " );
    printArray(array, argc - 1);

    fprintf( stdout, "\n");
    /* Free the array */
    free( array );

    return 0;
}
