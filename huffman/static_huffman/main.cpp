#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "huffman.h"

using namespace std;

//extern void DFS(stack<int>);
extern void test(Node*, stack<Node*>);

/*void test(stack<int> s)
{
	cout << "enter..." << endl;

}
*/

struct cmp
{
	bool operator()(Node *&node1,Node *&node2)
	{
		return node1->weight > node2->weight;
	}

};


int main(void)
{
	priority_queue<Node*, vector<Node*>, cmp> pq;

	stack<Node*> s;
	
	Huffman huffman;

	Node* node1 = huffman.createNew();
	node1->weight = 10;
	node1->content = 'a';


	Node* node2 = huffman.createNew();
	node2->weight = 1;
	node2->content = 'b';
	

	Node* node3 = huffman.createNew();
	node3->weight = 2;
	node3->content = 'c';

	
	Node* node4 = huffman.createNew();
	node4->weight = 2;
	node4->content = 'd';

	Node* node5 = huffman.createNew();
	node5->weight = 2;
	node5->content = 'e';

	Node* node6 = huffman.createNew();
	node6->weight = 15;
	node6->content = 'f';

	pq.push(node1);
	pq.push(node2);
	pq.push(node3);
	pq.push(node4);	
	pq.push(node5);	
	pq.push(node6);	

	Node* current = NULL;
	Node* temp1 = NULL;
	Node* temp2 = NULL;

	while(!pq.empty()){

		if(huffman.checkHead()){
		
			temp1 = pq.top();
		 	pq.pop();
			temp2 = pq.top();
			pq.pop();
			
			cout << "insert first two: node1: " << temp1->weight << " node2: " << temp2->weight << endl;
			current = huffman.insertTwo(temp1, temp2);
		}
		// must attention!!!  else Segment fault.....	
		if(pq.size() >= 2){

			temp1 = pq.top();
			pq.pop();
			temp2 = pq.top();
			pq.pop();
		
			if(temp2->weight <= current->weight){
				cout << "insert sequence two: node1: " << temp1->weight << " node2: " << temp2->weight << endl;
				current = huffman.insertTwo(temp1, temp2);
			}else{
				pq.push(temp2);
				cout << "insert one: node1: " << temp1->weight << endl;
				current = huffman.insertOne(temp1);
			}
		}else{
			temp1 = pq.top();
			pq.pop();
			current = huffman.insertOne(temp1);
		}
	}


/*	Node* node7 = huffman.createNew();
	node7->weight = 31;
	node7->content = 'g';
*/


/*
	current = huffman.insertTwo(node2, node3);
	cout << "current: " << current->weight << endl;
	

	current = huffman.insertTwo(node4, node5);
	cout << "current: " << current->weight << endl;

//	huffman.insertOne(node1);
//	huffman.insertOne(node6);

	cout << "main DFS traverse..." << endl;
//	stack<int> s;

//	test(huffman.getHead(), s);
		
*/
	huffman.DFS();
	

	cout << "get code==========" << endl;
	
/*
	int i;
	char buf[10];
	for(i = 1; i < 7; i++){
		sprintf(buf, "%d", i);
		string str = buf;

		string name = "node" + str;
		
		huffman.getCode(name);
	}	
*/
	huffman.getCode(node1);	

	return 0;
}
