#ifndef _ARITHMETIC_H
#define _ARITHMETIC_H

#include <vector>
#include <string>

using namespace std;

class Record
{
public:
	char Character;
	double Probability;
	double lowRange;
	double highRange;
	
	double lValue;
	double hValue;

public:
	Record(char ch, double prob, double lrange, double hrange)
	{
		this->Character = ch;
		this->Probability = prob;
		this->lowRange = lrange;
		this->highRange = hrange;
	}
	

};

class ArithmeticTable
{
public:	
	vector<Record*> records;

public:
	
	void initialise(string code);
	Record* getRecord(char ch);
	void setEncodeValue(char ch, double lValue, double hValue);
	Record* getRecord(double number);
	void encode(string code);
	void decode(double number);
		
};

#endif
