/*
Nate Mankovich
1/19/2016
linked_list.c

singly linked list in C
*/



#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

ll_node_p ll_add_front(ll_node_p curr_node, float x)
{

	//add the node if it is not empty
	ll_node_p new_node = (ll_node_p)malloc(sizeof(*curr_node));
	new_node->data = x;
	new_node->next = curr_node;
	return new_node;
}

void ll_print(ll_node_p n)
{
	if (!n)
	{
		//the list is empty
		printf("%s\n", "[empty list]");
	}
	else
	{
		//printing the list
		while (n!= NULL)
		{
			printf("%f", n->data);
			if (n->next == NULL)
			{
				//formatting
				printf("%s\n", " -|");
				n = n->next;
			}
			else
			{
				//formatting
				printf("%s", " -> ");
				n = n->next;
			}
		}
	}
}

void ll_free(ll_node_p n)
{
	if (n != NULL)
	{
		//recurse throught the list
		ll_free(n->next);
	}
	//free jah memory
	free(n);
}

ll_node_p ll_rev_copy(ll_node_p n)
{
	ll_node_p rev_ll = NULL;

	while (n != NULL)
	{
		rev_ll = ll_add_front(rev_ll, n->data);

		n = n->next;
	}

	return rev_ll;
}

ll_node_p ll_rev(ll_node_p curr) 
{
	//reverses the list by just messing with pointers
	//deal with the head pointers (new tail)
	ll_node_p prev = NULL;
	ll_node_p nxt = curr->next;
	//the while loop deals with the rest of the list 
	//until curr is the NULL pointer of the last node
	while (curr != NULL)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}

	//returns the new head of the list
	return prev;
}


