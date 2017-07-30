#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include "huffman.h"

using namespace std;

vector<Node*> vec;

Node* Vitter::createNew()
{
	Node* node = new Node;
	
	node->weight = 0;
	node->key = ' ';
	node->prev = NULL;
	node->left = NULL;
	node->right = NULL;
	node->NYT_flag = true;
	node->internal_flag = false;
	
	return node;
}

Node* Vitter::copyNode(Node* src)
{
	Node* node = new Node;

	node->weight = src->weight;
	node->key = src->key;
	node->prev = src->prev;
	node->left = src->left;
	node->right = src->right;
	node->NYT_flag = src->NYT_flag;
	node->internal_flag = src->internal_flag;

	return node;
}

Node* Vitter::findNYTNode()
{
	// DFS search...
	if(head->NYT_flag){
		cout << "findNYTNode return head..." << endl;
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


Node* Vitter::findByKey(char key)
{
	// DFS search...
	if(head->NYT_flag){
		cout << " empty FGK tree..." << endl;
		return NULL;
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

void Vitter::findSwapLeaf(Node* leaf, vector<Node*> &vec)
{

	if(head->NYT_flag){
		cout << "empty Vitter tree..." << endl;
		return;
	}

	// need to consider
	if(leaf == head){
		cout << "this node is head, just return itself..." << endl;
		vec.push_back(leaf);
		return;
	}


	int weight = leaf->weight;

	queue<Node*> myqueue;
	Node* current = head;
	myqueue.push(current);

	while(!myqueue.empty()){
		current = myqueue.front();
		myqueue.pop();

		// internal flag && leaf
		if(weight == current->weight){
//			cout << "push leaf block success..." << endl;
			vec.push_back(current);
		
			if(leaf == current){
				return;
			}
		
		}

		if(current->right != NULL){
			myqueue.push(current->right);
//			cout << "swap leaf push right success..." << endl;
		}
		if(current->left != NULL){
			myqueue.push(current->left);
//			cout << "swap leaf push left success..." << endl;
		}
	}
}

void Vitter::findSwapInternal(Node* internal, vector<Node*> &vec)
{
	// need to check head situation

	if(head->NYT_flag){
		cout << "empty Vitter tree..." << endl;
		return;
	}

	//need to consider
	if(internal == head){
		cout << "this internal is head, just return itself..." << endl;
		vec.push_back(internal);
		return ;
	}

	int weight = internal->weight + 1;
		
	queue<Node*> myqueue;
	Node* current = head;
	myqueue.push(current);

	// need do some modification, weight 5, 4, 1 but we should find weight 2...
	while(!myqueue.empty()){
		current = myqueue.front();
		myqueue.pop();
	
		if(weight == current->weight && !current->internal_flag){
//			cout << "push ok internal node..." << endl;
			vec.push_back(current);
		}
		
		// need to add more check...
		// if there are no more weight = weight we need to return itself...

		if(internal == current){
//			cout << "push internal itself success..." << endl;
			vec.push_back(internal);
			return;
		}
		

		if(current->right != NULL){
			myqueue.push(current->right);
//			cout << "swap internal push right success..." << endl;
		}
		if(current->left != NULL){
			myqueue.push(current->left);
//			cout << "swap internal push left success..." << endl;
		}
	}


}

Node* Vitter::findLeaderBlock(Node* node)
{
	cout << "enter find leader block..." << endl;
	if(head->NYT_flag){
//		cout << "empty Vitter tree..." << endl;
		return NULL;
	}

	queue<Node*> myqueue;
	Node* current = head;
	myqueue.push(current);

	while(!myqueue.empty()){
		current = myqueue.front();
		myqueue.pop();

		if(current->internal_flag == node->internal_flag && current->weight == node->weight){
			cout << "find leader block success..." << endl;
			return current;
		}

		if(current->weight < node->weight){
			cout << "not find leader block..." << endl;
			return NULL;
		}

		if(current->right != NULL){
			myqueue.push(current->right);
		}
		if(current->left != NULL){
			myqueue.push(current->left);
		}
	}
}


void Vitter::shift(Node* src, Node* dst)
{
		
	Node* dstParent = dst->prev;
	bool dst_left_flag = false;
	
	if(dst->prev->left == dst){
//		cout << "left flag..." << endl;
		dst_left_flag = true;
	}

//	cout << "head->right: " << head->right->key << " weight" << head->right->weight << " addr: " << head->right << endl;
	if(dst_left_flag){
		cout << "===>>set parent left" << endl;
		dstParent->left = src;
		
	}else{
		dstParent->right = src;
	}
	src->prev = dstParent;

}

void Vitter::swap(Node* src, Node* dst)
{
	cout << "enter swap ..." << endl;

	Node* srcParent = src->prev;
	Node* dstParent = dst->prev;

	bool src_left_flag = false;
	bool dst_left_flag = false;

	if(src->prev->left == src){
		src_left_flag = true;
	}
	if(dst->prev->left == dst){
		dst_left_flag = true;
	}

	//swap dest node
	if(dst_left_flag){
		dstParent->left = src;
		
	}else{
		dstParent->right = src;
	}
	src->prev = dstParent;
	
	//swap src node
	if(src_left_flag){
		srcParent->left = dst;
	}else{
		srcParent->right = dst;
	}
	dst->prev = srcParent;
	
}


// some problems when to shift left...
Node* Vitter::leftShift(vector<Node*> &vec, Node* src)
{
	//swap first;
	// here need to copy, not just use the some addr
	// we should not only use the pointer
	// if we change the pointer, the other variable
	// referenced with pointer 

	Node* newDst = copyNode(vec[0]);
	
	if(vec[0]->prev->left == vec[0]){
		vec[0]->prev->left = newDst;
	}else{
		vec[0]->prev->right = newDst;
	}

	//left shift <==
	int i;
	for(i = vec.size() - 2; i >= 0; i--){
		Node* temp = copyNode(vec[i]);

		shift(temp, vec[i+1]);
//		shift(vec[i], vec[i+1]);
		cout << "leftShift==> swap tail to head success..." << endl;
	}

	// swap head
	shift(src, newDst);

	return src;
}


Node* Vitter::slide_increment(Node* node)
{
	Node* prev_parent = node->prev;

	vector<Node*> vec;
	
	if(node->internal_flag){
		//note that this should be used left shift <-- not use swap!!!
		
		findSwapInternal(node, vec);	

		if(vec.size() != 0 && vec[0] != node){
			if(vec.size() == 2){
				swap(node, vec[0]);
			}else{
				leftShift(vec, node);
			}
		}

		node->weight += 1;
		node = prev_parent;

	}else{
		//note that this should be used left shit <--  not use swap!!!!!
			
		findSwapLeaf(node, vec);
		
		if(vec.size() != 0 && vec[0] != node){
			if(vec.size() == 2){
				swap(node, vec[0]);
			}else{
				//node = leftShift(vec, node);
				leftShift(vec, node);
			}

		}

		node->weight += 1;
		node = node->prev;
	}


	return node;
}


void Vitter::insert(char key)
{

	Node* parent = NULL;
	Node* leaf_to_increment = NULL;
	
	parent = findByKey(key);

	if(parent == NULL){

		parent = findNYTNode();

		//create left and right node;
		Node* right = createNew();
		Node* left = createNew();
	
		parent->NYT_flag = false;
		parent->internal_flag = true;	

		right->key = key;
		right->NYT_flag = false;

		parent->left = left;
		left->prev = parent;	
		parent->right = right;
		right->prev = parent;

		leaf_to_increment = right;
		
	}else{
		Node* leaderBlock = findLeaderBlock(parent);
		if(leaderBlock != parent){
			// need to double check
			// whether need the return value
			swap(parent, leaderBlock);
		}	

		if(parent->prev->left->NYT_flag){
			leaf_to_increment = parent;
			parent = parent->prev;
		}
	}

	while(parent != NULL){
		parent = slide_increment(parent);	
	}
		
	if(leaf_to_increment != NULL){
		slide_increment(leaf_to_increment);
		cout << "insert leaf success..." << endl;
	}
}

string Vitter::getCode(char key)
{

	string code  = "";
	
	if(head->NYT_flag){
		code = "ascii";
		return code;
	}	

	stack<int> reverseCode;		
	Node* current = findByKey(key);
	
	while(current != head){
		if(current->prev->left == current){
		//	cout << "put 0 success..." << endl;
			reverseCode.push(48);
		}else if(current->prev->right == current){
		//	cout << "put 1 success..." << endl;
			reverseCode.push(49);
		}

		current = current->prev;
	}

	while(!reverseCode.empty()){

		cout << "reverseCode.top(): " << reverseCode.top() << endl;
		code += reverseCode.top();

		cout << "code: " << code << endl;
		reverseCode.pop();
	}

	cout << "getCode: ==> code: " << code << endl;
	
	return code;
}


void Vitter::traverse()
{
	if(head->NYT_flag){
		cout << "empty Vitter tree..." << endl;
		return;
	}

	queue<Node*> myqueue;
	Node* current = head;
	myqueue.push(current);

	while(!myqueue.empty()){
		current = myqueue.front();
		myqueue.pop();
	
		cout << "key: " << current->key << " weight: " << current->weight << endl;

		if(current->left != NULL){
			myqueue.push(current->left);
		}
		
		if(current->right != NULL){
			myqueue.push(current->right);
		}

	}
}
