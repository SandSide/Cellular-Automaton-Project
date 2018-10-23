#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <cstdlib>

using namespace std;

// Daniel Langr https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
const std::string red("\033[1;31m");	// Makes output red coloured.
const std::string reset("\033[0m");		// Makes output black coloured.


// defining all functions in the program
void menu();
void generateCellularAutomata();
void getDimensions(int &size, int &generations);
void initGenerations(int array[], int size);
void getRule(int rule[8]);
void calculateBinary(int rule[8],int val);
void computeGenerations(int nextGeneration[], int previousGeneration[], int rule[], int nGenerations, int sizeGeneration);
void displayGeneration(int generation[], int size);
void binary2Number(int binaryN[8]);


/*
	Menu method


*/
void menu()
{

	int userOption;

	// Display the options to the user
	cout << "1.	Start" << endl; 
	cout << "0.	Exit" << endl; 

	// Get the input from the user and check if the input is valid
	// Refrence from:https://study.com/academy/lesson/validating-input-data-in-c-plu-plus-programming.html
	// Under the "cin Functions" Sections
	while(!(cin >> userOption))
	{

		// Send an error message
		cerr << "Error: A non whole number was entered \nPlease enter a whole number:" << endl;
		cin.clear();
		cin.ignore(100, '\n');

	}

	// Process the users option
	if(userOption == 1)
	{

		// Run the Processs
		generateCellularAutomata();


	}
	else if (userOption ==0)
	{
		
		exit(0);

	}
	else
	{
		// Send Error message
		cout << "Error: Your entered something that was not one of the inputs!" << endl; 
		cout << "Enter a number form the options below" << endl;
		cout << "" << endl;

	}

}

/*
	
	Collects all data needed to run ComputeGenerations, which will create a Cellular Automata.

*/
void generateCellularAutomata()
{

	// make local varibles
	int size;
	int amount;

	// getRule does not work so had to use this to make the program work
	int rule[8];

	// get size and uber of generations
	getDimensions(size, amount);

	// takes 1 away from ammount (to compensate for first generation)
	amount--;

	// creates previous and next generation arrays
	int array1[size];
	int array2[size];

	// initalises the arrays
	initGenerations(array1, size);
	initGenerations(array2, size);

	getRule(rule);

	// calls computeGenerations
	computeGenerations(array1, array2, rule, amount, size);

}

/*
	Recieves user input to determine size and number of generations.

	Parameter: &size; Refrence to store user input.
	Parameter: &generations. Refrence to store user input.
	
*/
void getDimensions(int &size,int &generations)
{

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
	cout << "Please enter the number of generations you want to create: " << endl;
	cin >> generations;

	// while the number entered for number of generations is less than 1
	while(generations < 1)
	{

		// ask user to enter a number
		cout << "The number you entered is too small. Please enter a size greater than 0." << endl;
		cout << "Please enter the size of the generations: " << endl;
		cin >> generations;

	}

}


/*
	Initalises the whole array to be 0.

	Parameter: array[]. Generation which will be initalised with 0s.
	Parameter: size. Size of the generation.

*/
void initGenerations(int array[], int size)
{

	// for every item in the generation, make it 0
	for(int i = 0; i <size ; i++)
	{

		array[i] = 0;

	}

}

/*
	
	Gets integer user input to convert into binary and store in the parameter varaible.

	Paramter: rule[8]. Array to store the rule.


*/
void getRule(int rule[8])
{

	// store integer
	int ruleN;

	// ask for user input
	cout << "\n Please enter the rule: " << endl;
	cin >> ruleN;

	// while the rule enetred is not between 0 and 255
	while(ruleN < 0 || ruleN >255)
	{

		// ask user to enter a number
		cout << "The rule you entered is invalid. Please enter a vlue between 0-255." << endl;
		cout << "Please enter the rule: " << endl;
		cin >> ruleN;

	}

	cout << endl;

	// calculate the binary number of the integer
	calculateBinary(rule, ruleN);

}


//Will calculate the binary value of a decimal number. Returns the binary value as an array.
//val is the number being converted.
void calculateBinary(int rule[8],int val)
{
	int num = val;
	int r = 0;	
	int col = 128;

	r = num%col;

	for (int i = 0; i <8; i++)
	{

	  r = num/col;
	  if(r != 0)
	  {

		  	rule[i] = 1;
		  	num -= col;

	  }
	  else
	  {

	  		rule[i] = 0;

	  }

	  col = col/2;

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
void computeGenerations(int nextGeneration[], int previousGeneration[], int rule[], int nGenerations, int sizeGeneration)
{

	// varaible will store an int which is the total of next 3 varaibles.
	int boxPattern = 0;
	int prevBox = 0; // represents 4 bit value
	int currBox = 0; // represents 2 bit value
	int nextBox = 0; // represents 1 bit value

	// give first generation 1 (black) in the middle of the array
	previousGeneration[(sizeGeneration/2)] = 1;


	cout<< "GENERATING CELLULLAR AUTOMATA.\n" << endl; 

	// displays previous generation (first generation)
	displayGeneration(previousGeneration, sizeGeneration);

	// creates nGenerations generations
	for (int g = 1; g < nGenerations; g++)
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
			else if (i == (sizeGeneration-1))
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

		// displays generated generation (nextGeneration)
		displayGeneration(nextGeneration,sizeGeneration);

		// display next Generation
		for (int k =0; k<sizeGeneration; k++)
		{	

			// make previous generation next generation
			previousGeneration[k] = nextGeneration[k];
			nextGeneration[k] = 0;

		}

	}	

}

/*
	
	Dsiplays recieved generation.

	Parameter: generation[]. Array contain generation.
	Parameter: size. Contains size of generation.

*/
void displayGeneration(int generation[], int size)
{

	// displays the generation
	for (int i = 0; i<size; i++)
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


int main()
{

	menu();
	
}

