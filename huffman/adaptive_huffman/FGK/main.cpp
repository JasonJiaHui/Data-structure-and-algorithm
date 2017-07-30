#include <iostream>
#include "huffman.h"

using namespace std;

int main(void)
{
	FGK tree;

	Node* node1 = tree.createNew();
	Node* node2 = tree.createNew();


	cout << "node1.id: " << node1->id << endl;
	cout << "node2.id: " << node2->id << endl;
		

	return 0;
}
