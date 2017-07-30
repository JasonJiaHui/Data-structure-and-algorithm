#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(string str1, string str2)
	{	
		return str1 > str2;
	}
};

string rotate(string str, int index)
{
	string res;

	string front = str.substr(index);	
	string back = str.substr(0, index);

	res = front + back;
	
	return res;
}
	
int main(int argc, char *argv[])
{
	string input;

	cout << "Please input string: " << endl;
	cin >> input;
	

	string temp = "";
	string res = "";
	string str = input;
	priority_queue<string, vector<string>, cmp> pq;

	int i;
	for(i = str.size(); i > 0; i--){
		temp = rotate(str, i);
		pq.push(temp);
	}
	
	while(!pq.empty()){
		
		char character = pq.top().at(str.size() - 1);
		res += character;
		pq.pop();
	}

	cout << "bwt res: " << res << endl;

	
	return 0;
}
