#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	cout << "max(1,3) = " << max(1,3) << endl;
	cout << "abs(-5) = " << abs(-5) << endl;
	return 0; 
}


int main1(void)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while(!q.empty()){
		cout << "data: " << q.front() << endl;
		q.pop();
	}

	return 0;
}
