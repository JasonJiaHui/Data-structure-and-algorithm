#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	cout.precision(15);

	long double a = 1.23456789012;

	cout << "a: " << a << endl;

	cout << "? " << (0.0 == 0) << endl;

	return 0;
}


int main0(void)
{
	string str = "bill gate";

	int arr[256] = {0};

	int i;
	for(i = 0; i < str.length(); i++){
		arr[str.at(i)]++;
	}
	
	for(i = 0; i < 256; i++){
		if(arr[i] != 0){
			cout << "char: " << (char)i << "cout: " << arr[i] << endl;
		}
	}	
	
	return 0;
}
