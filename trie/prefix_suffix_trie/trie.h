#ifndef _TRIE_H
#define _TRIE_H

#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

#define MAX 26
using namespace std;


class Node
{
public:
	Node* next[MAX];
	Node* prev;
	
	int count;
	int wordCount;
	bool endFlag;
	char alpha;
	bool redundantFlag;
};

class Trie
{
public:
	Node* head;

public:
	Trie()
	{
		head = createNew();
	}

	~Trie()
	{
		delete head;
	}
	
	Node* createNew();
	void insertStr(const char *str);
	int search(const char* str);
	int findAll();
	void findWordIndex(Node* node, int *p, int index, int k);
	void findWord();
	int checkMul(Node* node);
	void print(Node* node);	
	void printWord(Node* current);
	void sort(vector<Node*> vec);
	void traverse(int maxFlag);
};

#endif
