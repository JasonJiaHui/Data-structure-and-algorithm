#include <stdio.h>
#include "link.h"

void print_item(link p)
{
	printf("%d\n", p->item);
}


int main(void)
{
	link head, p;  // struct node *head;
	link_init(&head); //head => null

	p = make_node(3);
	link_insert(&head, p);   //head insert

	p = make_node(5);
	link_insert(&head, p);   //head insert
	p = make_node(1);
	link_insert(&head, p);   //head insert
	p = make_node(8);
	link_insert(&head, p);   //head insert
	
	link_travel(&head, print_item);  //traverse and print linklist

	printf("=============\n");


	p = link_search(&head, 1);

	if(p != NULL)
	{
		link_delete(&head, p);
		free_node(p);
	}

	link_travel(&head,print_item);  //traverse and print linklist
	
	link_destroy(&head);
	return 0;	

}

