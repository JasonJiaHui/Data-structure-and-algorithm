#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

void DLinkList::insertLast(Node *node)
{
	if(head->next == tail){
	
		node->pre = head;
		node->next = tail;
		head->next = node;
		tail->pre = node;			

		std::cout <<"first: " << node->data << std::endl;
		return;
	}

	Node *current = head;
	while(current->next != tail){
		current = current->next;
	}
	
	node->pre = current;
	node->next = tail;
	current->next->pre = node;
	current->next = node;

	std::cout <<"last: " << node->data << std::endl;
	//printf("insert last: %s\n", node->data);
}

void DLinkList::traverseHead()
{
	if(head == NULL || head->next == tail){
		printf("empty\n");
		return;
	}


	printf("traversing...");
	Node *node = head;
	while(node != tail){
		printf("data: %s\n", node->data);
		node = node->next;
	}

}

void DLinkList::traverseTail()
{
	if(tail->pre == head){
		std::cout << "Empty DLinkList..." << std::endl;
		return;
	}

	Node *current = tail;
	while(current != head){
		printf("data: %s\n", current->data);
		current = current->pre;
	}		
}

void DLinkList::insertAfter(Node *src, Node *dst)
{
	Node *current = head;
	while(current != src){
		current = current->next;
	}


	dst->pre = current;
	dst->next = current->next;
	current->next->pre = dst;
	current->next = dst;

	std::cout << "insert success..." << std::endl;
}

void DLinkList::destroy()
{
	Node *current = head;
	Node *temp = NULL;
	while(current != tail){
		temp = current->next;
		
		std::cout << "free....addr: " << current << std::endl;
		free(current);
		current = temp;
	}
	
	std::cout << "free success..addr: " << current << std::endl;
	free(current);
}



