#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include "btree.h"

using namespace std;

extern void sort(char *);
extern Node* leftMost(Node*);
extern bool contains(BTree, BTree);


int main4(void)
{
	
	BTree tree;
	tree.setRootData("M");
	
	Node *n1 = new Node("H");
	Node *n2 = new Node("N");
	Node *n3 = new Node("O");
	
	tree.insertNode(n1);
	tree.insertNode(n2);
	tree.insertNode(n3);
	
	BTree tree2;
	tree2.setRootData("M");
	Node *n21 = new Node("N");
	Node *n22 = new Node("O");
	
	tree2.insertNode(n21);
//	tree2.insertNode(n22);

	
	if(contains(tree, tree2)){
		cout << "contain..." << endl;
	}else{
		cout << "Not contain..." << endl;
	}

}



int main(void)
{
	BTree tree;
	tree.setRootData("M");
	
	Node *n1 = new Node("H");
	Node *n2 = new Node("N");
	Node *n3 = new Node("C");

	Node *n4 = new Node("L");
	Node *n5 = new Node("J");
	Node *n6 = new Node("I");

	tree.insertNode(n1);
	tree.insertNode(n2);
	tree.insertNode(n3);
	tree.insertNode(n4);
	tree.insertNode(n5);
	tree.insertNode(n6);


	BTree tree2;
	tree2.setRootData("H");
	
	Node *n21 = new Node("A");
	Node *n22 = new Node("L");
	
	tree2.insertNode(n21);
	tree2.insertNode(n22);

//	tree2.inOrder(tree2.getRoot());


	if(contains(tree, tree2)){
		cout << "contain..." << endl;
	}else{
		cout << "Not contain..." << endl;
	}


//	cout << "LCA: " << tree.findLCA(n3, n6)->data << endl;


//	if(tree.isBalanced()){
//		cout << "balanced..." << endl;
//	}else{
//		cout << "Not Balanced..." << endl;
//	}


//	cout << "level order..." << endl;
//	tree.levelOrder();

//	tree.deleteNode(n1);
//	cout << "delete level order..." << endl;
//	tree.levelOrder();
//	cout << "successor: " << tree.inSuccessor(n1)->data << endl;
	
//	tree.inOrder(tree.getRoot());
	//tree.levelOrder();

	//cout << "left most: " << leftMost(n4)->parent->data << endl;
	

	return 0;
}



int main2(void)
{

	BTree tree;
		
	tree.setRootData("D");
		
	Node *n1 = new Node("B");
	Node *n2 = new Node("F");
	Node *n3 = new Node("C");
	Node *n4 = new Node("E");

	tree.insertNode(n1);
	tree.insertNode(n2);	
	tree.insertNode(n3);
	tree.insertNode(n4);	


	if(tree.search("E")){
		cout << "found..." << endl;
	}

/*	cout << "inOrder" << endl;
	tree.inOrder(tree.getRoot());


	cout << "preOrder" << endl;
	tree.preOrder(tree.getRoot());

	cout << "levelOrder" << endl;
	tree.levelOrder();
*/
	return 0;
}


/*
int main1(void)
{

	BTree tree;

	tree.setRootData("a");
	
	Node *n1 = new Node("b");
	Node *n2 = new Node("c");
	Node *n3 = new Node("d");
	Node *n4 = new Node("e");
	Node *n5 = new Node("f");
	Node *n6 = new Node("g");
	Node *n7 = new Node("h");
	Node *n8 = new Node("i");

	tree.getRoot()->left = n1;
	tree.getRoot()->right = n2;

	n1->left = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->right = n8;	
	
	cout << "preOrder..." << endl;
	tree.preOrder(tree.getRoot());

	cout << "inOrder..." << endl;
	tree.inOrder(tree.getRoot());

	cout << "postOrder..." << endl;
	tree.postOrder(tree.getRoot());
	
	cout << "levelOrder..." << endl;
	tree.levelOrder();

	cout << "depthOrder..." << endl;
	tree.depthOrder();
	
	return 0;

}
*/
