#ifndef _HUFFMAN_H
#define _HUFFMAN_H

class Node
{
public:
	int id;
	int weight;
	char key;
	Node* prev;
	Node* left;
	Node* right;
	bool NYT_flag;
	bool internal_flag;	
};


class FGK
{
public:
	Node* head;

public:
	FGK()
	{
		head = createNew();
	}
	~FGK()
	{
		delete head;
	}

	Node* createNew();
	Node* findNYTNode();
	Node* findByKey(char key);
	void swap(Node* node, Node* leader);
	Node* findBlockLeader(Node* node);
	void update(Node* node);
	void insert(char key);
};

#endif
