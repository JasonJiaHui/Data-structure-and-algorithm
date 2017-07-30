#include <iostream>
#include <vector>

using namespace std;

void init(vector<int> &vec)
{
	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(8);
	
}

int main(void)
{
	vector<int> vec;

	cout << "vec.size: " << vec.size() << endl;

	init(vec);

	cout << "vec.size: " << vec.size() << endl;
	
	return 0;	
}
