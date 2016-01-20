/*
Nate Mankovich
1/20/2016
linked_list_test.c

test the singly linked list

by commenting and un-commenting lines of code
it is possible to check each of the required functionalities
*/

#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

int main( int argc, char **argv)
{
	ll_node_p full = ll_add_front(NULL, 4.1);
	full = ll_add_front(full, 2.3);
	full = ll_add_front(full, 0.1);


	//print the list
	ll_print(full);

	//reverse and copy
	ll_node_p full_rev_copy = ll_rev_copy(full);

	//print the newreverse list
	ll_print(full_rev_copy);

	//reverse in place
	ll_node_p full_rev = ll_rev(full);

	//print reversed
	ll_print(full_rev);

	//linked list is free
	ll_free(full);
	ll_free(full_rev_copy);
	ll_free(full_rev);

	return 0;
}
