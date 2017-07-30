#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
	int weight;
	char content;
};

struct cmp
{

	bool operator()(Node *&a,Node *&b)
	{
		return a->weight < b->weight;
	}

};


int main(void)
{
	priority_queue<Node*,vector<Node*>, cmp> pq;
	
	Node* n1 = new Node;
	Node* n2 = new Node;
	Node* n3 = new Node;
	
	n1->weight = 10;
	n2->weight = 20;
	n3->weight = 0;

	pq.push(n1);
	pq.push(n2);
	pq.push(n3);
		
	while(!pq.empty()){
		cout << pq.top()->weight << endl;
		pq.pop();
	}

	return 0;
}
