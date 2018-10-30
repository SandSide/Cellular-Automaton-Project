#include "cel.h"






void appendMethod(int array[],int size, string filename){
	//Create an Object of fstream
	fstream fs;

	//Alter the filename supplied by the user to add a .txt file type
	string name= filename+".txt";
	
	//Open the file to append
	fs.open(name,fstream::app);
	
	//Loop though the full array
	for (int i = 0; i < size; ++i){
		//Append each item of the array into the file
		fs<< array[i];
	}
	
	//add a comma to the end to speprate a line
	fs<< ",\n";
	
	//Close the file
	fs.close();
}

int main()
{

	int array[4] ={3,4,5,6};
	
	string filename="test2";

	for (int i = 0; i < 6; ++i)
	{
		appendmethod(array,filename);
	}

	return 0;
}