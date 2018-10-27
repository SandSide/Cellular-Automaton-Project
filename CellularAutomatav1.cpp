#include <iostream>
#include "cel.h"

//	stores the rule throughout the program.
int rule[8] = {};


/*
	Menu method

*/
void menu()
{

	system("clear");

	// seeds the random value generator for all random value generation.
	srand(time(0));
	
	int userOption = 50;

	while(userOption != 0)
	{

		// Display the options to the user
		cout << "\n-------------------------------" << endl;
		cout << "\t MAIN MENU" << endl;
		cout << "-------------------------------" << endl;
		cout << "1.	Cellular Automata." << endl;
		cout << "2.	Game of Life." << endl;
		cout << "0.	Exit." << endl;
		cout << "-------------------------------" << endl;
		cout << "Please enter you choice: " << endl;

		cin >> userOption;

		cout << "-------------------------------" << endl;

		// While the input is invalid
		while(!cin || userOption < 0 || userOption >2)
		{

			// Clear the terminal
			system("clear");

			cin.clear();
			cin.ignore();

			// Send Error message
			cout << "\nError: Your entered something that was not one of the inputs!" << endl; 
			cout << "Enter a number from the options below." << endl;

			// Display the options to the user
			cout << "\n-------------------------------" << endl;
			cout << "\t MAIN MENU" << endl;
			cout << "-------------------------------" << endl;
			cout << "1.	Cellular Automata." << endl;
			cout << "2.	Game of Life." << endl;
			cout << "0.	Exit." << endl;
			cout << "-------------------------------" << endl;
			cout << "Please enter you choice: " << endl;

			cin >> userOption;
			
			cout << "-------------------------------" << endl;

		}

		// Process the users option
		if(userOption == 1)
		{

			// Run the Processs
			generateCellularAutomata();


		}
		else if (userOption == 2)
		{
			
			generateGameOfLife();

		}
		else if (userOption == 0)
		{
			
			cout << "Exiting program." << endl;
			exit(0);

		}

	}

}

/*
Sub menu method
*/
int SubMenu(){
	//Initilise Varaiables
	bool isValid=false;
	int userOption;
	
	//Keep asking the user to enter a value until a valid number is entered
	while(isValid==false){
	//Display Menu
	cout << "What values would you like to use:	" <<endl;
	cout << "1.	Pre Defined Values" << endl;
	cout << "2.	Use Customm Values" << endl;


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

	//Add the while loop here
	if(userOption ==1 || userOption ==2)
	{
		isValid=true;
	}else{
		// Send Error message
		cout << "Error: Your entered something that was not one of the inputs!" << endl; 
		cout << "Enter a number form the options below" << endl;
		cout << "" << endl;
	}
}
	return userOption;

}

/*
	
	Collects all data needed to run ComputeGenerations, which will create a Cellular Automata.

*/
void generateCellularAutomata()
{
	// Make local varibles
 	int size;
	int amount;

	// Get size and nuber of generations
 	getDimensions(size,amount);

	// Creates and initialises previous and next generation arrays.
	int *array1 = new int[size];
	int *array2 = new int[size];

	// Will recieve the rule the user wants to execute the automata with.
	getRuleInput();

	// Calls computeGenerations
	computeGenerations(array1, array2, amount, size);
}

/*
	Will randomly select values to use for the grid size.
	@param grid This is the input grid

*/
void randomGridSize(int grid[2])
{
	//Set x and y values in the grid.
	grid[0] = rand() % 199 + 2;
	grid[1] = rand() % 44 + 2;
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
	randomGridSize(grid1);
	randomGridSize(grid2);
	randomGridSize(grid3);

	//Will allow user to select a grid size.
	int choice;

	system("clear");

	cout << "\n-------------------------------" << endl; 
	cout << "   Select Automata Dimensions." << endl;
	cout << "-------------------------------" << endl;
	cout << "Static:" << endl;
	cout << "	1) 8x8" << endl;
	cout << "	2) 9x9" << endl;
	cout << "	3) 10x10" << endl;
	cout << "Random:" << endl;
	cout << "	4) " << grid1[0] << "x" << grid1[1] << endl;
	cout << "	5) " << grid2[0] << "x" << grid2[1] << endl;
	cout << "	6) " << grid3[0] << "x" << grid3[1] << endl;
	cout << "Manual" << endl;
	cout << "\t7) Custom Dimensions." << endl;

	cout << "-------------------------------" << endl;
	cout << "Please enter your choice:" << endl;
	cin >> choice;
	cout << "-------------------------------" << endl;
	
	while(!cin || choice <1 || choice > 7)
	{

		system("clear");
		cin.clear();
		cin.ignore(); // skips stream data

		cout << "\nInvalid Input." << endl;
		cout << "\n-------------------------------" << endl; 
		cout << "   Select Automata Dimensions." << endl;
		cout << "-------------------------------" << endl;
		cout << "Static:" << endl;
		cout << "	1) 8x8" << endl;
		cout << "	2) 9x9" << endl;
		cout << "	3) 10x10" << endl;
		cout << "Random:" << endl;
		cout << "	4) " << grid1[0] << "x" << grid1[1] << endl;
		cout << "	5) " << grid2[0] << "x" << grid2[1] << endl;
		cout << "	6) " << grid3[0] << "x" << grid3[1] << endl;
		cout << "Manual" << endl;
		cout << "\t7) Custom Dimensions." << endl;

		cout << "-------------------------------" << endl;
		cout << "Please enter your choice:" << endl;
		cin >> choice;
		cout << "-------------------------------" << endl;

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
			size = grid1[0];
			generations = grid1[1];
		break;

		case 5:
			size = grid2[0];
			generations = grid2[1];
		break;

		case 6:
			size = grid3[0];
			generations = grid3[1];
		break;

		case 7:

			// ask for user input for size
			cout << "\nPlease enter the size of the generations: " << endl;
			cin >> size;


			// while the size entered for the array is less than 2 or entered bad varaible type
			while(size < 2 || !cin)
			{

				cin.clear();
				cin.ignore(); // skips stream data


				// ask user to  re-enter the size
				cout << "\nThe size you entered is invalid. Please enter a size greater than 1." << endl;
				cout << "Please enter the size of the generations: " << endl;
				cin >> size;

			}


			// ask for user input foe number of generations
			cout << "\nPlease enter the number of generations you want to create: " << endl;
			cin >> generations;

			// while the number entered for number of generations is less than 1 or entered bad varaible type
			while(generations < 2 || !cin)
			{

				cin.clear();
				cin.ignore(); // skips stream data

				// ask user to re-enter the size of generations
				cout << "\nThe number you entered is invalid. Please enter a size greater than 1." << endl;
				cout << "Please enter the size of the generations: " << endl;
				cin >> generations;

			}
		break;

	}

}

//	Will select a random decimal number to use as the rule.
//	@return rule The decimal value of the rule.
int randomRule()
{
	int rule = rand() % 256;
	return rule;
}

void binaryToInt()
{
	
}

/*
	
	Gets integer user input to convert into binary and store in the parameter varaible.

	Paramter: rule[8]. Array to store the rule.


*/
void getRuleInput()
{
	int choice;
	// 
	int rule0 = randomRule(), rule1 = randomRule(), rule2 = randomRule();
	cout << "Select a rule to use." << endl;
	cout << "1) Rule 30" << endl;
	cout << "2) Rule 255" << endl; 
	cout << "3) Rule 0" << endl;
	cout << "4) Rule 45" << endl;
	cout << "5) Rule " << rule0 << endl;
	cout << "6) Rule " << rule1 << endl;
	cout << "7) Rule " << rule2 << endl;
	cout << "8) Custom Rule" << endl;
	cout << "9) Input Rule as Binary value" << endl;

	cin >> choice; 

	// store integer
	int ruleN;

	switch(choice)
	{
		case 1:
			ruleN = 30;
		break;
		case 2:
			ruleN = 255;
		break;
		case 3:
			ruleN = 0;
		break;
		case 4:
			ruleN = 45;
		break;
		case 5:
			ruleN = rule0;
		break;
		case 6:
			ruleN = rule1;
		break;
		case 7:
			ruleN = rule2;
		break;
		case 8:
			cout << "\nPlease enter the rule: " << endl;
			cin >> ruleN;

			// while the rule enetred is not between 0 and 255
			while(ruleN < 0 || ruleN >255 || !cin)
			{

				cin.clear();
				cin.ignore(); // skips stream data

				// ask user to enter a number
				cout << "\nThe rule you entered is invalid. Please enter a vlue between 0-255." << endl;
				cout << "Please enter the rule: " << endl;
				cin >> ruleN;

			}

			cout << endl;
		break;
		case 9:
			cout << "Type a binary number" << endl;
		break;
	}

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

	cout << "-------------------------------" << endl;
	cout<< "GENERATING CELLULLAR AUTOMATA." << endl; 
	cout << "-------------------------------\n" << endl;

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

//	Will randomly generate the first generation.
//	@param x The size of the generation.
//	@param gen[] This is the array random values are being assigned to.
void generateFirstGeneration(int x, int gen[])
{
	//Will loop for the entire row.
	for (int i = 0; i < x; ++i)
	{
		//Will pick 1 or 0.
		gen[i] = rand() % 2;
	}
}


/*
		Creates computeGameOfLife Cellular Automata.

*/
	
void generateGameOfLife()
{

	// counts how mnay alive neighbours around the block
	int aliveNeb = 0;

	// definining the size of the array
	const int size = 40;
	const int sizeX = size;
	const int sizeY = size;

	int previousGeneration[sizeY][sizeX];
	int nextGeneration[sizeY][sizeX];

	// initalising the generations
	for (int j = 0; j <sizeY; j++)
	{
		// for every item in the generation, make it 0
		for(int i = 0; i <sizeX ; i++)
		{

			previousGeneration[j][i] = 0;
			nextGeneration[j][i] = 0;

		}
	}

	// clearing the terminal
	system("clear");
	system("clear");

	// make some blocks black
	for(int i = 0; i < 40; i++)
	{

		for(int j = 0; j <40; j++)
		{	

			previousGeneration[i][j] = 1;

		}

	}

	// display first generation
	for (int i = 0; i < sizeY; i++)
	{

		for(int j = 0; j <sizeX ; j++)
		{

			// if block is 1, display black
			if (previousGeneration[i][j] == 1)
			{

				cout << "\u25A1" << 0; //previousGeneration[i][j];

			}
			else
			{

				// display white
				cout << "\u25A0" << 0; //previousGeneration[i][j];

			}

		}

		cout << reset << endl;

	}

	// do 100 times
	for(int m = 0; m <100; m++)
	{

		// display name
		cout << "\n\t\t\t\t  GAME OF LIFE" << endl;

		// for every item in the 2-D array
		for(int i = 0; i < sizeY ; i++)
		{

			for(int j = 0; j <sizeX ; j++)
			{

				// if at right-top corner
				if(i == 0 && j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][sizeX-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);

				}

				// if at right-bottom corner
				else if (i == (sizeY-1) && j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[0][sizeX-1] + previousGeneration[0][j] + previousGeneration[0][j+1]);

				}

				// if at left-top corner
				else if (i == 0 && j == (sizeX - 1))
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][j-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][0]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][0]);
					aliveNeb += (previousGeneration[i+1][j-1] + previousGeneration[i+1][j] + previousGeneration[i+1][0]);

				}

				// if at left-bottom corner
				else if (i == (sizeY-1) && j == (sizeX - 1))
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][0]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][0]);
					aliveNeb += (previousGeneration[0][j-1] + previousGeneration[0][j] + previousGeneration[0][0]);

				}

				// if at left border
				else if(i == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][j-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][j+1]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][j+1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);


				}

				// if at right border
				else if(i == sizeY -1)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][j+1]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[0][j+1] + previousGeneration[0][j] + previousGeneration[0][j+1]);

				}

				// if at top border
				else if(j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][sizeX-1] + previousGeneration[i-1][j] + previousGeneration[i-1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);

				}

				// if at bottom border
				else if(j == sizeX-1)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][0]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][0]);
					aliveNeb += (previousGeneration[i+1][j-1] + previousGeneration[i+1][j] + previousGeneration[i+1][0]);

				}
				else
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][j+1]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][j-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);

				}

				// if resident is alive
				if(previousGeneration[i][j] == 1) 
				{	

					// if have 2 neighbours
					if(aliveNeb < 2)
					{

						// resident dies from loneliness
						nextGeneration[i][j] = 0;

					}

					// if 2 or 3 neighbours
					else if(aliveNeb == 3 || aliveNeb == 2)
					{

						// resident stays alive
						nextGeneration[i][j] = 1;

					}

					// if more than 3 neighbours
					else if(aliveNeb > 3 )
					{

						// resident dies
						nextGeneration[i][j] = 0;

					}

				}
				// if no resident
				else if(previousGeneration[i][j] == 0)
				{

					// if 3 neighbours 
					if(aliveNeb == 3)
					{

						// new resident is born
						nextGeneration[i][j] = 1;

					}

				}

			}

		}

		// sleep for 1 second
	    sleep_until(system_clock::now() + 1s);
	    system("clear");
	   	system("clear");

	   	// for every item in the aray, display it
		for (int i = 0; i < sizeY; i++)
		{

			// for every item in the generation, make it 0
			for(int j = 0; j <sizeX; j++)
			{

				if (nextGeneration[i][j] == 1)
				{

					cout << "\u25A1" << nextGeneration[i][j];

				}
				else
				{

					cout << "\u25A0" << nextGeneration[i][j];

				}

				previousGeneration[i][j] = nextGeneration[i][j];

			}

			cout << reset << endl;

		}

	}
		
}

/*

Method to print an array

*/
void print(int array[], int size, string filename){
	//Create an object
	ofstream outputFile;

	//Open the file
	string file= filename+ ".txt";
	outputFile.open(file);

	//Print the lines of code onto file
	for (int i = 0; i < size; ++i)
	{
		//Print the line into the file
		outputFile << array[i] << " " ;
	}

	//CLose file
	outputFile.close();
}


int main(){
	menu();
	return 0;
}