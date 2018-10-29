#include <iostream>
#include <string>
#include "cel.h"

using namespace std;
/*
int binary2Number(int binaryN[8])
{


	int number = (128*binaryN[0]) + (64*binaryN[1]) + (32*binaryN[2]) + (16*binaryN[3]) + (8*binaryN[4]) + (4*binaryN[5]) + (2*binaryN[6]) + (1*binaryN[7]);

	cout << "Binary: ";

	for (int i = 0; i <8; i++)
	{

		cout << binaryN[i];

	}

	cout << " | Integer: " << number << endl; 


}
*/
int userBinaryRule()
{
	//Variables are initialised to store the binary, decimal, and loop exit.
	char binVal[8];
	int val = 0;
	bool calculated = false;

	int b[7] = {128,64,32,16,8,4,2,1};

	while(!calculated)
	{
		val = 0;
		cout << "Enter binary value" << endl;
		scanf("%8c",binVal);

		for (int i = 0; i < 8; ++i)
		{
			if (binVal[i] != '1' && binVal[i] != '0')
			{
				i = 8;
				calculated = false;
				cout << "Value not a binary number. Try again." << endl;
			}
			else
			{
				calculated = true;
			}
					
		}
	}




	cout<< val << endl;
}

int main(){

		//int array[8] = {};
		binary2Number(array);
	userBinaryRule();


}