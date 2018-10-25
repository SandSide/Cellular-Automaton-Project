#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// Daniel Langr https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
const std::string red("\033[1;31m");	// Makes output red coloured.
const std::string reset("\033[0m");		// Makes output black coloured.

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


/*
	
		Creates 1-D Cellular Automata which is looped at the sides.

		Parameter: nextGeneration[]. Array which will contain next generation based on previous generation.
		Parameter: previousGeneration[]. Array which contains first generation. Will store previous generation as a new one is being created.
		Parameter: rule[]. Contains the rule.
		Parameter: nGenerations. Number which specifies how many generations will be made.
		Parameter: sizeGeneration. Number which specifies the size of each generation.
*/
	
void computeGenerations()
{

	int aliveNeb = 0;
	const int sizeX = 40;
	const int sizeY = 40;

	int previousGeneration[sizeY][sizeX];
	int nextGeneration[sizeY][sizeX];

	for (int j = 0; j <sizeY; j++)
	{
		// for every item in the generation, make it 0
		for(int i = 0; i <sizeX ; i++)
		{

			previousGeneration[j][i] = 0;
			nextGeneration[j][i] = 0;

		}
	}

	system("clear");
	system("clear");


	for(int i = 10; i < 20; i++)
	{

		for(int j = 10; j <20; j++)
		{	

			previousGeneration[i][j] = 1;

		}

	}


	previousGeneration[0][0] = 1;
	previousGeneration[0][1] = 1;
	previousGeneration[0][1] = 1;


	for (int i = 0; i < sizeY; i++)
	{

		// for every item in the generation, make it 0
		for(int j = 0; j <sizeX ; j++)
		{

			if (previousGeneration[i][j] == 1)
			{

				cout << "\u25A1" << previousGeneration[i][j];

			}
			else
			{

				cout << "\u25A0" << previousGeneration[i][j];

			}

		}

		cout << reset << endl;

	}


	for(int m = 0; m <100; m++)
	{

		for(int i = 0; i < sizeY ; i++)
		{

			for(int j = 0; j <sizeX ; j++)
			{

				if(i == 0 && j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][sizeX-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);

				}

				else if (i == (sizeY-1) && j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[0][sizeX-1] + previousGeneration[0][j] + previousGeneration[0][j+1]);

				}

				else if (i == 0 && j == (sizeX - 1))
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][j-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][0]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][0]);
					aliveNeb += (previousGeneration[i+1][j-1] + previousGeneration[i+1][j] + previousGeneration[i+1][0]);

				}

				else if (i == (sizeY-1) && j == (sizeX - 1))
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][0]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][0]);
					aliveNeb += (previousGeneration[0][j-1] + previousGeneration[0][j] + previousGeneration[0][0]);

				}

				else if(i == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[sizeY-1][j-1] + previousGeneration[sizeY-1][j] + previousGeneration[sizeY-1][j+1]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][j+1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);


				}

				else if(i == sizeY -1)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][j-1] + previousGeneration[i-1][j] + previousGeneration[i-1][j+1]);
					aliveNeb += (previousGeneration[i][j-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[0][j+1] + previousGeneration[0][j] + previousGeneration[0][j+1]);

				}

				else if(j == 0)
				{

					aliveNeb = 0;
					aliveNeb += (previousGeneration[i-1][sizeX-1] + previousGeneration[i-1][j] + previousGeneration[i-1][j+1]);
					aliveNeb += (previousGeneration[i][sizeX-1] + previousGeneration[i][j+1]);
					aliveNeb += (previousGeneration[i+1][sizeX-1] + previousGeneration[i+1][j] + previousGeneration[i+1][j+1]);

				}

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

				if(previousGeneration[i][j] == 1)
				{

					if(aliveNeb < 2)
					{

						nextGeneration[i][j] = 0;

					}
					else if(aliveNeb == 3 || aliveNeb == 2)
					{

						nextGeneration[i][j] = 1;

					}
					else if(aliveNeb > 3 )
					{

						nextGeneration[i][j] = 0;

					}

				}
				else if(previousGeneration[i][j] == 0)
				{

					if(aliveNeb == 3)
					{

						nextGeneration[i][j] = 1;

					}

				}

			}

		}

	    sleep_until(system_clock::now() + 1s);
	    system("clear");
	   	system("clear");

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


int main()
{

	computeGenerations();
	
}

