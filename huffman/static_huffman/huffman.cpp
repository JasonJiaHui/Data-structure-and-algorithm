#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include "huffman.h"

using namespace std;

//static stack<int> s;

//stack<int> Huffman::s;
Node* Huffman::getHead()
{
	return head;
}

bool Huffman::checkHead()
{
	if(head->left == NULL){
		return true;
	}

	return false;
}

Node* Huffman::createNew()
{
	Node* node = new Node;
	node->content = ' ';
	node->weight = 0;
	node->prev = NULL;
	node->left = NULL;
	node->right = NULL;
	node->code = ""; 
	return node;
}

Node* Huffman::insertTwo(Node* n1, Node* n2)
{
	bool rightFlag = false;
	
	Node* node = createNew();

	int parentWeight = n1->weight + n2->weight;
	node->weight = parentWeight;	

	if(n1->weight <= n2->weight){
		node->left = n1;
		node->right = n2;
	}else{
		node->left = n2;
		node->right = n1;
	}	
	
	n1->prev = node;
	n2->prev = node;
	
	if(head->left == NULL)
	{
		head->left = node;
		std::cout << "adjust node as the left..." << std::endl;
	}else if(node->weight >= head->left->weight){
		head->right = node;
		cout << "adjust node as the right..." << endl;
		rightFlag = true;
	}	
	
	node->prev = head;

	if(rightFlag){
		node = mergeTwoChild();
	}
	cout << "init first two node success...weight: " << node->weight << endl;
	return node;
}

Node* Huffman::insertOne(Node* node)
{
	Node* newNode = createNew();
	int mergeWeight = 0;
	// no right child

	mergeWeight = head->left->weight + node->weight;
	newNode->weight = mergeWeight;

	if(node->weight >= head->left->weight){
		newNode->left = head->left;
		newNode->right = node;
	}else{
		newNode->left = node;
		newNode->right = head->left;
	}	
	node->prev = newNode;
	head->left->prev = newNode;
		
	head->left = newNode;
	newNode->prev = head;

	cout << "inner insert one success..." << endl;


	return newNode;
}

Node* Huffman::mergeTwoChild()
{
	Node* node = createNew();
	
	int parentWeight = head->left->weight + head->right->weight;

	node->weight = parentWeight;

	node->left = head->left;
	node->right = head->right;
	
	node->left->prev = node;
	node->right->prev = node;
		
	node->prev = head;
	head->left = node;
	
	head->right = NULL;

	cout << "merge two child success..." << endl;	
	return node;
}

void Huffman::DFS()
{
	if(head->left == NULL){
		cout << "empty huffman tree..." << endl;
		return;
	}

	stack<Node*> mystack;
	Node* current  = head;
	mystack.push(current);

	while(!mystack.empty()){
	
	
		current = mystack.top();
		mystack.pop();

		cout << "node: " << current->content << " " << current->weight << endl;

		if(current->right != NULL){
			mystack.push(current->right);
		}
		if(current->left != NULL){	
			mystack.push(current->left);
		}
	}
}

void Huffman::getCode(Node* node)
{
	stack<int> reverseCode;
	string code;
	
	Node* temp = NULL;
	Node* current = node;
	while(current->prev != head){
	
		cout << "current weight: " << current->weight << endl;
	
		temp = current->prev;
		if(temp->left == current){
			reverseCode.push(48);
		}else if(temp->right == current){
			reverseCode.push(49);
		}
		current = temp;
	}
	
	while(!reverseCode.empty()){
		code += reverseCode.top();
		reverseCode.pop();
	}
	
	node->code = code;
	cout << "code: " << code << endl;
}
