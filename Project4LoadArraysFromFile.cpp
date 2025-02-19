#include "myheader.h"

void LoadArraysFromFile(ifstream &inFile, string first[], string last[],
						int numbers[], float balance[], int SIZE, int &count)
{

	while (!(inFile.eof()) && count < SIZE)
	{
		inFile >> first[count];
		inFile >> last[count];
		inFile >> numbers[count];
		inFile >> balance[count];
		count++;
	}
}
