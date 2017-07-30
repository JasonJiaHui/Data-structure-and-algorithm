#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Node
{
public:
	std::vector<Node*> *vec;
	string str;

	Node()
	{
		vec = new vector<Node*>(5);
	}
};

//std::vector<Node*> Node::vec;

class Test
{
public:
	Node* head;

public:	
	Test()
	{
		head = createNew();
	}

	Node* createNew()
	{
		Node* node = new Node;
		node->str = "head";
		return head;
	}

	void insert(string str)
	{
		Node* current = head;
		Node* node = new Node;
		node->str = str;
		cout << "111111" << endl;
		current->vec.push_back(node);
		cout << "push head success..." << endl;

		cout << "head vec size: " << head->vec.size() << endl;
	}
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
	
	Node* createNew()
	{
		Node* node = new Node;
	//	std::vector<Node*> myvec;
	//	node->vec = myvec;
		//node->vec = NULL;
		node->str = "";
		//cout << "here" << endl;
	}

	void insert(string str)
	{
		//cout << "here" << endl;
		Node *node = new Node;
		node->str = str;
		*(head->vec).push_back(node);
		cout << "push_back into head success..." << endl;
		cout << "insert  vec size: " << head->vec.size() << endl;
	}

	void traverse()
	{

		cout << "traverse..." << endl;
		Node* current = head;
		int len = current->vec.size();
		cout << "vec size: " << len << endl;
		int i;
		for(i = 0; i < len; i++){
			cout << current->vec[i]->str << endl;
		}	
	}
	
};


void contains(string src, string dest)
{
	if(dest.find(src) != string::npos){
		
		cout << "contain completly..." << endl;
		return;
	}
	
	int i, index = -1;
	bool flag = false;
	int len = src.length();

	for(i = 0; i < len; i++){
		if(dest[i] == src[i]){
			flag = true;
			index = i;
		}else{
			flag = false;
		}
	}

	if(!flag){
		if(index != -1){
			cout << "find common at index: " << index << endl;
		}else{
			cout << "not have common..." << endl;
		}
	}
}

int main(void)
{
	string str1 = "hello";
	
	string a = str1.substr(2);
	
	cout << "a: " << a << endl;

	return 0;

}


int main5(void)
{
	Test* t = new Test;
	t->insert("hello");

	cout << "main success..." << endl;
	return 0;
}

int main4(void)
{
	Node* node = new Node;
	Node* node1 = new Node;
	Node* node2 = new Node;
	node1->str = "node1";
	node2->str = "node2";	

	node->vec.push_back(node1);
	node->vec.push_back(node2);
	
	int i;
	for(i = 0; i < node->vec.size(); i++){
		cout << node->vec[i]->str << endl;
	}
		

	cout << "success..." << endl;
	return 0;
}


int main2(void)
{
	vector<Node*> vec;
	
	cout << "init vec len: " << vec.size() << endl;

	Node *n1 = new Node;
	n1->str = "hello";
	vec.push_back(n1);

	Node *n2 = new Node;
	n2->str = "hi";
	vec.push_back(n2);

	cout << "vec len: " << vec.size() << endl;
	
	return 0;
}


int main3(void)
{
	Trie *t = new Trie;
	
	t->insert("hello");
	t->insert("good");
	t->insert("morning");

	t->traverse();

	return 0;

}




int main1(void)
{
	string str1 = "abf";
	string str2 = "abcd";

	contains(str1, str2);
/*
	if(str2.find(str1) != string::npos){
		cout << "find..." << endl;
	}else{
		cout << "not find..." << endl;
	}

	cout << "content: " << str2[1] << endl;

	cout << "str2 len: " << str2.length() << endl;
*/

	return 0;
}
