#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <list>
#include <string.h>

using namespace std;

class Record
{
public:
	int position;
	char symbol;
	int matching;
	int lessThan;

};

int getMatching(string str, char character)
{	
	int count = 0;
	if(str == ""){
		return count;
	}

	int i;
	for(i = 0; i < str.size(); i++){
		if(str.at(i) == character){
			count++;
		}
	}

	return count;
}	

void getLessThan(string str, set<char> &myset, vector<int> &lessThanVector)
{


	int i, j;
	set<char>::iterator it;
	vector<int> temp;
	for(it = myset.begin(); it != myset.end(); it++){
		int count = 0;
		for(i = 0; i < str.size(); i++){
			if(str.at(i) == *it){
				count++;
			}
		}
		temp.push_back(count);
	}
	
	int count;
	for(i = 0; i < temp.size(); i++){
		count = 0;

		if(i == 0){
			count = 0;
		}else{
			for(j = 0; j < i; j++){
				count += temp[j];
			}
		}
		lessThanVector.push_back(count);
	}	
}


void init(vector<Record*> &vec, string str)
{
	int position, index;
	string substr;
	Record* rec = NULL;
	for(position = 0; position < str.size(); position++){
		rec = new Record;
		rec->position = position;
		rec->symbol = str.at(position);
		substr = str.substr(0, position);
		rec->matching = getMatching(substr, str.at(position));

		vec.push_back(rec);
	}

	//init lessThan table
	set<char> myset;
	set<char>::iterator it;

	for(position = 0; position < str.size(); position++){
		myset.insert(str.at(position));
	}
		
	vector<int> lessThanVector;

	getLessThan(str, myset, lessThanVector);

	index = 0;
	int j;
	int NumLessThan;
	for(it = myset.begin(); it != myset.end(); it++){
	
		for(position = 0; position < vec.size(); position++){
			if((*it) == vec[position]->symbol){
				vec[position]->lessThan = lessThanVector[index];
			}
		}
		index++;
	}
}

// note that code here should use &! to transfer addr
void decode(vector<Record*> &vec, char end, string &code)
{
	list<char> res;
	
	int index, position;
	
	for(index = 0; index < vec.size(); index++){
		if(vec[index]->symbol == end){
			position = vec[index]->matching + vec[index]->lessThan;
			break;
		}
	}

	res.push_front(end);

	while(position != index){
		res.push_front(vec[position]->symbol);
		position = vec[position]->matching + vec[position]->lessThan;
	}

	list<char>:: iterator it;

	for(it = res.begin(); it != res.end(); it++){
		code += *it;
	}		
}



int main(void)
{
	vector<Record*> vec;

	string str;
	cout << "please input code: " << endl;
	cin >> str;

	string res;

	init(vec, str);
	
	decode(vec, ']', res);

	cout << "res: " << res << endl;
	
	return 0;
}
