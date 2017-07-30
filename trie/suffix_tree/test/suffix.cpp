#include <iostream>
#include <string>
#include <vector>
#include "suffix.h"

using namespace std;

Node* SuffixTree::createNew()
{
	Node* node = new Node;
	vector<Node*> myvec;
	node->vec = myvec;
	node->string = NULL
	node->terminal = false;	

}

int contains(Node* node, string str)
{
	if(str.find(node->string) != string::npos){
		return node->string.length() - 1;
	}
	int i, index = -1;
	bool flag = false;
	int len = node->string.length();
	for(i = 0; i < len; i++){
		if(str[i] == node->string[i]){
			flag = true;
			index = i;
		}else{
			flag = false;
		}
	}
	
	if(!flag){
		if(index != -1){
			cout << "find common at index: " << index << endl;	
			return index;	
		}else{
			return -1;
		}
	}
}


void SuffixTree::insert(string str)
{
	int len = head->vec.size();
	
	if(len == 0){
		Node* node = createNew();
		node->string = str;
		node->terminal = true;
		head->vec.push_back(node);

		cout << "push first node success..." << endl;
		return;
	}
	
	int i;
	bool containFlag = false;
	Node* current = head;
	for(i = 0; i < len - 1; i++){
		if(str.find(current->vec[i]->string) != string::npos){
			
		}
	}

}
