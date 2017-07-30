#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include "trie.h"

#define MAX 26
using namespace std;

Node* Trie::createNew()
{
	int i;
	Node *node = new Node;
	for(i = 0; i < MAX; i++){
		node->next[i] = NULL;
	}
	node->prev = NULL;

	node->alpha = ' ';
	node->count = 0;
	node->wordCount = 0;
	node->endFlag = false;	

	node->redundantFlag = false;
	return node;
}

void Trie::insertStr(const char* str)
{
	int i;
	int len = strlen(str);
	
	Node* temp = NULL;
	Node* current = head;
	
	for(i = 0; i < len; i++){
		int index = str[i] - 'a';
		if(current->next[index] == NULL){
			temp = createNew();
			current->next[index] = temp;
			
			temp->prev = current;
	
			current->count++;
			current = current->next[index];
			
			current->alpha = str[i];			

			if(i == len - 1){
				current->endFlag = true;
				current->count++;
				current->wordCount++;
			}
				
		}else{
			current->count++;
			current = current->next[index];
			
			if(i == len - 1){
				current->count++;
				current->wordCount++;
			}
		}
	}
}

int Trie::search(const char* str)
{
	int i, count;
	int len = strlen(str);

	Node* current = head;
	for(i = 0; i < len; i++){
		int index = str[i] - 'a';
		if(current->next[index] != NULL){
			current = current->next[index];
			count = current->count;
		}else{
			cout << "Not find..." << endl;
			return 0;
	
		}
	}

	return count;
}

int Trie::findAll()
{
	return head->count;
}


void Trie::findWordIndex(Node* node, int *p, int index, int k)
{
	Node* current = node;
	
	if(current->endFlag){
		p[index] = k;
		return;
	}
	
	p[index] = k;
	
	int i;
	for(i = 0; i < 26; i++){
		if(current->next[i] != NULL && !current->endFlag){
			cout << "my index: " << i << endl;
			findWordIndex(current->next[i], p, index+1, i);
		}
	}
}

void Trie::findWord()
{
	int index[10] = {-1};
	
	findWordIndex(head, index, -1, -1);
	
	int i;
	for(i = 0; i < 10; i++){
		cout << "index: " << index[i] << endl;
	}

}

int Trie::checkMul(Node* node)
{
	int i, count = 0;
	for(i = 0; i < 26; i++){
		if(node->next[i] != NULL){
			count++;
		}
	}
	
	return count;

}

void Trie::print(Node* node)
{
	cout << "alpha: " << node->alpha << endl;
}


void Trie::printWord(Node* current)
{
	if(head == NULL){
		cout << "empty word..." << endl;
		return;
	}

	Node* temp = current;
	
	stack<Node*> mystack;
	while(temp != head){
		mystack.push(temp);
		temp = temp->prev;
	}

	while(!mystack.empty()){
		temp = mystack.top();
		print(temp);
		mystack.pop();
	}
	
	cout << "this word count: " << current->wordCount << endl;
}

void Trie::sort(vector<Node*> vec)
{
	int i, j;
	int len = vec.size();
	
	for(i = len - 1; i >= 0; i--){
		for(j = 0; j < i; j++){
			if(vec[j]->wordCount > vec[j+1]->wordCount){
				Node* temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
		}
	}

	cout << "sorted success..." << endl;
	for(i = 0; i < len; i++){
		printWord(vec[i]);
		cout<< "*****" << endl;
	}	
};

void Trie::traverse(int maxFlag)
{
	int i;
	if(head == NULL){
		cout << "empty trie..." << endl;
		return;
	}

	stack<Node*> mystack;
	mystack.push(head);

	Node* temp = NULL;
	Node* maxNode = createNew();

	vector<Node*> vec;


	while(!mystack.empty()){
		Node* current = mystack.top();
		mystack.pop();
		
		if(!maxFlag){
			print(current);
		}

		if(current->endFlag && !current->redundantFlag){
			if(maxFlag == 1){
				if(maxNode->count < current->count){
					maxNode = current;
				}
			}else if(maxFlag == 0){
				cout << "current char num: " << current->count << endl;
				cout << "*****" << endl;
			}else if(maxFlag == 2){
				vec.push_back(current);	
			}
		}
	
		if(!current->redundantFlag){
			int count = checkMul(current);
			for(i = MAX - 1; i >= 0; i--){
				if(current->next[i] != NULL){
					count--;
					mystack.push(current->next[i]);
					temp = current;
					if(count != 0 || temp->endFlag){
						while(temp != head){
							temp->redundantFlag = true;
							mystack.push(temp);
							temp = temp->prev;
						}
					}
				}
			}
		}
	}
	if(maxFlag == 1){
		printWord(maxNode);
	}else if(maxFlag == 2){
		sort(vec);		
	}

}



