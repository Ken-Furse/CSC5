/*******************************************************************************
* AUTHOR		: Kenneth Furse 											   *
* PROJECT #3	: Functions								                       *
* CLASS			: CSC5														   *
* SECTION 		: MW 2:20PM - 5:30PM										   *
* DUE DATE 		: 05/08/2024												   *
*******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/*******************************************************************************
*
* Generate Gross Sales
* ______________________________________________________________________________
*
* This program will calculate Gross sales after discount, sales tax, and
* shipping costs are added.
*
* Program will run 3 times before completing.
* ______________________________________________________________________________
* INPUT
*  numberAccount		: Number of member bank account
*  month				: month ordered
*  day					: day ordered
*  year					: year ordered
*  codeCounty			: county code for LA, OC, and San Diego
*  sales				: amount sold in dollars
*  weight				: weight of product to be shipped

* OUTPUT
*  sales				: Amount sold in dollars
*  discount				: Amount discounted due to time of year
*  salestaxed			: Amount taxed based on county code
*  shipping				: Amount charged for shipping based on weight
*  total				: Total amount payed
*
*
*******************************************************************************/
/*******************************************************************************
 * GetSalesInfo Funtion
 * -----------------------------------------------------------------------------
 * The purpose of this function is to gather from the user, an account number,
 * date of purchase, county code, sale amount, and weight of product. These
 * values will be brought back into the main function for use.
 ******************************************************************************/
void GetSalesInfo (int &account, int &month, int &day, int &year, char &code,
					float &sales, int &weight);

/*******************************************************************************
 * CalcDiscount Function
 * -----------------------------------------------------------------------------
 * The purpose of this function is to use the month of sale to determine the
 * discount rate applied to the sale.
 ******************************************************************************/
float CalcDiscount (int month, float sales);

/*******************************************************************************
 * CalcSalesTax Function
 * -----------------------------------------------------------------------------
 * The purpose of this function is to use the county code to determine what
 * sales tax rate will be used for the sale.
 ******************************************************************************/
float CalcSalesTax (char code, float salesDiscounted);

/*******************************************************************************
 * CalcShipping Function
 * -----------------------------------------------------------------------------
 * The purpose of this function is to determine the amount of shipping costs
 * applied to the sale based on the weight of the product sold.
 ******************************************************************************/
float CalcShipping (int weight, float salesTaxed);

/*******************************************************************************
 * OutputInvoice Function
 * -----------------------------------------------------------------------------
 * the purpose of this function is to gather the data from the main function
 * and output it in a formatted form.
 ******************************************************************************/
void OutputInvoice (int account, char code, int month, int day, int year,
					float sales, float discount, float salesTaxed,
					float shipping, float total);

/***************************************************************************
 * CONSTANTS
 * -------------------------------------------------------------------------
 *  SPRING			: discount appied when purchased in spring
 *  SUMMER			: discount appied when purchased in summer
 *  FALL			: discount appied when purchased in fall
 **************************************************************************/

const char PROGRAMMER[30] = "Kenneth Furse";
const char CLASS[5] = "CSC5";
const char SECTION[30] = "MW 2:20-5:30";
const int ASSIGNMENT_NUM = 3;
const char ASSIGNMENT_NAME[40] = "Functions";

int main ()
{

	int numberAccount;		//INPUT - Number of member bank account
	int month;				//INPUT - month ordered
	int day;				//INPUT - day ordered
	int year;				//INPUT - year ordered
	char codeCounty;		//INPUT - county code for LA, OC, and San Diego
	float sales;			//INPUT - amount sold in dollars
	int weight;				//INPUT - weight of product to be shipped
	float discount;			//OUTPUT - Amount discounted due to time of year
	float salesDiscounted;	//CALC - Sale value updated with discount
	float taxAmount;		//CALC - Amount taxed based on county code
	float salesTaxed;		//OUTPUT - Sale value updated with tax
	float shipping;			//OUTPUT - Shipping charges based on weight
	float total;			//OUTPUT - Total amount payed
	int count;				//CALC - count for for loop


	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMED BY  : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << setw(2) << ASSIGNMENT_NUM << ": " <<
			ASSIGNMENT_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	for (count = 0; count < 3; count++)
	{
	GetSalesInfo (numberAccount, month, day, year, codeCounty, sales, weight);
	discount = CalcDiscount (month, sales);
	salesDiscounted = sales - discount;
	taxAmount = CalcSalesTax (codeCounty, salesDiscounted);
	salesTaxed = salesDiscounted + taxAmount;
	shipping = CalcShipping (weight, salesTaxed);
	total = salesTaxed + shipping;
	OutputInvoice (numberAccount, codeCounty, month, day, year, sales, discount,
			salesTaxed, shipping, total);
	}

	return 0;
}

void GetSalesInfo (int &account, int &month, int &day, int &year, char &code,
		float &sales, int &weight)
{
	cout << "Please Enter your Account Number: ";
	cin >> account;
	cout << "Please Enter the Sales Date." << endl;
	cout << "Enter Month: ";
	cin >> month;
	cout << "Enter Day: ";
	cin >> day;
	cout << "Enter Year: ";
	cin >> year;
	cout << "Please Enter the County Code: ";
	cin >> code;
	cout << "Please Enter the Sales Amount: ";
	cin >> sales;
	cout << "Please Enter the Weight: ";
	cin >> weight;
}

float CalcDiscount (int month, float sales)
{
	const float SPRING = .05;
	const float SUMMER = .1;
	const float FALL = .15;
	float discount;

	if (month <= 5)
		discount = sales * SPRING;
	else if (month <= 8)
		discount = sales * SUMMER;
	else if (month <= 12)
		discount = sales * FALL;
	return discount;
}

float CalcSalesTax (char code, float salesDiscounted)
{
	const float ORANGE = .0775;
	const float SAN_DIEGO = .0825;
	const float LOS_ANGELES = .0800;
	float tax;

	switch(code)
	{
	case 'o':
	case 'O': tax = salesDiscounted * ORANGE;
			  break;
	case 's':
	case 'S': tax = salesDiscounted * SAN_DIEGO;
			  break;
	case 'l':
	case 'L': tax = salesDiscounted * LOS_ANGELES;
			  break;
	}

	return tax;
}

float CalcShipping (int weight, float salesTaxed)
{
	const float MEDIUM = .10;
	const float HEAVY = .07;
	float shipping;

	if (weight <= 25)
		shipping = 5.00;
	else if (weight <= 50)
		shipping = 5.00 + ((weight-25) * MEDIUM);
	else if (weight > 50)
		shipping = 5.00 + (25 * MEDIUM) + ((weight-50) * HEAVY);

	return shipping;
}

void OutputInvoice (int account, char code, int month, int day, int year,
					float sales, float discount, float salesTaxed,
					float shipping, float total)
{
	cout << endl;
	cout << left << setw(35) << "ACCOUNT NUMBER" << right << setw(10)
			<< "COUNTY" << endl;

	switch(code)
		{
		case 'o':
		case 'O': cout << setw(5) << "" << left << setw(31) << account << right
					<< setw(5) << "Orange County" << endl << endl;
				  break;
		case 's':
		case 'S': cout << setw(5) << "" << left << setw(31) << account << right
					<< setw(10) << "San Diego" << endl << endl;
				  break;
		case 'l':
		case 'L': cout << setw(5) << "" << left << setw(31) << account << right
					<< setw(5) << "Los Angeles" << endl << endl;
				  break;
		}
	cout << left << setw(14) << "DATE OF SALE:" << month << "/" << day << "/"
			<< year << endl << endl << endl;
	cout << left << setw(19) << "SALE AMOUNT:" << setw(1) << "$" << fixed
			<< setprecision(2) << right << setw(8) << sales << endl;
	cout << left << setw(19) << "DISCOUNT:" << setw(1) << "$" << fixed
				<< setprecision(2) << right << setw(8) << discount << endl;
	cout << left << setw(19) << "SALES TAX:" << setw(1) << "$" << fixed
				<< setprecision(2) << right << setw(8) << salesTaxed << endl;
	cout << left << setw(19) << "SHIPPING:" << setw(1) << "$" << fixed
				<< setprecision(2) << right << setw(8) << shipping << endl;
	cout << left << setw(19) << "TOTAL DUE:" << setw(1) << "$" << fixed
				<< setprecision(2) << right << setw(8) << total << endl << endl
				<< endl;
}
