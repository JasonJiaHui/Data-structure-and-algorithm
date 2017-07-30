#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <vector>
#include <string>

using namespace std;

class Node
{
public:
	int weight;
	char key;
	Node* prev;
	Node* left;
	Node* right;
	bool NYT_flag;
	bool internal_flag;	
};


class Vitter
{
public:
	Node* head;

public:
	Vitter()
	{
		head = createNew();
	}
	~Vitter()
	{
		delete head;
	}


	Node* createNew();
	Node* copyNode(Node* node);
	Node* findNYTNode();
	Node* findByKey(char key);
	void findSwapLeaf(Node* leaf, vector<Node*> &vec);
	void findSwapInternal(Node* internal, vector<Node*> &vec);
	Node* findLeaderBlock(Node* node);
	void shift(Node* src, Node* dst);
	void swap(Node* node, Node* leader);
	Node* leftShift(vector<Node*> &vec, Node* src);
	Node* slide_increment(Node* node);
	void insert(char key);
	
	string getCode(char key);
		
	void traverse();
};

#endif
