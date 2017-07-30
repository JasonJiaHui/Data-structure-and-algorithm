#include <iostream>
#include <string.h>
#include <string>
#include "trie.h"

using namespace std;

int main(void)
{
	string str;
	Trie *trie = new Trie();	
	cin >> str;	
	
	int i;
	for(i = str.length() - 1; i >= 0; i--){
		string a = str.substr(i);
		trie->insertStr(a.c_str());
	}

	cout << "init success..." << endl;

	trie->traverse(0);	


	string pattern;
	
	while(1){

		cout << "please input search pattern" << endl;
		cin >> pattern;
		
		if(pattern == "quit"){
			break;
		}	
		
		int res = trie->search(pattern.c_str());
		if(res == 0){
			cout << "Not find..." << endl;
		}else{
			cout << "Find...res: " << res << endl;
		}
	}


	return 0;
}
