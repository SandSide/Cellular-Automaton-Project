#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

int number2Binary(int number);
int textToASCII(string text);

ifstream infile("text_ASCII.cpp");

int textToASCII(string text)
{

	char c;

    for (int i = 0; i < text.length(); i++)
    {

        c = text.at(i);
		//number2Binary(int(c));

        cout << int(c);

    }

    cout << endl;
}

int number2Binary(int number)
{

	/*
	 int num = number;
	 int arr[8];

	 int i=0,r;
	 
	 while(num!=0)
	{

	  r = num%2;
	  arr[i++] = r;
	  num /= 2;

	}

	for(int j=i-1;j>=0;j--)
	{

	 	cout<<arr[j];

	}
*/

	int num = number;
	int r = 0;	
	int arr[8];
	int col = 128;

	r = num%col;

	for (int i = 0; i <8; i++)
	{

	  r = num/col;
	  if(r != 0)
	  {

	  	arr[i] = 1;
	  	num -= col;

	  }
	  else
	  {

	  	arr[i] = 0;

	  }

	  col = col/2;

	  cout << arr[i];

	}

}


int main()
{
	
	string line;

	while (getline(infile, line))
	{

		if (line != "")
		{

			textToASCII(line);

		}

	}
	
}