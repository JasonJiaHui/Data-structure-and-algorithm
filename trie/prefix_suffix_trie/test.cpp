#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
	

void test(vector<int> vec)
{
	int i;
	for(i = 0; i < vec.size(); i++){
		cout << "ele: " << vec[i] << endl;
	}

}

int main(void)
{
	int i;
	string str = "hello";
	
	for(i = 0; i < str.length(); i++){
		string a = str.substr(i);
	
		printf("%s\n", a.c_str());
		//cout << "str: " << a << endl;
	}

	return 0;
}



int main2(void)
{
	vector<int> vec;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	test(vec);

	return 0;
}


int main1(void)
{

	stack<int> mystack;

	mystack.push(1);
	mystack.push(2);
	mystack.push(3);
	
	while(!mystack.empty()){
		cout << "ele: " << mystack.top() << endl;
		mystack.pop();
	}

	return 0;
}
