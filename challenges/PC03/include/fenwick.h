// Name: Danielle Croft
// E-mail: dcroft@nd.edu
// File name: fenwick.h
// Date created: 2/14/22
// File contents: This is the function declarations for PC03

int *create_array(const char *argv[], long unsigned int num_inputs);

void print_menu(void);

int get_choice(void);

void print_array(int *the_array, long unsigned int array_len);

int *make_fenwick(int* array, long unsigned int length);

void update_fenwick(int *array, int *fenwick, long unsigned int array_len);

void sum_vals(int *fenwick);

// this is a function I added--it takes the user's selection and decides what function to execute
void execute_user_choice(int user_choice, int *array, int *fenwick, long unsigned int array_len);
