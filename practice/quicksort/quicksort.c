#include <stdio.h>
#include <stdlib.h>



void print_array(int *arr, long unsigned int arr_len)
{
	if (arr == NULL) return;

	long unsigned int i;
	for (i=0; i<arr_len; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');

	return;
}

// swaps two values in an array
void swap(int *a, int *b)
{
	// make temp and switch
	int *temp = a;
	a = b;
	b = temp;
	return;
}

void quicksort(int *arr, int *pivot, int *left, int *right)
{
	// base case: if arr_len is 1
	if (pivot == left) return;

	// base case: if arr_len is 2
	if (pivot+1 == right) {
		// sorting this array
		if (*left > *right) swap(left, right);
		return;
	}

	// setting an end pointer
	int *right_end = right;

	// while loop to test left and right pointers
	while ((left <= right) && (left <= right_end) && (right >= pivot)) {
		// iterate left pointer
		while (1) {
			if (*left >= *pivot) break;
			if (left == right_end) break;
			left++;
		}

		// iterate right pointer
		while (1) {
			if (*right <= *pivot) break;
			if (right == pivot) break;
			right++;
		}


	}

	// swap pivot and right pointer
	swap(pivot, right);

	// call recursion
	
}



int main()
{
	// array I am testing on
	long unsigned int arr_len = 8;
	int *arr = (int *)malloc(arr_len*sizeof(int));
	arr[0] = 5;
	arr[1] = 3;
	arr[2] = 8;
	arr[3] = 1;
	arr[4] = 4;
	arr[5] = 6;
	arr[6] = 2;
	arr[7] = 7;

	// print original array
	puts("Original array is:\n");
	print_array(arr, arr_len);

	// get pivot, left and right pointer
	int *pivot = arr;
	int *left = arr + 1;
	int *right = arr + arr_len - 1;

	// begin sorting

	return 0;
}




