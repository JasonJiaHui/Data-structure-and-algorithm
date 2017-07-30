#include <iostream>
#include "linklist.h"

using namespace std;

int main(void)
{
	DLinkList *list = new DLinkList;

	list->traverseHead();
	
	Node *n1 = new Node;
	n1->data = "hello";
	n1->next = NULL;
	n1->pre = NULL;
	cout << "n1 addr: " << n1 << endl;
	list->insertLast(n1);

	Node *n2 = new Node;
	n2->data = "good";
	n2->next = NULL;
	n2->pre = NULL;
	cout << "n2 addr: " << n2 << endl;
	list->insertLast(n2);

	Node *n3 = new Node;
	n3->data = "morning";
	n3->next = NULL;
	n3->pre = NULL;
	cout << "n3 addr: " << n3 << endl;
	list->insertLast(n3);
	

	list->traverseHead();

	list->destroy();
/*
	cout << "***************" << endl;

	list->traverseHead();

	cout << "***************" << endl;

	list->traverseTail();


	Node *n4 = new Node;
	n4->data = "fuck";
	n4->next = NULL;
	n4->pre = NULL;
	list->insertAfter(n2, n4);
	

	cout << "***************" << endl;

	list->traverseHead();

	cout << "***************" << endl;

	list->traverseTail();
*/
	return 0;
}
