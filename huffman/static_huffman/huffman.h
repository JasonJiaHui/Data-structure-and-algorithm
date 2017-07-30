#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <string>
#include <stack>

using namespace std;

class Node
{
public:
	char content;
	int weight;
	Node* prev;
	Node* left;
	Node* right;
	string code;
};

class Huffman
{
public:
	Node* head;
//	static stack<int> s;
public:
	Huffman()
	{
		head = createNew();
		head->content = '$';
	}
	~Huffman()
	{
		delete head;
	}
	Node* getHead();
	bool checkHead();	
	Node* createNew();
	Node* insertTwo(Node* n1, Node* n2);
	Node* insertOne(Node* node);
	Node* mergeTwoChild();
	void DFS();

	void getCode(Node* node);
};

#endif

