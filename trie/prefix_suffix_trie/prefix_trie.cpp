#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include "trie.h"

using namespace std;

#define MAX 26

/*
create trie O(log26 N)
use more space to get more efficiency

Still has some problems
	1. when input str, we should based on the increase order eg, ab, abc, abf

*/

int main(void)
{
	cout << "initialise..." << endl;

	Trie *trie = new Trie;

//	Node* head = createNew();
	trie->insertStr("ab");	

	trie->insertStr("abc");	
	trie->insertStr("abc");	
	trie->insertStr("abc");	
	trie->insertStr("abd");	
	trie->insertStr("abd");	
	trie->insertStr("abe");	


/*	insertStr("abf", head);	
	insertStr("abf", head);
	insertStr("abf", head);
	insertStr("abf", head);	
*/

/*	insertStr("ab", head);	
	insertStr("ab", head);
	insertStr("ab", head);
	insertStr("ab", head);	
*/	
	trie->traverse(2);

	return 0;
}




int main1(void)
{
	cout << "initialise..."<< endl;
//	cout << "input: abcdefg" << endl;
//	cout << "search: cde" << endl;
	
//	Node *head = createNew();
	//insertStr("bcde", head);
	//insertStr("bcfg", head);

	//insertStr("ab", head);

/*
	insertStr("ab", head);	
	insertStr("abd", head);
	insertStr("abch", head);
	insertStr("abch", head);
	insertStr("abcj", head);
	insertStr("abcil", head);
	insertStr("abcim", head);
	insertStr("abcin", head);
	insertStr("abcin", head);
	insertStr("abcin", head);
	

	traverse(head, 0);
*/

//	findWord(head);


//	insertStr("nat", head);
//	insertStr("nao", head);
	


/*	cout << "all string: " << head->count << endl;

	int res = search("abch", head);

	if(0 == res){
		cout << "not find..." << endl;
	}else{
		cout << "abch: find number: " << res << endl;
	}
*/	


	return 0;
}	
