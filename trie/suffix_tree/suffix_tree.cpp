#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
	vector<Node*> vec;
	string str;
	bool terminal;

};

Node* createNew()
{
	Node* node = new Node;
	node->str = "";
	node->terminal = false;
}

/*
void insert(Node* head, string str)
{
	Node* node = new Node;
	node->str = str;
	node->terminal = true;

	head->vec.push_back(node);
	cout << "push head vec success..." << endl;
}
*/

void DFSsearch(Node* head)
{
	if(head->vec.size() == 0){
		cout << "empty suffix tree..." << endl;
		return;
	}
	
	int i;

	stack<Node*> mystack;
	mystack.push(head);

	while(!mystack.empty()){
		Node* current = mystack.top();
		mystack.pop();
		
		cout << "==>ele: " << current->str << endl;

		for(i = 0; i < current->vec.size(); i++){
			mystack.push(current->vec[i]);
		}
	}
}


void traverse(Node* head)
{
	int i;
	int len = head->vec.size();
		
	for(i = 0; i < len; i++){
		cout << "content: " << head->vec[i]->str << endl;
	}
}


int contains(Node* node, string str)
{
	cout << "contains:  node->str: " << node->str << " str: " << str << endl;


	int i, index = -1;
	bool flag = false;
	int len = node->str.length();
	for(i = 0; i < len; i++){
		if(str[i] == node->str[i]){
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
	}else{
		cout << "complete contain..." << endl;
		return index;
	}
}


bool search(const char *str)
{
	

}

Node* findNodeBasedParent(Node* parent, string str)
{
	int i;
	for(i = 0; i < parent->vec.size(); i++){
		if(parent->vec[i]->str == str){
			return parent->vec[i];
		}
	}

}



void insert(Node* head, string str)
{

	cout << "node str: " << head->str << " input str: " << str << endl;

	int len = head->vec.size();
	
	if(len == 0){
		Node* node = new Node;
		node->str = str;
		node->terminal = true;
		head->vec.push_back(node);
	

		cout << "push first success..." << endl;	
		return;
	}
	
	int i, index = -1;
	bool containFlag = false;
	Node* current = head;
	for(i = 0; i < len; i++){
		if((index = contains(current->vec[i], str)) >= 0){
			containFlag = true;
			break;
		}
	}
	
	
	if(containFlag){
		if(index == current->vec[i]->str.length() - 1){
		
			if(current->vec[i]->vec.size() == 0){
				current->vec[i]->str = str;
				cout << "deal with contain completely with no child success update" << endl;
			}else{
				insert(current->vec[i], str.substr(index+1));

				cout << "1111" << endl;
			}
	

/*			Node* node = current->vec[i];
			if(node->vec.size() == 0){
				node->vec[i]->str = str;
			}else{
				Node* newNode = new Node;
				newNode->
			}	
			current->vec[i]->str = str;
*/		
			cout << "complete contain, updataed..." << endl;
	
		}else{

			if(current->vec[i]->vec.size() == 0){
			//	cout << "111" << endl;	
				
				string nodeNextStr = current->vec[i]->str.substr(index+1);		
				current->vec[i]->str = current->vec[i]->str.substr(0, index+1);

				cout << "node str: " << current->vec[i]->str << endl;
				insert(current->vec[i], nodeNextStr);
				insert(current->vec[i], str.substr(index+1));
					
				cout << "partly contain with no child..." << endl;
			}else{

				vector<Node*> savedVec = current->vec[i]->vec;
				string nodeNextStr = current->vec[i]->str.substr(index+1);
				current->vec[i]->str = current->vec[i]->str.substr(0, index+1);
				
				//clear
				current->vec[i]->vec.clear();
				cout << "clear success..." << endl;
				insert(current->vec[i], nodeNextStr);
				insert(current->vec[i], str.substr(index+1));
							
				cout << "insert child node success..." << endl;

				Node* child = findNodeBasedParent(current->vec[i], nodeNextStr);
				
				cout << "find child node success..." << endl;				

				child->vec = savedVec;
				
				cout << "connect child node and savedVec success..." << endl;				

			}
		
			cout << "partly contain until index: " << index << endl;
		}
	}else{
		
		Node* node = new Node;
		node->str = str;
		node->terminal = true;
		current->vec.push_back(node);
		cout << "no contain, need to create new node..." << endl;
	}

}

/*
some error when use createNew to get a Node*
especially about vec.size()!!!!

int main(void)
{
	Node *head = new Node;
	Node *head1 = createNew();	

	cout << "head size: " << head->vec.size() << endl;
	cout << "head1 size: " << head1->vec.size() << endl;
	
	
	return 0;
}
*/


int main0(void)
{
	Node* head = new Node;
	
	insert(head, "abcd");
	insert(head, "abcf");
	insert(head, "abk");
//	insert(head, "abe");

	cout << "main end..." << endl;

	return 0;
}


int main(void)
{
	Node* head = new Node;

	string str = "apple";
	int i;
	for(i = str.length() - 1; i >= 0; i--){
		string a = str.substr(i);
		cout << "main str: " << a << endl;	
	
		insert(head, a);
	}

	cout << "init success..." << endl;
	
	cout << " DFS traverse..." << endl;

	DFSsearch(head);

	return 0;

}


int main1(void)
{
	Node* head = new Node;
	
	insert(head, "hello");
	insert(head, "good");

	traverse(head);

	
	return 0;
}
