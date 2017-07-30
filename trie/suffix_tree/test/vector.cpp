#include <iostream>
#include <string>
#include <vector>

//error:
// 当A类 调用 B类中的 vector 存储数据时  报错！！！
// vector 的实例化问题

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

/*
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
		head->vec.push_back(node);
		cout << "push head success..." << endl;

		cout << "head vec size: " << head->vec.size() << endl;
	}
};
*/

/*
int main0(void)
{
	Test* t = new Test;
	t->insert("hello");

	cout << "main success..." << endl;
	return 0;
}
*/

int main(void)
{
	string str1 = "hello";
	
	string a = str1.substr(2);
	
	cout << "a: " << a << endl;

	return 0;

}

int main0(void)
{
	Node* node = new Node;
	Node* node1 = new Node;
	Node* node2 = new Node;
	node1->str = "node1";
	node2->str = "node2";	

	node->vec->push_back(node1);
	node->vec->push_back(node2);
	
	int i;
	for(i = 0; i < node->vec->size(); i++){
		cout << node->vec[i]->str << endl;
	}
		

	cout << "success..." << endl;
	return 0;
}

/*
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
*/


