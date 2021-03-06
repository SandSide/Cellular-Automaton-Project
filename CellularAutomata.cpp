//Group: 23
//Patryk Jakubek - 170011784
//Aditya Kumar Menon - 170025886
// Melvin Abraham - 170013110

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
	
	//Initliaise Variables
	int userOption = 50;

	//Display the user menu
	while(userOption != 0)
	{

		// Display the options to the user
		cout << "\n-------------------------------" << endl;
		cout << "\t MAIN MENU" << endl;
		cout << "-------------------------------" << endl;
		cout << "1.	Cellular Automata." << endl;
		cout << "2.	Game of Life." << endl;
		cout << "3. 	Load Cellular Automata." << endl;
		cout << "4. 	2D Automata." << endl;
		cout << "0.	Exit." << endl;
		cout << "-------------------------------" << endl;
		cout << "Please enter you choice: " << endl;

		cin >> userOption;

		cout << "-------------------------------" << endl;

		// While the input is invalid
		while(!cin || userOption < 0 || userOption >4)
		{

			// Clear the terminal
			system("clear");

			cin.clear();
			cin.ignore();

			// Send Error message
			cout << "Error- You have entered an invalid option!" <<endl;
      		cout << "Please try again with the following options:" <<endl;

			// Display the options to the user
			cout << "\n-------------------------------" << endl;
			cout << "\t MAIN MENU" << endl;
			cout << "-------------------------------" << endl;
			cout << "1. 	Cellular Automata." << endl;
			cout << "2.	Game of Life." << endl;
			cout << "3. 	Load Cellular Automata." << endl;
			cout << "4. 	2D Automata." << endl;
			cout << "0.	Exit." << endl;
			cout << "-------------------------------" << endl;
			cout << "Please enter you choice: " << endl;

			cin >> userOption;
			
			cout << "-------------------------------" << endl;

		}

		// Process the users option
		if(userOption == 1)
		{

			// Run the Cellular Automata
			generateCellularAutomata();


		}
		else if (userOption == 2)
		{
			//Run game of life
			generateGameOfLife();

		}
		else if(userOption == 3)
		{	
			//Allow the user to load a file
		 	load();
				
		}

		else if(userOption == 4)
		{	
			//Let the user run a 2D automata
		 	Generate2DAutomata();
				
		}
		else if (userOption == 0)
		{
			//Exit option
			cout << "Exiting program." << endl;
			exit(0);

		}

	}

}

/*
	Method for the sub menu
*/
int SubMenu()
{
	//Initilise Varaiables
	bool isValid=false;
	int userOption;
	
	//Keep asking the user to enter a value until a valid number is entered
	while(isValid==false)
	{
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
			cerr << "Error- A non whole number was entered \nPlease enter a whole number:" << endl;
			cin.clear();
			cin.ignore(100, '\n');

		}

		//Add the while loop here
		if(userOption ==1 || userOption ==2)
		{
			isValid=true;
		}else{
		// Send Error message
		cout << "Error- Your entered something that was not one of the inputs!" << endl; 
		cout << "Enter a number form the options below" << endl;
		cout << "" << endl;
		}
	}
	return userOption;

}

void selectGen(int firGen[], int size)
{
	//Initliaise Variables
	int choice;

	//Print menu
	cout << "\n-------------------------------" << endl;
	cout << "\t Select First Generation." << endl;
	cout << "-------------------------------" << endl;
	cout << "1) Generate Random first generation." << endl;
	cout << "2) Set middle to on/black." << endl;
	cout << "3) Enter your own first generation." << endl;
	cout << "-------------------------------" << endl;
	cout << "Enter choice: " << endl;
	cin >> choice;
	cout << "-------------------------------" << endl;

	//Run the user menu
	while(!cin || choice <1 || choice >3)
	{
		// skips stream data
		cin.clear();
		cin.ignore(); // skips stream data

		//Send error message
		cout << "Error- You have entered an invalid option!" << endl;
     	cout << "Please try again with the following options:" << endl;



     	//Re-display the menu
		cout << "\n-------------------------------" << endl;
		cout << "\t Select First Generation." << endl;
		cout << "-------------------------------" << endl;
		cout << "1) Random" << endl;
		cout << "2) Mid" << endl;
		cout << "3) Custom" << endl;
		cout << "-------------------------------" << endl;
		cout << "Enter choice: " << endl;
		cin >> choice;
		cout << "-------------------------------" << endl;
	}

	//Handles user choice.
	switch(choice)
	{
		case 1:
			//Randomly generates first generation.
			generateFirstGeneration(size, firGen);
		break;
		case 2:
			//Give first generation 1 (black) in the middle of the array
			firGen[(size/2)] = 1;
		break;
		case 3:
			//Allows user to pick where 1 values are placed.
			userDefFirstGen(firGen, size);
			break;
		default:
			//If the user enters anything that is not one of the user options
			cout << "Error- You have entered an invalid option!" <<endl;
			cout << "Please try again with the following options:" << endl;
	}
}


/*
	Method that ask the user for a valid filename
	Returns- A valid filename that is not already in the directory
*/
string getFilename(){
	//Iniliase Varaibles
	string filename;
	bool isValid= false;

	//Ask the user to eter a filename
	cout << ""<<endl;
	cout <<"Enter a filename" <<endl;
	cout << ""<<endl;

	cin >>filename;
	
	//Add the file type
	string name= filename+".txt";
	
	// create input file varaible
	ifstream infile(name);

	// if file is open (exists already)
	if(infile.is_open()==true){
		cout <<"The file: " <<filename <<" already exists" << endl;
			// Check if anything was entered
			// While the input is invalid
			while(isValid !=true)
			{
			// Clear the terminal
			system("clear");
			
			// skips stream data
			cin.clear();
			cin.ignore();

			// Send Error message
			cout << "\nError- You did not enter valid filename, try again" << endl; 
			cout << "" << endl;

			//Get a new filename from the user
			cout << ""<<endl;
			cout <<"Enter a filename" <<endl;
			cout <<"" <<endl;

			cin >>filename;

			//Add a file extention
			name= filename+".txt";
			//Check if that file exits
			ifstream infile(name);
			if(infile.is_open()==false){
				//file does not exit
				isValid=true;
			}
		}
	}
	
	return filename;
}


/*
	Writes the data stored in an array into a file
	Parameter: array[]		The Array that the user wants to print.
	Parameter: size 	The size of the array.
	Parameter: filename 	Name of the file that is gonig to be appended.
*/
void appendArrayToFile(int array[],int size, string filename){
	//Create an Object of fstream
	fstream fs;

	//Alter the filename supplied by the user to add a .txt file type
	string name= filename+".txt";
	
	//Open the file to append
	fs.open(name,fstream::app);
	
	//Loop though the full array
	for (int i = 0; i < size; ++i)
	{

		//Append each item of the array into the file
		fs<< array[i];

		if(i != size-1)
		{
			//Add a comma at the end of each line for te file to be able be read properly
			fs << ",";

		}

	}

	fs << endl;
	
	//Close the file
	fs.close();
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

	selectGen(array2, size);

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
	grid[0] = rand() % 99 + 2;
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

	//Display the menu
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

	//Get an input from the user
	cout << "-------------------------------" << endl;
	cout << "Please enter your choice:" << endl;
	cin >> choice;
	cout << "-------------------------------" << endl;
	
	//Error mitigation
	while(!cin || choice <1 || choice > 7)
	{

		system("clear");
		cin.clear();
		cin.ignore(); // skips stream data

		cout << "\nError- An invalid optino was entered please try aain with the options below:" << endl;
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
		cout << "Manual:" << endl;
		cout << "\t7) Custom Dimensions." << endl;

		cout << "-------------------------------" << endl;
		cout << "Please enter your choice:" << endl;
		cin >> choice;
		cout << "-------------------------------" << endl;

	}
	
	//Process the user optinos
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
			while(size < 2 || !cin || size >100)
			{

				cin.clear();
				cin.ignore(); // skips stream data


				// ask user to  re-enter the size
				cout << "\nError- The size you entered is invalid. Please enter a number between 2 and 100." << endl;
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
				cout << "\nError- The number you entered is invalid. Please enter a size greater than 1." << endl;
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

/*
	Will take the binary value as a string and convert it to decimal.
	Returns- The decimal version of the users binary input
*/
int userBinaryRule()
{
	//Variables are initialised to store the binary, decimal, and loop exit.
	string binVal;
	int val = 0;
	bool calculated = false;
	//While the rule has not been calculated loop repeats.
	while(!calculated)
	{

		//A boolean to test if the value entered is 8 bytes
		bool eightByte = false;
		while (!eightByte)
		{
			//Gets user input.
			val = 0;
			cout << "Enter binary value" << endl;
			cin >> binVal;

			//If the entered value is not 8 bytes.
			if (binVal.size() != 8)
			{
				//Will inform user and recieve input again.
				cout << "Make sure you use 8 characters." << endl;
			}
			else
			{
				//Exits input loop.
				eightByte = true;
			}
		}

		//Counts the number of times the for loop repeats.
		int looped = 0;

		//Loops for the string length.
		for (string::iterator i = binVal.begin(); i != binVal.end(); ++i)
		{
			//If the current value of the iterator is either not 1 and 0
			if (*i != '1' && *i != '0')
			{
				//Exits for loop
				i = binVal.end();
				//Makes sure input is recieved once again.
				calculated = false;
				cin.clear();
				cin.ignore(); // skips stream data
				cout << "Error- You have entered an invalid option!" << endl;
				cout << "Value not a binary number. Try again:" << endl;

			}
			else
			{
				//Makes sure loop exits if last char is valid.
				calculated = true;

				//If the value is one, adds the relevant power.
				if (*i == '1')
				{
					val += pow(2,7-looped);
				}
			}

			//Increments the count of the times loop has occured.

			looped++;
		}
	}

	return val;
}

/*
	
	Gets integer user input to convert into binary and store in the parameter varaible.
	Paramter: rule[8]. Array to store the rule.
*/
void getRuleInput()
{
	//Initliaise the Varibles
	int choice;
	
	// Display Menu
	int rule0 = randomRule(), rule1 = randomRule(), rule2 = randomRule();
	cout << "\n-------------------------------" << endl;
	cout << "\tSelect a rule to use." << endl;
	cout << "-------------------------------" << endl;
	cout << "Preset:" << endl;
	cout << "\t1) Rule 30" << endl;
	cout << "\t2) Rule 255" << endl; 
	cout << "\t3) Rule 0" << endl;
	cout << "\t4) Rule 45" << endl;
	cout << "Random:" << endl;
	cout << "\t5) Rule " << rule0 << endl;
	cout << "\t6) Rule " << rule1 << endl;
	cout << "\t7) Rule " << rule2 << endl;
	cout << "Manual:" << endl;
	cout << "\t8) Custom Rule" << endl;
	cout << "\t9) Input Rule as Binary value" << endl;

	//Get the user option
	cout << "-------------------------------" << endl;
	cout << "Enter Choice: " << endl;
	cin >> choice; 
	cout << "-------------------------------" << endl;


	//Error mitigation
	while(!cin || choice < 1 || choice >9)
	{

		cin.clear();
		cin.ignore(); // skips stream data

		cout << "\nInvalid Input." << endl;

		cout << "\nError- You have entered an invalid option!" << endl;
		cout <<"\nPlease try again with the following options:" <<endl;

		cout << "\n-------------------------------" << endl;
		cout << "\tSelect a rule to use." << endl;
		cout << "-------------------------------" << endl;
		cout << "Preset:" << endl;
		cout << "\t1) Rule 30" << endl;
		cout << "\t2) Rule 255" << endl; 
		cout << "\t3) Rule 0" << endl;
		cout << "\t4) Rule 45" << endl;
		cout << "Random:" << endl;
		cout << "\t5) Rule " << rule0 << endl;
		cout << "\t6) Rule " << rule1 << endl;
		cout << "\t7) Rule " << rule2 << endl;
		cout << "Manual:" << endl;
		cout << "\t8) Custom Rule" << endl;
		cout << "\t9) Input Rule as Binary value" << endl;

		cout << "-------------------------------" << endl;
		cout << "Enter Choice: " << endl;
		cin >> choice; 
		cout << "-------------------------------" << endl;

	}


	// store integer
	int ruleN;

	//Process user Options
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
				cout << "\nError- The rule you entered is invalid. Please enter a vlue between 0-255." << endl;
				cout << "Please enter the rule: " << endl;
				cin >> ruleN;

			}

			cout << endl;
		break;
		case 9:
			//Will allow user to enter a binary value to compute.
			bool correct = false;
			while(!correct)
			{
				ruleN = userBinaryRule();
				cout << "You entered rule " << ruleN << endl;
				cout << "To confirm value enter relevant option:" << endl;
				cout << "1) Confirm" << endl;
				cout << "2) Re-enter value" << endl;
				int option;
				cin >> option;
				//If user confirms loop exits.
				if (option == 1)
				{
					correct = true;
				}else{
					cin.clear();
				cin.ignore(); // skips stream data
				}
			}
			
		break;
	}

	// calculate the binary number of the integer
	calculateBinary(rule, ruleN);
}

/*
	Will allow the user to choose the values that will constitute the first generation.
*/
void userDefFirstGen(int gen[], int size)
{	
	int rep;
	int sel;


	//Get the first generation from the user
	cout << "The first generation has " << size << " elements in it." << endl;
	cout << "Enter the number of 1s/Black values you want." << endl;
	cin >> rep;

	while(!cin){
		// skips stream data
		cin.clear();
		cin.ignore(); 

		//Send Error message
		cout << "\nError- You have entered an invalid option!" <<endl;
      	cout << "Please try again with the following options:" <<endl;
		cin >> rep;
	}


	for (int i = 0; i < rep; ++i)
	{
		bool notWithinRange = true;
		do
		{
			cout << "Enter a number for the position where you would like to make 1." << endl;
			cin >> sel;
			if (sel > size)
			{
				cout << "Value out of range. Enter a value below " << size << "." << endl;
				notWithinRange = false;
			}
			else
			{
				notWithinRange = true;
				if (gen[sel-1] == 1)
				{
					cout << "Value is already set to 1." << endl;
					i--;
				}
				else
				{
					gen[sel-1] = 1;
				}
			}
		}while(!notWithinRange);
	}
}

/*
	Will calculate the binary value of a decimal number. Will fill an array with the values representing the binary value of the input decimal number.
	Parameter: arr[8]. Array that contains a binary number
	Parameter: val. number being converte
*/
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
	int willBeSavedToFile=0;
	string filename= "";


	//Ask User if they want to print to file
	cout << "Do you want to print the the Cellular Automata to file?"<< "\n" <<"1. Yes"<< "\n" << "2. No"<<endl;
	cin >> willBeSavedToFile;

			// While the opton entered is not one of the options or is an incorrect varaible type
			while(!cin || willBeSavedToFile <1 || willBeSavedToFile > 2)
			{
				cin.clear();
				cin.ignore(); // skips stream data


				// ask user to  re-enter the size
				cout << "\nError- The option you have entered is invalid. Please choose a number from the options below: " << endl;
				//Ask User if they want to print to file
				cout << "Do you want to print the the Cellular Automata to file?"<< "\n" <<"1. Yes"<< "\n" << "2. No"<<endl;
				cin >> willBeSavedToFile;
			}

			if(willBeSavedToFile==1){
				//Get the filename form the user
				filename= getFilename();
			}
	

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

		if (willBeSavedToFile==1){
		//Print the generation to a file
			appendArrayToFile(previousGeneration,sizeGeneration, filename);
		}

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
			cout << "\u25A1" << " ";
		}
		else
		{
			cout << "\u25A0" << generation[i];

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


	for(int i = 9; i < 15; i++)
	{

		for(int j = 9; j <15; j++)
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

				cout << "\u25A1" << " "; 

			}
			else
			{

				// display white
				cout << "\u25A0" << previousGeneration[i][j];

			}

		}

		cout << reset << endl;

	}

	// do 100 times
	for(int m = 0; m <60; m++)
	{

		// display name
		cout << "\n\t\t\t\t  GAME OF LIFE" << "\t\tDuration: " << m << "/60 seconds." << endl;

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

					cout << "\u25A1" << " ";

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
	
	Generates A 20x20 2D automata.

*/
void Generate2DAutomata()
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
	for(int i = 10; i < 14; i++)
	{

		for(int j = 10; j <14; j++)
		{	

			previousGeneration[i][j] = 1;
			previousGeneration[sizeX-i][sizeX-j] = 1;

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

				cout << "\u25A1" << " "; 

			}
			else
			{

				// display white
				cout << "\u25A0" << previousGeneration[i][j];

			}

		}

		cout << reset << endl;

	}

	// do 100 times
	for(int m = 0; m <60; m++)
	{

		// display name
		cout << "\n\t\t\t\t  2D Cellular Automata" << "\t    Duration: " << m <<"/60 seconds." << endl;

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
				
				// if black
				if(previousGeneration[i][j] == 1) 
				{	

					// if have even 1s
					if(aliveNeb == 0 || aliveNeb == 2 || aliveNeb == 4 || aliveNeb == 6 || aliveNeb == 8)
					{

						// becomes white
						nextGeneration[i][j] = 0;

					}

				}

				// if white
				else if(previousGeneration[i][j] == 0)
				{

					// if have no even 1s
					if(!(aliveNeb == 0 || aliveNeb == 2 || aliveNeb == 4 || aliveNeb == 6 || aliveNeb == 8))
					{

						// becomes black
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

					cout << "\u25A1" << " ";

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
	Loads Cellular Automata loaded from an external text file
*/
void load()
{

	cout << "\nAvailable files to load: \n" << endl;
	
	// Display txt files vetically
	system("ls | grep .txt | cat");

	// Variable to store user input
	string filename;

	// Ask for user input
	cout << "\nPlease enter the filename (Without the file type): " << endl;
	cin >> filename;

	// Add .txt to string to make it easier for opening file
	filename += ".txt";

	// create input file varaible
	ifstream infile;

	// Open file as input
	infile.open(filename, ios::in);

	// if file is open (exists in this case)
	if(infile.is_open() == 1)
	{

		// P0W how-to-detect-empty-file-in-c stackoverflow
		// If file is empty 
		if(infile.peek() == ifstream::traits_type::eof())
		{

			cout << "\nFILE IS EMPTY. " << endl;

		}
		else
		{

			cout << "\nDISPLAYING FILE: " << endl;

			// For every line
			while(!infile.eof())
			{

				// local varaibles
				string line;
				vector<int> vect;

				// get next line in the file
				getline(infile, line);

				// store line in stringstream
				stringstream ss(line);

				unsigned int i;

				// while
				while (ss >> i)
				{

					// push i onto back of string
					vect.push_back(i);

					// if string has ", or " " ignore
					if(ss.peek() == ',' || ss.peek() == ' ')
					{

						ss.ignore();

					}

				}

				// for every 1 and 0 in file display it
				for(i=0; i <vect.size(); i++)
				{

					if(vect.at(i) == 1)
					{

						cout << "\u25A1" << " ";

					}
					else
					{

						cout << "\u25A0" << vect.at(i);

					}

				}

				cout << endl;

			}

		}

	}
	else
	{
		cout << "\nError- The file ente does not exist" << endl;
		cout << "Try again: " << endl;
	}

	// close file
	infile.close();

}

/*
	Main Method
*/
int main()
{

	menu();
	
}

