#ifndef _LINKLIST_H
#define _LINKLIST_H

class Node
{
public:
	char *data;
	Node *next;
	Node *pre;

};


class DLinkList
{
private:
	Node *head;
	Node *tail;

public:
	DLinkList()
	{
		head = new Node;
		tail = new Node;
		std::cout << "head addr: " << head << std::endl;
		std::cout << "tail addr: " << tail << std::endl;

		head->data = NULL;
		head->next = tail;
		tail->data = NULL;
		tail->pre = head;
	}

	void insertLast(Node *node);
	void traverseHead();
	void traverseTail();
	void insertAfter(Node *src, Node *dst);
	void destroy();

};

#endif
