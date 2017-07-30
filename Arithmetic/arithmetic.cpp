#include <iostream>
#include <vector>
#include <string>
#include "arithmetic.h"

using namespace std;

void ArithmeticTable::initialise(string code)
{
	
	int i;
	double totalCount = 0;
	double prob = 0.0;
	double lrange = 0.0;
	double hrange = 0.0;
	int hash[256] = {0};

	Record* record;	

	for(i = 0; i < code.length(); i++){
		hash[code.at(i)]++;	
		totalCount++;
	}

	for(i = 0; i < 256; i++){
		if(hash[i] != 0){
			prob = hash[i] / totalCount;
			lrange = hrange;
			hrange += prob;

			record = new Record((char)i, prob, lrange, hrange);
	
			records.push_back(record);
			
			cout << "char: " << (char)i << " prob: " << prob << " lrange: " << lrange << " hrange: " << hrange << endl;
			cout << "push success..." << endl;
		}
	}
}

Record* ArithmeticTable::getRecord(char ch)
{
	int i;
	for(i = 0; i < records.size(); i++){
		if(records[i]->Character == ch) return records[i];
	}
	return NULL;
}

void ArithmeticTable::setEncodeValue(char ch, double lValue, double hValue)
{
	Record* record = getRecord(ch);
	record->lValue = lValue;
	record->hValue = hValue;

}

void ArithmeticTable::encode(string code)
{	
	int i;
		
	Record* record;
	double lValue = 0.0;
	double hValue = 1.0;
	double codeRange = 0.0;

	for(i = 0; i < code.length(); i++){
		record = getRecord(code.at(i));
		codeRange = hValue - lValue;
		hValue = lValue + codeRange * (record->highRange);
		lValue = lValue + codeRange * (record->lowRange);
	
		cout.precision(10);
		cout << "char: " << code.at(i) << " lValue: " << lValue << " hValue: " << hValue << endl;
	}

}

Record* ArithmeticTable::getRecord(double num)
{
	int i;
	for(i = 0; i < records.size(); i++){
		if(num >= records[i]->lowRange && num < records[i]->highRange){
			return records[i];
		}
	}
	return NULL;
}


void ArithmeticTable::decode(double num)
{
	Record* record;
	
	while(num > 0){
		record = getRecord(num);
		num = (num - record->lowRange) / (record->highRange - record->lowRange);
		cout << "char: " << record->Character << "num: " << num << "low: " << record->lowRange << "hi: " << record->highRange << endl;
	}		

}


