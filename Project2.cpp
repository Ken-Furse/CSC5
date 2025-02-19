/*******************************************************************************
* AUTHOR		: Kenneth Furse 											   *
* PROJECT #2	: Repetition & Switch Statement								   *
* CLASS			: CSC5														   *
* SECTION 		: MW 2:20PM - 5:30PM										   *
* DUE DATE 		: 04/03/2024												   *
*******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************************************
*
* COMPUTE GPA
* ______________________________________________________________________________
*
* This program gathers letter grades as input, then validates and assigns a
* point value to each input. The program then calculates both the class total
* and grade point average for each class.
*
* Program will run 3 times before completing.
* ______________________________________________________________________________
* INPUT
* 	grade				: Letter grade
*
* CALCULATIONS
* 	gradeAmount			: Total number of valid letter grades input.
* 	count				: Counter for the loop.
*
* FLAG
* 	exit				: Flags the end of inputs for that class.
*
* OUTPUT
* 	gradePoints			: Total sum of all grades
* 	gradeAverage		: average grade point average
*
*******************************************************************************/

int main ()
{
	/***************************************************************************
	 * CONSTANTS
	 * -------------------------------------------------------------------------
	 * GRADE_A			: GPA value for letter grade A
	 * GRADE_B			: GPA value for letter grade B
	 * GRADE_C			: GPA value for letter grade C
	 * GRADE_D			: GPA value for letter grade D
	 * GRADE_F			: GPA value for letter grade F
	 **************************************************************************/

	const char PROGRAMMER[30] = "Kenneth Furse";
	const char CLASS[5] = "CSC5";
	const char SECTION[30] = "MW 2:20-5:30";
	const int ASSIGNMENT_NUM = 2;
	const char ASSIGNMENT_NAME[40] = "Repetition & Switch Statement";
	const int GRADE_A = 4;		// CONST - GPA value for letter grade A.
	const int GRADE_B = 3;		// CONST - GPA value for letter grade B.
	const int GRADE_C = 2;		// CONST - GPA value for letter grade C.
	const int GRADE_D = 1;		// CONST - GPA value for letter grade D.
	const int GRADE_F = 0;		// CONST - GPA value for letter grade F.
	char grade;					// INPUT - Letter grade.
	int gradeAmount;			// CALC - Total # of valid letter grades input.
	int count;					// CALC - Counter for loop.
	bool exit = false;			// FLAG - End of inputs for that class.
	float gradePoints;			// OUTPUT - Total sum of all grades.
	float gradeAverage;			// OUTPUT - Average grade point average.
	count = 1;

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMED BY  : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " <<
			ASSIGNMENT_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;



		while(count < 4)
		{
			exit = false;
			gradeAmount = 0;
			gradePoints = 0;
			cout << "TEST #" << count << ":" << endl << endl;

			while (!exit)
			{

				cout << setw(46) << "Enter Letter Grade (enter 'X' to exit):";
				grade = cin.get();
				cin.get();


				switch(grade)
				{
					case 'a':
					case 'A': gradePoints += GRADE_A;
							  gradeAmount +=1;
							  exit = false;
							  break;
					case 'b':
					case 'B': gradePoints +=GRADE_B;
							  gradeAmount +=1;
							  exit = false;
							  break;
					case 'c':
					case 'C': gradePoints +=GRADE_C;
							  gradeAmount +=1;
							  exit = false;
							  break;
					case 'd':
					case 'D': gradePoints +=GRADE_D;
							  gradeAmount +=1;
							  exit = false;
							  break;
					case 'f':
					case 'F': gradePoints +=GRADE_F;
							  gradeAmount +=1;
							  exit = false;
							  break;
					case 'x':
					case 'X': exit = true;
							  break;
					default: cout << "\n" << setw(46)
							<< "Invalid letter grade,please try again\n\n";
							  exit = false;
				}
			}

			// Calculating GPA
			gradeAverage = gradePoints/gradeAmount;

			//Output Results
			if (gradePoints > 0)
			{
				cout << endl << fixed << setprecision(0) <<
						"Total Grade Points: " << gradePoints << endl;
				cout << fixed << setprecision(2) << "GPA: " << gradeAverage <<
						endl << endl <<endl;
			}
			count +=1;
		}
	return 0;
}
