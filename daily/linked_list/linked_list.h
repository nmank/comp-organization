/*
Nathan Mankovich
1/20/2016

Linked list.h file (has the node struct)
*/

typedef struct ll_node_s ll_node_t;
typedef ll_node_t *ll_node_p;

//this is a node
struct ll_node_s
{
	//the link
	ll_node_p next;
	//the data
	float data;
};

ll_node_p ll_add_front(ll_node_p n, float x);
void ll_free(ll_node_p n);