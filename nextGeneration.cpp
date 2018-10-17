#include <iostream>
#include <string>


using namespace std;

int main()
{
	// our rule (rule 30)
	string rule[8] = {"0","0","0","1","1","1","1","0"};

	// define a 1-D for previous and next Generations (rows)
	string previousGeneration [40];
	string nextGeneration [40];

	// define strings to store whole Generation (row)
	string lastGeneration;
	string newGeneration;
	
	// for every item in the array, make it 0;
	for(int i = 0; i<40; i++){

		nextGeneration[i] = "0";
		previousGeneration[i] = "0";
	}
	
	// assign black boxes (1) to first generation
	previousGeneration[20] = "1";
	previousGeneration[10] = "1";
	previousGeneration[30] = "1";

	// define strings wich will be used to compare pattern to rule
	string boxPattern;
	string prevBox;
	string currBox;
	string nextBox;
		
	// define size of the array (did not find a functions to find the size like .length or .size)
	int maxColumn = 40;
	
	// for every item in array (
	for(int i = 0; i<maxColumn; i++)
	{
		// combine all strings to creae one large string
		lastGeneration += previousGeneration[i];
		
	}

	cout << lastGeneration << endl;

	// how many generations you want (does not include first generation
	for (int m = 0; m <10; m++)
	{


	// for every column in the next generation
	for (int i = 0; i <maxColumn; i++)
	{
		
		// if you are finding the result for first box (column)
		if(i == 0)
		{

			// checking previous generation to find out what will happen to the first box (column) in the next generation
			prevBox = previousGeneration[maxColumn-1];
			currBox = previousGeneration[i];
			nextBox = previousGeneration[i+1];


		}
		// if you are finding the result for last box (column)
		else if (i == maxColumn)
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
		boxPattern = prevBox + currBox + nextBox;
		
		// comparing pattern to rule patterns to decide what the rule will result in
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

	}
		
	// for every box in both generations
	for (int i = 0; i<maxColumn; i++)
	{	
		
		// add all next generation boxes to create one string
		newGeneration += nextGeneration[i];
		
		// make previous generation next generation.
		previousGeneration[i] = nextGeneration[i];


	}
	
	// display newGeneration (next generation) and clear it
	cout << newGeneration << endl;
	newGeneration = "";

}
}


