#ifndef _BTREE_H
#define _BTREE_H
#include <iostream>

using namespace std;

class Node
{
public:
	char *data;
	Node *left;
	Node *right;
	Node *parent;	

	bool ltag;
	bool rtag;

	Node(char* data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
	Node()
	{
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}

	
};


class BTree
{
private:
	Node *root;

public:
	BTree()
	{
		root = new Node;
	}
	BTree(char *str)
	{
		root = initWithStr(str, 0, strlen(str) - 1);
	}

	//note that, if we use delete in ~function, maybe some bugs...would be difficult to deal with...
	
//	~BTree()
//	{
//		cout << "~BTree()" << endl;
//		delete root;
//	}
	Node *getRoot();
	void setRoot(Node *root);
	void setRootData(char*data);
	
	Node* initWithStr(char *str, int start, int end);

	void insertNode(Node *node);
	Node* search(char *data);
	
	void preOrder(Node *node);
	void inOrder(Node *node);
	void postOrder(Node *node);
	void traverse(Node *node);
	void levelOrder();
	void depthOrder();

	bool deleteNode(Node* node);
	Node* inSuccessor(Node* node);
	bool isBalanced();
	Node* findLCA(Node* node1, Node* node2);
		
};



#endif
