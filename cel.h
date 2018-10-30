#ifndef __CELLULLARAUTOMATA_H_INCLUDED__
#define __CELLULLARAUTOMATA_H_INCLUDED__

#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Daniel Langr https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
const std::string red("\033[1;31m");	// Makes output red coloured.
const std::string reset("\033[0m");		// Makes output black coloured.

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

// defining all functions in the program
void menu();
int SubMenu();
void generateCellularAutomata();
void getDimensions(int &size, int &generations);
void initGenerations(int array[], int size);
void getRuleInput();
void calculateBinary(int rule[8],int val);
void computeGenerations(int nextGeneration[], int previousGeneration[], int nGenerations, int sizeGeneration);
void displayGeneration(int generation[], int size);
void binary2Number(int binaryN[8]);
void computeGameOfLife();
void generateGameOfLife();
void print(int array[], int size);
void generateFirstGeneration(int x, int gen[]);
void userDefFirstGen(int gen[], int size);
void load();

#endif
