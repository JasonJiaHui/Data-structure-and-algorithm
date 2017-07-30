#include <iostream>
#include <string.h>
#include <string>
#include "huffman.h"


using namespace std;


int main9(void)
{
	string str = "";

	str += 48;

	cout << "code: " << str << endl;


	return 0;
}


int main(void)
{
	Vitter vitter;

	char buf[30] = {"abacabdabaceabacabdfg"};
	//char buf[10] = {"abcdefg"};	

	int i;
	for(i = 0; i < strlen(buf); i++){
//		cout << " key: " << buf[i] << endl;

		vitter.insert(buf[i]);	
	}

	cout << "=========yy=================================================================================" << endl;
	vitter.traverse();

	vitter.getCode('a');
	//string code_a = NULL;
	//code_a = vitter.getCode('a');
	//cout << "a_code: " << code_a << endl;

	return 0;

}




int main0(void)
{
	Vitter vitter;
	
	vitter.insert('a');
	

	vitter.insert('b');
	vitter.insert('c');
	cout << "=========yy=================================================================================" << endl;
	vitter.insert('d');

	cout << "*****************" << endl;
	vitter.traverse();
	cout << "*****************" << endl;	

	return 0;
}



int main1(void)
{
	Vitter vitter;

	vitter.insert('a');
	vitter.insert('b');	
	vitter.insert('b');	
	cout << "******************************************************" << endl;
	vitter.insert('b');	
	vitter.insert('b');	
	vitter.insert('b');	

//	vitter.insert('b');	
//	vitter.insert('b');	
//	vitter.insert('b');	
//	vitter.insert('b');	
	vitter.insert('a');


	
	cout << "main traverse..." << endl;
	vitter.traverse();
	cout << "main end..." << endl;

	return 0;
}
