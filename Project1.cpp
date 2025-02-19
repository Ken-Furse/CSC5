/*******************************************************************************
* AUTHOR		: Kenneth Furse 											   *
* PROJECT #1	: Basic Input/Output										   *
* CLASS			: CSC5														   *
* SECTION 		: MW 2:20PM - 5:30PM										   *
* DUE DATE 		: 03/11/2024												   *
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*******************************************************************************
*
* COMPUTE RETROACTIVE PAY
* ______________________________________________________________________________
* This program accepts as user input an employee name, current annual
* salary and percent increase and computes a new annual salary, new monthly
* salary and retroactive pay due. The program will execute three times
* prompting the user for the appropriate input and then displaying the
* computed values for the given input.
*
* computations are based on the assumption that input values are effective
* on January 1 and calculations are effective for July 1.
* ______________________________________________________________________________
* INPUT
* 	nameFull			: Employee's full name
* 	salaryCurrent		: Current annual salary
* 	percentIncrease		: Percent increase due
*
* OUTPUT
* 	salaryNew			: New Salary after applying rate increase
* 	salaryMonthly		: Current annual salary
* 	retroactivePay		: Retroactive pay due to employee
*
*******************************************************************************/
int main ()
{
	/***************************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------------
	 * MONTHS			: Total number of months
	 * RETRO_MONTHS		: Number of months retroactive
	 **************************************************************************/
	const int MONTHS = 12;
	const int RETRO_MONTHS = 6;
	const char PROGRAMMER[30] = "Kenneth Furse";
	const char CLASS[5] = "CSC5";
	const char SECTION[30] = "MW 2:20-5:30";
	const int ASSIGNMENT_NUM = 1;
	const char ASSIGNMENT_NAME[25] = "Basic Input / Output";

	string nameFull;		// INPUT - Employee's full name
	float salaryCurrent;	// INPUT - Current annual salary
	float percentIncrease;	// INPUT - Percent increase due
	float salaryNew;		// OUTPUT - New salary after increase
	float salaryMonthly;	// OUTPUT - New monthly salary
	float retroactivePay;	// OUTPUT - Retroactive pay due to employee
	int count;				// CALC - Counter for loop

	count = 0;

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMED BY  : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " <<
			ASSIGNMENT_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;
	while (count < 3)
	{
		cout << left << setw(29) << "What is your name?";
		getline (cin,nameFull);
		cout << left << setw(29) << "What is your current salary?";
		cin >> salaryCurrent;
		cout << left << setw(29) << "What is your pay increase?";
		cin >> percentIncrease;

		salaryNew = (salaryCurrent * percentIncrease) + salaryCurrent;
		salaryMonthly = (salaryNew/MONTHS);
		retroactivePay = (salaryNew / (MONTHS/RETRO_MONTHS)) -
		(salaryCurrent / (MONTHS/RETRO_MONTHS));

		cout << endl;
		cout << right << nameFull << "'s SALARY INFORMATION" << endl;
		cout << right << setw(10) << "New Salary" << setw(19) <<
				"Monthly Salary" << setw(20) << "Retroactive Pay" << endl;
		cout << right << showpoint << fixed << setprecision(2) << setw(10) <<
				salaryNew << setw(19) << salaryMonthly << setw(20) <<
				retroactivePay << endl;

		count+=1;
		cout << "\n <Press enter to continue>\n\n";
		cin.ignore();
		cin.get();
	}

	return 0;
}
