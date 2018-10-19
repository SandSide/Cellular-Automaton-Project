#include <iostream>
#include <string>

using namespace std;

// Daniel Langr https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
const std::string red("\033[1;31m");	// Makes output red coloured.
const std::string reset("\033[0m");		// Makes output black coloured.


/*
	Initalises the whole array to be 0.

	Parameter: array[]. Generation which will be initalised with 0s.
	Parameter: size. Size of the generation.

*/
int initGenerations(int array[], int size)
{

	// for every item in the generation, make it 0
	for(int i = 0; i <size ; i++)
	{

		array[i] = 0;

	}

}

/*
	Creates 1-D Cellular Automata which is looped at the sides.

	Parameter: nextGeneration[]. Array which will contain next generation based on previous generation.
	Parameter: previousGeneration[]. Array which contains first generation. Will store previous generation as a new one is being created.
	Parameter: rule[]. Contains the rule.
	Parameter: nGenerations. Number which specifies how many generations will be made.
	Parameter: sizeGeneration. Number which specifies the size of each generation.

*/
int computeGenerations(int nextGeneration[], int previousGeneration[], int rule[], int nGenerations, int sizeGeneration)
{

	// varaible will store an int which is the total of next 3 varaibles.
	int boxPattern = 0;
	int prevBox = 0; // represents 4 bit value
	int currBox = 0; // represents 2 bit value
	int nextBox = 0; // represents 1 bit value

	// give first generation 1 (black) in the middle of the array
	previousGeneration[(sizeGeneration/2)] = 1;



	// displays first generation
	for (int i = 0 ; i<sizeGeneration; i++)
	{

		if (previousGeneration[i] == 1)
		{

			cout << red << previousGeneration[i];

		}
		else
		{

			cout << reset << previousGeneration[i];

		}

	}

	cout << endl;

	// creates nGenerations generations
	for (int g = 0; g < nGenerations; g++)
	{

		// for every item in the next generation
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

				// checking previous row to find out what will happen to the box (column) in the next generation
				prevBox = previousGeneration[i-1];
				currBox = previousGeneration[i];
				nextBox = previousGeneration[i+1];


			}

			// calculate the pattern
			boxPattern = ((4*prevBox) + (2*currBox) + nextBox);

			// compute boxPattern
			switch(boxPattern) 
			{
		    	case 0 : nextGeneration[i] = rule[7]; break;
		    	case 1 : nextGeneration[i] = rule[6]; break;
		    	case 2 : nextGeneration[i] = rule[5]; break;
		    	case 3 : nextGeneration[i] = rule[4]; break;
		    	case 4 : nextGeneration[i] = rule[3]; break;
		    	case 5 : nextGeneration[i] = rule[2]; break;
		    	case 6 : nextGeneration[i] = rule[1]; break;
		    	case 7 : nextGeneration[i] = rule[0]; break;
		    		
			}
		
		}

		// display next Generation
		for (int k =0; k<sizeGeneration; k++)
		{
			
			if (nextGeneration[k] == 1)
			{

				cout << red << nextGeneration[k];

			}
			else
			{

				cout << reset << nextGeneration[k];

			}

			// make previous generation next generation
			previousGeneration[k] = nextGeneration[k];
			nextGeneration[k] = 0;

		}

		cout << reset << endl;

	}	

}


int displayGeneration(int generation[], int size)
{

	// displays generation
	for (int i = 0 ; i<size; i++)
	{

		if (generation[i] == 1)
		{

			cout << red << generation[i];

		}
		else
		{

			cout << reset << generation[i];

		}

	}

	cout << reset << endl;

}

/*
	Converts binary number to a Integer value.

	Parameter: binaryN[8]. Array containing binary number.

*/
int binary2Number(int binaryN[8])
{

	// calculates binary number integer value
	int number = (128*binaryN[0]) + (64*binaryN[1]) + (32*binaryN[2]) + (16*binaryN[3]) + (8*binaryN[4]) + (4*binaryN[5]) + (2*binaryN[6]) + (1*binaryN[7]);

	// displays Binary number
	cout << "Binary: ";

	for (int i = 0; i <8; i++)
	{

		cout << binaryN[i];

	}

	// diplays intger value
	cout << " | Integer: " << number << endl; 


}

/*
	Converts a character to a binary number.

	Parameter: c. Character to be turned to a character.

*/
int char2Binary(char c)
{


	int number = static_cast<int>(c);

	cout << "Character: " << c << " | Number: " << number << endl;


}

int main()
{

	// make local varibles
	int size;
	int ammount;

	// ask for user input
	cout << "Please enter the size of the generations: " << endl;
	cin >> size;

	// while the size entered for the array is less than 2
	while(size < 2)
	{

		// ask user to enter a number
		cout << "The size you entered is too small. Please enter a size greater than 1." << endl;
		cout << "Please enter the size of the generations: " << endl;
		cin >> size;

	}

	cout << endl;

	// ask for user input
	cout << "Please enter the number of the generations: " << endl;
	cin >> ammount;

	// while the number entered for number of generations is less than 1
	while(ammount < 1)
	{

		// ask user to enter a number
		cout << "The number you entered is too small. Please enter a size greater than 0." << endl;
		cout << "Please enter the size of the generations: " << endl;
		cin >> size;

	}

	// takes 1 away from ammount (to compensate for first generation)
	ammount--;

	// creates previous and next generation arrays
	int array1[size];
	int array2[size];

	// initalises the arrays
	initGenerations(array1, size);
	initGenerations(array2, size);

	// rule
	int rule[8] = {0, 0, 0, 1, 1, 1, 1, 0};

	// calls computeGenerations
	computeGenerations(array1, array2, rule, ammount, size);

}
