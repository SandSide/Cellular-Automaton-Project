#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

// Daniel Langr https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
const std::string red("\033[1;31m");	// Makes output red coloured.
const std::string reset("\033[0m");		// Makes output black coloured.


// defining all functions in the program
void menu();
void generateCellularAutomata();
void getDimensions(int &size, int &generations);
void initGenerations(int array[], int size);
void getRuleInput();
void calculateBinary(int rule[8],int val);
void computeGenerations(int nextGeneration[], int previousGeneration[], int nGenerations, int sizeGeneration);
void displayGeneration(int generation[], int size);
void binary2Number(int binaryN[8]);

//Stores the rule throughout the program.
int rule[8] = {};

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
	//Make local varibles
 	int size;
	int amount;

	//Get size and nuber of generations
 	getDimensions(size,amount);

	//Creates and initialises previous and next generation arrays.
	int *array1 = new int[size];
	int *array2 = new int[size];

	//Will recieve the rule the user wants to execute the automata with.
	getRuleInput();

	//Calls computeGenerations
	computeGenerations(array1, array2, amount, size);
}

/*
Will randomly select values to use for the grid size.
Returns an array with the x and y size of the grid.
*/
int *randomGridSize()
{
	//Allocates memory for an array which will store the grid size.
	int* grid = new int[2];

	//Seeds the random value generator with the time.
	srand(time(0));
	//Set x and y values in the grid.
	grid[0] = rand() % 199 + 2;
	grid[1] = rand() % 44 + 2;
	return grid;
}

/*
	Recieves user input to determine size and number of generations.
	Parameter: &size; Refrence to store user input.
	Parameter: &generations. Refrence to store user input.
*/
void getDimensions(int &size,int &generations)
{
	//Gets random grid sizes to allow user to select.
	int grid1[2] = {};
	int grid2[2] = {};
	int grid3[2] = {};
	//grid1 = randomGridSize();

	//Will allow user to select a grid size.
	int choice;
	cout << "Select a grid size:" << endl;
	cout << "1) 8x8" << endl;
	cout << "2) 9x9" << endl;
	cout << "3) 10x10" << endl;
	//cout << "4) " << grid1[0] << "x" << grid1[1] << endl;
	//cout << "5) " << grid2[0] << "x" << grid2[1] << endl;
	//cout << "6) " << grid3[0] << "x" << grid3[1] << endl;
	cout << "7) Custom grid size" << endl;
	cin >> choice;
	
	while(choice > 4 && choice < 1)
	{
		cout << "Invalid option selected, please select a valid option (1-4)." << endl;
		cin >> choice;
	}
	

	switch(choice)
	{
		case 1: 
			size = 8;
			generations = 8;
		break;
		case 2: 
			size = 9;
			generations = 9;
		break;
		case 3: 
			size = 10;
			generations = 10;
		break;
		case 4:
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
		break;
	}
}

/*
	
	Gets integer user input to convert into binary and store in the parameter varaible.

	Paramter: rule[8]. Array to store the rule.


*/
void getRuleInput()
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

//Will calculate the binary value of a decimal number. Will fill an array with the values representing the binary value of the input decimal number.
//val is the number being converted.
void calculateBinary(int arr[8],int val)
{
	//Loops until the values in the result value are computed.
	for (int i = 0; i < 8; ++i)
	{
		//If the value is greater equal to the current exponent of 2
		if (val >= pow(2,(7-i)))
		{
			//Set spot in array to 1 and subtract the exponent of 2 from the value.
			arr[i] = 1;
			val -= pow(2,(7-i));
		}
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
void computeGenerations(int nextGeneration[], int previousGeneration[], int nGenerations, int sizeGeneration)
{
	// varaible will store an int which is the total of next 3 varaibles.
	int boxPattern = 0;
	int prevBox = 0; // represents 4 bit valuecomputeGen
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

	//Will clear rule array making it store 0.
	memset(rule,0,7);
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


//Will select a random decimal number to use as the rule.
int randomRule()
{
	//Reference: www.programiz.com/cpp-programming/library-function/cstdlib/srand
	//Will make a seed with the number of seconds since 00:00 Jan 1 1970 UTC.
	srand(time(0));

	int rule = rand() % 256;
	return rule;
}

//Will randomly generate the first generation.
//@param x The size of the generation.
//@param gen[] This is the array random values are being assigned to.
void generateFirstGeneration(int x, int gen[])
{
	//Reference: www.programiz.com/cpp-programming/library-function/cstdlib/srand
	//Will make a seed with the number of seconds since 00:00 Jan 1 1970 UTC.
	srand(time(0));

	//Will loop for the entire row.
	for (int i = 0; i < x; ++i)
	{
		//Will pick 1 or 0.
		gen[i] = rand() % 2;
	}
}

int main()
{

	menu();
	
}

