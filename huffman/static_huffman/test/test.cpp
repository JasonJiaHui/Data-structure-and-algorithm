#include <iostream>
#include <queue>
#include <string>
#include <stack>



using namespace std;

class Node
{
public:
	int num;
	string name;
};

void fun1(stack<Node*> &s)
{
	Node* node = s.top();
	cout << "num: " << node->num << endl;
}

int main(void)
{
	int i;
	string s;
	char buf[10];
	for(i = 0; i < 5; i++){
		
		sprintf(buf, "%d", i);

		string str = buf;
	
		s = "n" + str;

		cout << "string: " << s << endl;		
	}

}


int main2(void)
{
	stack<Node*> s;
	
	Node* n1 = new Node;
	n1->num = 10;	

	Node* n2 = new Node;
	n2->num = 20;
	
	s.push(n1);
	s.push(n2);
	
	fun1(s);

	return 0;
}



int main1(void)
{

	string str;
	
	int i;
	for(i = 0; i < 5; i++){
		if(i % 2){
			str += 48;
			continue;
		}
		str+= 49;
	}

	cout << "str: " << str << endl;

	return 0;
}
