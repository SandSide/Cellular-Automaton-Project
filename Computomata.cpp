//Author: Aditya Kumar Menon
#include <random>
#include <cmath>
#include <cstdlib>

using namespace std;



//Will calculate the binary value of a decimal number. Returns the binary value as an array.
//val is the number being converted.
int* calculateBinary(int val)
{
	int count = 8;
	//Stores the binary value.
	int result[count];
	
	//Loops until the values in the result value are computed.
	for (int i = 0; i < count; ++i)
	{
		//If the value is greater equal to the current exponent of 2
		if (val >= pow(2,(7-i)))
		{
			//Set spot in array to 1 and subtract the exponent of 2 from the value.
			result[i] = 1;
			val -= pow(2,(7-i))
		}
	}
	return result;
}

//Will randomly generate a generation.
int* generateFirstGeneration(int x)
{
	//Stores the generation.
	int firstGen[x];
	
	//Will loop for the entire row.
	for (int i = 0; i < x; ++i)
	{
		//Will pick 1 or 0.
		firstGen[i] = rand() % 2
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
	int rule = rand() % 256
	return rule;
}



int main()
{
	calculateBinary(145);
	return 0;
}