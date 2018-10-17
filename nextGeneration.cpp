#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

	string rule[8] = {"0","0","0","1","1","1","1","0"};

	string previousGeneration [40];
	string nextGeneration [40];

	string lastGeneration;
	string newGeneration;

	for(int i = 0; i<40; i++){

		nextGeneration[i] = "0";
		previousGeneration[i] = "0";
	}

	previousGeneration[20] = "1";
	previousGeneration[10] = "1";
	previousGeneration[30] = "1";


	string boxPattern;
	string prevBox;
	string currBox;
	string nextBox;
			
	//int maxColumn = previousGeneration.length();
	int maxColumn = 40;

	for(int i = 0; i<maxColumn; i++){

		
		lastGeneration += previousGeneration[i];
	}

	cout << lastGeneration << endl;

	// for every column in the enxt row
	for (int m = 0; m <10; m++)
	{


	// for every column in the enxt row
	for (int i = 0; i <maxColumn; i++)
	{
		
		if(i == 0)
		{

			// checking previous row to find out what will happen to the first box (column) in the new row
			prevBox = previousGeneration[maxColumn-1];
			currBox = previousGeneration[i];
			nextBox = previousGeneration[i+1];


		}
		else if (i == maxColumn)
		{

			// checking previous row to find out what will happen to the last box (column) in the new row
			prevBox = previousGeneration[i-1];
			currBox = previousGeneration[i];
			nextBox = previousGeneration[0];

		}
		else
		{

			// checking previous row to find out what will happen to the  box (column) in the new row

			prevBox = previousGeneration[i-1];
			currBox = previousGeneration[i];
			nextBox = previousGeneration[i+1];


		}

		// add strings together to recieve a pattern e.g. 010, 110, 011 etc.
		boxPattern = prevBox + currBox + nextBox;

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

	for (int i = 0; i<maxColumn; i++)
	{

		newGeneration += nextGeneration[i];
		previousGeneration[i] = nextGeneration[i];
		//lastGeneration += previousGeneration[i];

	}

	//cout << lastGeneration << endl;
	cout << newGeneration << endl;
	newGeneration = "";

}
}


