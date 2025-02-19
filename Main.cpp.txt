/*******************************************************************************
* AUTHOR		: Kenneth Furse 											   *
* PROJECT #4	: Parallel Arrays							                   *
* CLASS			: CSC5														   *
* SECTION 		: MW 2:20PM - 5:30PM										   *
* DUE DATE 		: 05/22/2024												   *
*******************************************************************************/

#include "myheader.h"

/*******************************************************************************
*
* Generate Statement
* ______________________________________________________________________________
*
* This program will accept input and output file names, the input file will be
* used to read all names, account numbers, and account balances into arrays.
* User input will be used to search for names gathered from input file. All
* found account numbers, names, and balances will be output in formatted form to
* the output file designated by the user, as well as the average balance for
* all found accounts.
* ______________________________________________________________________________
* INPUT
*  inFileName			// Input File name input by user
*  outFileName			// Output File name input by user
*
*
* OUTPUT
*  full					// Full Name of the account found by program
*  numbers				// Account number of the account found by program
*  balance				// Account balance of the account found by program
*  average				// average balance of all accounts found by program
*
*
*******************************************************************************/
/*******************************************************************************
 * CONSTANTS
 * -----------------------------------------------------------------------------
 * SIZE					// Largest allowed number of components within array
 ******************************************************************************/

int main ()
{
	// Declaring Variables
	const int SIZE = 30;		// Maximum size of arrays
	string first[SIZE];			// First name array read from infile
	string last[SIZE];			// Last name array read from infile
	int numbers[SIZE];			// Account number array read from infile
	float balance[SIZE];		// Balance array read from infile
	int count = 0;				// Counter for list size
	ifstream inFile;			// Input file operations
	ofstream outFile;			// Output file operations
	string outFileName;			// Output file name
	string inFileName;			// Input file name
	string firstSearch;			// First name entered by user
	string lastSearch;			// Last Name entered by user
	int match;					// Contains index of found account
	int matchCount = 0;			// Counter for total number of matches
	int matches[SIZE];			// Array used to store index numbers of matches
	string full[SIZE];			// Full Name of account member
	float total = 0;			// Total balance for all found accounts
	float average;				// Average balance of all found accounts

	// Input Data - Gathering file names
	cout << left << setw(40) << "What input file would you like to use?";
	cin >> inFileName;
	cout << left <<  setw(40) << "What output file would you like to use?";
	cin >> outFileName;

	// Input File Operation with Function Call
	inFile.open(inFileName.c_str());
	LoadArraysFromFile(inFile, first, last, numbers, balance, SIZE, count);
	inFile.close();

	//Input Validation
	cout << endl << "Who do you want to search for (enter done to exit) : ";
	cin >> firstSearch;
	if (firstSearch != "done" && firstSearch != "Done")
		cin >> lastSearch;
	else if(firstSearch == "done" || firstSearch == "Done")
		cout << endl << "Thank you for using my program." << endl;

	// Search For Match Function Call with input validation
	while (firstSearch != "done" && firstSearch != "Done")
	{
		match = SearchForMatch(first, firstSearch, last, lastSearch, count);
		if (match >= 0)
		{
			matches[matchCount] = match;
			matchCount++;
		}

		else if (firstSearch != "done" && firstSearch != "Done")
		cout << firstSearch << " " << lastSearch << " was not found." <<
				endl << endl;

		else if(firstSearch == "done" || firstSearch == "Done")
				cout << endl << "Thank you for using my program." << endl;

		cout << "Who do you want to search for (enter done to exit) : ";
		cin >> firstSearch;
			if (firstSearch != "done" && firstSearch != "Done")
				cin >> lastSearch;

			else if(firstSearch == "done" || firstSearch == "Done")
				cout << endl << "Thank you for using my program." << endl;
	}

	// Combining First and Last names into Full Names
	for (int c = 0; c < matchCount; c ++)
	{
		full[matches[c]] += first[matches[c]];
		full[matches[c]] += " ";
		full[matches[c]] += last[matches[c]];
	}

	// Calculate Total balance of all found accounts
	for (int c = 0; c < matchCount; c ++)
		{
			total += balance[matches[c]];
		}

	// Calculate Average balance of all found accounts
	average = total/matchCount;


	// Output File Operations Print Header + Report to file Function Calls
	outFile.open(outFileName.c_str());
	PrintHeaderToFile(outFile);
	PrintReportToFile(outFile, full, numbers, balance, matches,
						matchCount, average);
	outFile.close();

	return 0;
}
