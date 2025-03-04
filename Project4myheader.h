#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;
/*******************************************************************************
 * LoadArraysFromFile Function
 * -----------------------------------------------------------------------------
 * This function accepts the input file stream as well as arrays for first
 * name, last name, account number, account balance, array size, and a counter.
 * The input file operation will read names, account numbers, and account
 * balances from the input file to the associated arrays. This loop will iterate
 * for the array size number of times. The counter will keep track of how many
 * accounts were read from the file.
 ******************************************************************************/
void LoadArraysFromFile(ifstream &inFile, string first[], string last[],
						int numbers[], float balance[], int SIZE, int &count);

/*******************************************************************************
 * SearchForMatch Function
 * -----------------------------------------------------------------------------
 * This function accepts arrays for first name and last name, as well as input
 * for first and last name to be searched for, and count. The function will then
 * search for a match of both first and last names. If a match is found, index
 * number for the array is documented. This loop will iterate "count" number of
 * times.
 ******************************************************************************/
int SearchForMatch(string first[], string firstSearch, string last[],
					string lastSearch, int count);

/*******************************************************************************
 * PrintHeaderToFile Function
 * -----------------------------------------------------------------------------
 * This function accepts the output file stream. The function will then output
 * to the selected output text file the programmer, class name, class number,
 * project name, and project number formatted to form a class header.
 ******************************************************************************/
void PrintHeaderToFile(ofstream &outFile);

/*******************************************************************************
 * PrintReportToFile Function
 * -----------------------------------------------------------------------------
 * This function accepts the output file stream, arrays for full name, account
 * number, account balance, and matches, as well as the match counter, and the
 * average balance for all found accounts. This Function will then output all
 * data for the accounts that were found to the selected output file.
 ******************************************************************************/
void PrintReportToFile(ofstream &outFile, string full[],int numbers[],
						float balance[], int matches[], int matchCount,
							float average);
