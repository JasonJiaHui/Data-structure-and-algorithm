#ifndef _LINK_H_
#define _LINK_H_

typedef struct node *link;
struct node{
	int item;
	link next;
};

void link_init(link *head);
link make_node(int item);
void link_insert(link *head, link p);
link link_search(link *head, int key);
void link_delete(link *head, link p);
void free_node(link p);
void link_modify(link p, int key);
void link_destroy(link *head);
void link_travel(link *head, void (*visit)(link));
#endif

