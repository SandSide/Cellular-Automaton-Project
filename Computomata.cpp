//Author: Aditya Kumar Menon
#include <random>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//Will calculate the binary value of a decimal number. Returns the binary value as an array.
//val is the number being converted.
vector<int> calculateBinary(int val)
{
	int biggestBinVal = 8;
	//Stores the binary value.
	vector<int> result(biggestBinVal);
	
	//Loops until the values in the result value are computed.
	for (int i = 0; i < biggestBinVal; ++i)
	{
		//If the value is greater equal to the current exponent of 2
		if (val >= pow(2,(7-i)))
		{
			//Set spot in array to 1 and subtract the exponent of 2 from the value.
			result[i] = 1;
			val -= pow(2,(7-i));
		}
	}
	return result;
}

//Will randomly generate a generation.
vector<int> generateFirstGeneration(int x)
{
	//Stores the generation.
	vector<int> firstGen(x);

	//Reference: www.programiz.com/cpp-programming/library-function/cstdlib/srand
	//Will make a seed with the number of seconds since 00:00 Jan 1 1970 UTC.
	srand(time(0));

	//Will loop for the entire row.
	for (int i = 0; i < x; ++i)
	{
		//Will pick 1 or 0.
		firstGen[i] = rand() % 2;
	}

	return firstGen;
}

/*

//TODO: Complete method
setRule(int rule)
{
	calculateBinary(rule)
}

//TODO: Find out if this is still going to be in use.
calculateBinary(char letr)
{
	
}

int randomRuleSet()
{
	
}
*/

//Will select a random number to use as the rule.
int randomRule()
{
	int rule = rand() % 256;
	return rule;
}



int main()
{
	vector<int> trry = generateFirstGeneration(test);
	for (int i = 0; i < test; ++i)
	{
		cout << trry[i];
	}
	cout << endl;
	return 0;
}