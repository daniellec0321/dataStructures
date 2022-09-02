#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
	int data;
	struct list_node *next_node;
} list_node;

typedef struct head_node {
	struct list_node *head_node;
} dllist;



void push(dllist *the_list, int value)
{
	// malloc a node
	list_node *insert_node = (list_node *)malloc(sizeof(list_node));
	insert_node->data = value;
	insert_node->next_node = NULL;

	// check if list is empty
	if (the_list->head_node == NULL) {
		the_list->head_node = insert_node;

		return;
	}

	// save head pointer in a reference
	list_node *reference = the_list->head_node;

	// making the insert node the head node
	the_list->head_node = insert_node;

	// making insert_node then point to old head node
	the_list->head_node->next_node = reference;

	return;
}

void print_dllist(dllist *the_list)
{
	list_node *curr_ptr = the_list->head_node;

	while (curr_ptr != NULL) {
		printf("%d ", curr_ptr->data);
		curr_ptr = curr_ptr->next_node;
	}

	putchar('\n');

	return;
}



int main()
{
	// mallocing a list
	dllist *the_list = (dllist *)malloc(sizeof(dllist));
	the_list->head_node = NULL;

	// creating array that I will push and pop
	int arr[] = {0, 1, 2, 3, 4};

	// push all of the values here
	int i;
	for (i=0; i<5; i++) {
		push(the_list, arr[i]);

		// print list
		print_dllist(the_list);
	}

	return 0;
}
