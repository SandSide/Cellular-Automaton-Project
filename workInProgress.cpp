#include <iostream>
#include <string>

using namespace std;

/*
char previousGeneration;
char nextGeneration;
char rule[8];

int initGenerations(char &previousGeneration[], char &nextGeneration[], int size)
{

	char previousGeneration[size];
	char nextGeneration[size];

	// for every item in the array, make it 0;
	for(int i = 0; i<size; i++)
	{

		nextGeneration[i] = '0';
		previousGeneration[i] = '0';

	}

}
*/

int computeGenerations()
{

	// define strings wich will be used to compare pattern to rule
	char boxPattern[3];
	char prevBox;
	char currBox;
	char nextBox;

	char rule[8] = {'111', '110', '101', '100', '011', '010', '001', '000'};
		
	char nextGeneration[40];
	char previousGeneration[40];
	int nGenerations = 10;

	// define size of the array (did not find a functions to find the size like .length or .size)
	int sizeGeneration = sizeof(nextGeneration);

	for (int i =0; i<sizeGeneration; i++)
	{

		nextGeneration[i] = '0';
		previousGeneration[i] = '1';

	}

	previousGeneration[20] = '1';

	cout << previousGeneration << endl;

	// how many generations you want (does not include first generation)
	for (int m = 0; m < nGenerations; m++)
	{

		// for every column in the next generation
		for (int i = 0; i <sizeGeneration; i++)
		{
			
			// if you are finding the result for first box (column)
			if(i == 0)
			{

				// checking previous generation to find out what will happen to the first box (column) in the next generation
				prevBox = previousGeneration[sizeGeneration-1];
				currBox = previousGeneration[i];
				nextBox = previousGeneration[i+1];


			}
			// if you are finding the result for last box (column)
			else if (i == sizeGeneration)
			{

				// checking previous row to find out what will happen to the last box (column) in the next generation
				prevBox = previousGeneration[i-1];
				currBox = previousGeneration[i];
				nextBox = previousGeneration[0];

			}
			else
			{

				// checking previous row to find out what will happen to the  box (column) in the next generation

				prevBox = previousGeneration[i-1];
				currBox = previousGeneration[i];
				nextBox = previousGeneration[i+1];


			}

			// add strings together to recieve a pattern e.g. 010, 110, 011 etc.
				boxPattern[0] = prevBox;
				boxPattern[1] = currBox;
				boxPattern[2] = nextBox;

				/*
				switch(boxPattern) 
				{
		    		case '000' : nextGeneration[i] = rule[7];
		    		case '001' : nextGeneration[i] = rule[6];
		    		case '010' : nextGeneration[i] = rule[5];
		    		case '011' : nextGeneration[i] = rule[4];
		    		case '100' : nextGeneration[i] = rule[3];
		    		case '101' : nextGeneration[i] = rule[2];
		    		case '110' : nextGeneration[i] = rule[1];
		    		case '111' : nextGeneration[i] = rule[0];
		    		
				}
				*/


					// have not found a way to use cases with strings
		if (boxPattern == "000")
		{

			nextGeneration[i] = rule[7];

		}
		else if(boxPattern == "001")
		{

			nextGeneration[i] = rule[6];

		}
		else if(boxPattern == "010")
		{

			nextGeneration[i] = rule[5];

		}
		else if(boxPattern == "011")
		{

			nextGeneration[i] = rule[4];

		}
		else if(boxPattern == "100")
		{

			nextGeneration[i] = rule[3];

		}
		else if(boxPattern == "101")
		{

			nextGeneration[i] = rule[2];

		}
		else if(boxPattern == "110")
		{

			nextGeneration[i] = rule[1];

		}
		else if(boxPattern == "111")
		{

			nextGeneration[i] = rule[0];

		}
			cout << nextGeneration << endl;

			for (int k =0; k<sizeGeneration; k++)
			{

				previousGeneration[k] = nextGeneration[k];
				nextGeneration[k] = '0';

			}
	}

}


