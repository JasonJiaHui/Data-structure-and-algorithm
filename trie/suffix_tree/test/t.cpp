#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vec1;

	
	vec1.push_back(1);
	vec1.push_back(2);

	vector<int> vec2 = vec1;	


//	vec2 = vec1;

	int i;
	for(i = 0; i < vec2.size(); i++){
		cout << vec2[i] << endl;
	}

	return 0;
}



int main1(void)
{
	string str1 = "hello";
	
	string a = str1.substr(2);
	
	cout << "a: " << a << endl;

	return 0;

}
