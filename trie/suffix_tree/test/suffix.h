#ifndef _SUFFIX_H
#define _SUFFIX_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
	vector<Node*> vec;
	string str;
	bool terminal;

};

class SuffixTree
{
public:
	Node* head;	

public:
	SuffixTree()
	{
		head = createNew();
	}
	~SuffixTree()
	{
		delete head;
	}
	
	Node* createNew();
	void insert(const char *str);
	bool search(const char *str);
};

#endif
