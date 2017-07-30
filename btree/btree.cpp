#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
#include "btree.h"

using namespace std;

Node *prev;
Node *node = NULL;


void BTree::setRoot(Node *root)
{
	this->root = root;
}


Node * BTree::getRoot()
{
	return root;
}

void BTree::setRootData(char* data)
{
	this->root->data = data;
}

void sort(char *p)
{
	int len = strlen(p);
	int i,j;
	char temp;
	for(i = len - 1; i > 0; i--){
		for(j = 0; j < i; j++){
			if(p[j] > p[j+1]){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;	
			}
		}
	}

}

//error...
Node* BTree::initWithStr(char *str, int start, int end)
{
	if(start > end){
		return NULL;
	}
	int mid = (start + end) / 2;

	root = new Node(&(str[mid]));	

	root->left = initWithStr(str, start, mid - 1);
	root->right = initWithStr(str, mid + 1, end);
	
	cout << "str: " << str[mid] << endl;	
	cout << "init success mid .root: " << mid << root->data <<  endl;

	
		
	return root;
}

void BTree::insertNode(Node *node)
{
	if(root == NULL){
		root = node;
		return;
	}	
	
	Node *parent;
	Node *current = root;
	while(1){
		parent = current;
		
		if(strcmp(current->data, node->data) > 0){
			current = current->left;
			if(!current){
				parent->left = node;
				node->parent = parent;
//				cout << "insert left" << endl;
				return;
			}
		}else{
			current = current->right;
			if(!current){
				parent->right = node;
				node->parent = parent;
//				cout << "insert right" << endl;
				return;
			}
		}	
	}
}

Node* BTree::search(char *str)
{
	Node *current = root;
	while(strcmp(current->data, str) != 0){
		if(strcmp(current->data, str) > 0){
			current = current->left;
		}else if(strcmp(current->data, str) < 0){
			current = current->right;
		}
		
		if(current == NULL){
			cout << "return NULL..." << endl;
			return NULL;
		}
	}
	cout << "return Node..." << endl;
	return current;
}


void BTree::preOrder(Node *node)
{
	if(node == NULL){
		return;
	}
	std::cout << "pre traverse: " << node->data << std::endl;
	preOrder(node->left);
	preOrder(node->right);
}

void BTree::inOrder(Node *node)
{
	if(node == NULL){
		return;
	}
	inOrder(node->left);
	std::cout << "in traverse: " << node->data << std::endl;

/*
	if(!node->left){
		node->ltag = true;
		node->left = prev;
	}	
	if(!prev->right){
		prev->rtag = true;
		prev->right = p;
	}
	prev = p;
*/
	inOrder(node->right);
}

void BTree::traverse(Node *node)
{
	


} 

void BTree::postOrder(Node *node)
{
	if(node == NULL){
		return;
	}

	postOrder(node->left);
	postOrder(node->right);
	std::cout << "post traverse: " << node->data << std::endl;
	
}

void BTree::levelOrder()
{
	queue<Node*> myqueue;
	if(root == NULL){
		cout << "empty..." << endl;	
		return;
	}
	
	myqueue.push(root);
	while(!myqueue.empty()){
		Node *temp = myqueue.front();
		cout << "data: " << temp->data << endl;
		myqueue.pop();
		if(temp->left != NULL){
			myqueue.push(temp->left);
		}
		if(temp->right != NULL){
			myqueue.push(temp->right);
		}
	}
}

void BTree::depthOrder()
{
	stack<Node*> mystack;
	if(root == NULL){
		cout << "empty..." << endl;
		return;
	}	
	
	mystack.push(root);
	while(!mystack.empty()){
		Node *temp = mystack.top();
		cout << "data: " << temp->data << endl;
		mystack.pop();	
	
		if(temp->right != NULL){
			mystack.push(temp->right);
		}
		if(temp->left != NULL){
			mystack.push(temp->left);
		}
	}
}



Node* leftMost(Node* node)
{
	if(node->left == NULL){
		return node;
	}else{
		while(node->left != NULL){
			node = node->left;
		}
		return node;
	}
}

Node* BTree::inSuccessor(Node* node)
{
	if(node->right != NULL){
		cout << "right..." << endl;
		return leftMost(node->right);
	}else{
		while(node->parent->right == node){
			node = node->parent;
		}	
		return node->parent;
	}
}

bool BTree::deleteNode(Node* node)
{
	Node* current = root;
	Node* parent = root;
	bool isLeft = false;
	
	//find this node;
	while(current != node){
		parent = current;
		if(strcmp(current->data, node->data) > 0){
			isLeft = true;	
			current = current->left;
		}else{
			isLeft = false;
			current = current->right;
		}
		if(current == NULL){
			return false;
		}	
	}	
	
	//case1:all are left node;
	if(current->left == NULL && current->right == NULL){
		if(current == root){
			root = NULL;
		}else{
			if(isLeft){
				parent->left = NULL;
			}else{
				parent->right = NULL;
			}
		}
	//case2:
	}else if(current->left == NULL || current->right == NULL){
		if(current->right == NULL){
			if(root == current){
				root = current->left;
			}else{
				if(isLeft){
					parent->left = current->left;
				}else{
					parent->right = current->left;
				}
			}
		}else if(current->left == NULL){
			if(root == current){
				root = current->right;
			}else{
				if(isLeft){
					parent->left = current->right;
				}else{
					parent->right = current->right;
				}
			}
		}	
	//case 3: has left and right subnodes;
	}else{
		Node *successor = inSuccessor(current);
	
		//make the successor be null
		Node *parentSuccessor = successor->parent;
		if(strcmp(parentSuccessor->data, successor->data) > 0){
			parentSuccessor->left = NULL;
		}else{
			parentSuccessor->right = NULL;
		}		

		if(current == root){
			root = successor;
		}else{
			if(isLeft){
				parent->left = successor;
			}else{
				parent->right = successor;
			}
		}
		
		// link the left and right of successor...
		successor->left = current->left;
		successor->right = current->right;
		
	}
	return true;
}

int checkHeight(Node* node)
{
	if(node == NULL){
		return 0;
	}
	
	int leftHeight = checkHeight(node->left);
	if(leftHeight == -1){
		return -1;
	}

	int rightHeight = checkHeight(node->right);
	if(rightHeight == -1){
		return -1;
	}

	int diffHeight = abs(leftHeight - rightHeight);
	if(diffHeight > 1){
		return -1;	
	}else{
		return max(leftHeight, rightHeight) + 1;
	} 
}

bool BTree::isBalanced()
{
	int height = checkHeight(root);
	if(height == -1){
		return false;
	}
	return true;
}

bool cover(Node* root, Node* dst)
{
	if(root == NULL){
		return false;
	}
	if(root == dst){
		return true;
	}	
	return cover(root->left, dst) || cover(root->right, dst);
}

Node* LCAHelper(Node* root, Node *n1, Node* n2)
{
	if(root == NULL){
		return NULL;
	}
	if(root == n1 || root == n2){
		return root;
	}
	
	bool n1_left = cover(root->left, n1);
	bool n2_left = cover(root->left, n2);

	if(n1_left != n2_left){
		return root;
	}
	
	Node* childSide = n1_left ? root->left : root->right;
	
	return LCAHelper(childSide, n1, n2);
}


Node* BTree::findLCA(Node* node1, Node* node2)
{
	if(!cover(root, node1) || !cover(root, node2)){
		return NULL;
	}

	return LCAHelper(root, node1, node2);
}

bool match(Node* root1, Node* root2)
{

	if(root1 == NULL && root2 == NULL){
		cout << "both are null..." << endl;
		return true;
	}
	if(root1 == NULL || root2 == NULL){

		return false;
	}
	if(strcmp(root1->data, root2->data) != 0){
		cout << "data not same..." << endl;
		return false;
	}
	
	// should consider all the alternatives...
	if(root2->left != NULL && root2->right != NULL){
		return (match(root1->left, root2->left) && match(root1->right, root2->right));
	}else if(root2->left != NULL && root2->right == NULL){
		return (match(root1->left, root2->left));
	}else if(root2->left == NULL && root2->right != NULL){
		return (match(root1->right, root2->right));
	}else{
		return true;
	}	
}

bool subTree(Node* root1, Node* root2)
{

	if(root1 == NULL){
		return false;
	}
	if(strcmp(root1->data, root2->data) == 0){
		if(match(root1, root2)){
			return true;
		}
	}
	return (subTree(root1->left,root2) || subTree(root1->right, root2));
}



bool contains(BTree tree1, BTree tree2)
{
	Node* root1 = tree1.getRoot();
	Node* root2 = tree2.getRoot();

	if(root2 == NULL){
		return true;
	}
	return subTree(root1, root2);	
}



