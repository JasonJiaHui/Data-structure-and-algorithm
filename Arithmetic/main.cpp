#include <iostream>
#include <vector>
#include <string>
#include "arithmetic.h"

int main(void)
{
	string str = "BILL GATES";
	
	ArithmeticTable table;

	table.initialise(str);

	table.encode(str);	

	table.decode(0.2572167752);

	return 0;
}
