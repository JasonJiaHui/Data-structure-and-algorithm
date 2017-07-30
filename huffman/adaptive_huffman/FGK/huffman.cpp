#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "huffman.h"

using namespace std;

static int id(256);

/*
struct cmp
{
	bool operator()(Node* &node1, Node* &node2)
	{
		return node1->id < node2->id;
	}

};
*/


Node* FGK::createNew()
{
	Node* node = new Node;
	
	node->id = id;
	node->weight = 0;
	node->key = ' ';
	node->prev = NULL;
	node->left = NULL;
	node->right = NULL;
	node->NYT_flag = true;
	node->internal_flag = false;
	
	id--;

	return node;
}

Node* FGK::findNTYNode()
{
	// DFS search...
	if(head->NYT_flag){
		return head;
	}

	stack<Node*> mystack;
	Node* current = head;	
	mystack.push(current);

	while(!mystack.empty()){
		current = mystack.top();
		mystack.pop();

		if(current->NYT_flag){
			cout << " Found NYT success..." << endl;
			return current;
		}
	
		if(current->right != NULL){
			mystack.push(current->right);
		}	
		if(current->left != NULL){
			mystack.push(current->left);
		}
	}
	return NULL;
}


Node* FGK::findByKey(char key)
{
	// DFS search...
	if(head->NYT_flag){
		cout << " empty FGK tree..." << endl;
		return;
	}

	stack<Node*> mystack;
	Node* current = head;	
	mystack.push(current);

	while(!mystack.empty()){
		current = mystack.top();
		mystack.pop();

		if(key == current->key){
			cout << " Found node success..." << endl;
			return current;
		}
	
		if(current->right != NULL){
			mystack.push(current->right);
		}	
		if(current->left != NULL){
			mystack.push(current->left);
		}
	}
	return NULL;
}

// still has some problems...
// how to swap the node: 1. address  OR 2.value
// how to decide the actual largest numbering...
void FGK::swap(Node* node, Node* leader)
{
	


}


Node* FGK::findBlockLeader(Node* node)
{
	if(head->NYT){
		cout << "empty FGK tree..." << endl;
		return;
	}

	int weight = node->weight;
		
	queue<Node*> myqueue;
	queue<Node*> destQueue;
	
//	priority_queue<Node*, vector<node*>, cmp> pq;

	Node* current = head;
	myqueue.push(current);

	while(!myqueue.empty()){
		current = myqueue.front();
		myqueue.pop();

		
		if(weight > current->weight){
			break;
		}		

		// need to do some optimisation...
		if(weight == currrent->weight){
			destQueue.push(current);
		}
		
		if(current->right != NULL){
			myqueue.push(current->right);
		}
		if(current->left != NULL){
			myqueue.push(current->left);
		}
	}	

	if(destQueue.size() != 0){
		return destQueue.front();
	}else{
		return NULL;
	}

}



void FGK::update(Node* node)
{

	Node* leader = findBlockLeader(node);

	if(leader != node){
		swap(node, leader);
	}



}


void FGK::insert(char key)
{
/*	if(head->NYT_flag){
		Node* right = createNew();
		Node* left = createNew();

		head->NYT = false;
		head->internal_flag = true;

		right->key = key;
		right->NYT_flag = false;
		
		head->left = left;
		left->prev = head;
		head->right = right;
		righ->prev = head;
		
		return;
	}
*/


	Node* parent = NULL;
	Node* current = NULL;
	
	current = findByKey(key);

	if(current == NULL){
		current = findNYTNode();

		//create left and right node;
		Node* right = createNew();
		Node* left = createNew();
	
		current->NYT_flag = false;
		current->weight += 1;
		current->internal_flag = true;	


		right->weight += 1;
		right->key = key;
		right->NYT_flag = false;

		current->left = left;
		left->prev = current;	
		current->right = right;
		right->prev = current;

		if(current != head){
			update(current->prev);
		}	

	}else{
		
		
	}




}
