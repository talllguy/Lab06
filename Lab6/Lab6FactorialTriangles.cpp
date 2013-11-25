/***************************************************************************
COSC 501
Lab 6
Elliott Plack
12 OCT 2013											   Due date: 14 OCT 2013
Problem: Two functions: One computes factorials between 1 and 8, the other
	draws triangles with asterisks * based on user input.
Algorithm: Use a switch case to give the user the option to pick which
	function to do.
	Factorials: input in the main with logic checks to decide if the input
	is valid and within the range. Calculate the result in a separate
	function with the formula x *= i in a for loop.	Set the initial value
	equal to a temporary variable that will control	how many times the loop
	should run. return result back to the main and output.
	Triangles: input in the main the number of triangles and the number of
	stars to have on the last row. Validate inputs in the main and send the
	results to the triangle drawing function, which will be a void function.
	in the void triangles function, do two nested loops, one for the number
	of triangles, and one for the number of stars. The first loop will have
	a check to see if it should ask how many stars before repeating.

*/

#include <iostream>
#include <string>
using namespace std;

int factorial(int); //  calculation function
void triangle (int,int); // triangle output function

int main()
{
	char funct_choice; // character that will determine program route
	int result(0), number_to_fac(0);
	int triangles_number(0), triangles_stars(0);
	cout << "This program performs two functions.\n";
	cout << "Select from one of two functions below\n";
	cout << "   1 ... Compute a factorial\n";
	cout << "   2 ... Draw triangles with '*'s\n";
	cout << "To quit, press any other key.\n";
	cout << "Please select a function: ";
	cin >> funct_choice;
	
	switch(funct_choice)  // switch case menu to call functions
	{
	case '1':
		cout << "Enter an integer to compute the factorial of (Between 1 and 8): ";
		while ((!(cin >> number_to_fac)) || (number_to_fac < 1) || (number_to_fac > 8)) // Get the input and validate it, check if outside of range
			{
				cin.clear();     // Clear the error flags
				cin.ignore(100, '\n');    // Remove unwanted characters from buffer
				cout << "\aEnter an integer between 1 and 8: ";   // Re-issue the prompt
			}
		cout << "You entered: " << number_to_fac << "!" << endl;

		result = factorial(number_to_fac);
		cout << number_to_fac << "! = " << result << endl;
		break;
	case '2':
		cout << "Triangle output program.\n"
			 << "How many triangles do you want to draw? ";	
		while (!(cin >> triangles_number)) // Get the input and validate it
		{
			cin.clear();     // Clear the error flags
			cin.ignore(100, '\n');    // Remove unwanted characters from buffer
			cout << "\aEnter a valid number of triangles: ";   // Re-issue the prompt
		}
		cout << "How many stars on the last line? (5 - 21) ";
		while ((!(cin >> triangles_stars)) || (triangles_stars < 5) || (triangles_stars > 21)) // Get the input and validate it
		{
			cin.clear();     // Clear the error flags
			cin.ignore(100, '\n');    // Remove unwanted characters from buffer
			cout << "\aEnter a valid number of stars: ";   // Re-issue the prompt
		}
		triangle(triangles_number,triangles_stars);
		break;
	default:
		break;
	}
	return 0;
}

int factorial (int number_to_fac)
{
	int factorial_i(0);
	factorial_i = number_to_fac; // number_to_fac to keep the for loop at the initial count value
	for (int i = 1; i < factorial_i; i++)
	{
		number_to_fac *= i;
	}
	return number_to_fac;
}

void triangle (int triangle_number, int triangle_stars)
{
	string asterisk("*");
	
	for (int i = 1; i <= triangle_number; i++) // first loop for number of triangles
	{
		for (int j = 1; j <= triangle_stars; j++) // inner loop to draw them
		{
			cout << string(j, '*') << endl;     // star output
		}
		if (i < triangle_number) // checks if there if this is the final iteration of the first loop, thus will the program ask for another input
		{
			cout << "How many stars for the next triangle? (5 - 21) ";
			while ((!(cin >> triangle_stars)) || (triangle_stars < 5) || (triangle_stars > 21)) // Get the input and validate it
			{
				cin.clear();     // Clear the error flags
				cin.ignore(100, '\n');    // Remove unwanted characters from buffer
				cout << "\aEnter a valid number of stars: ";   // Re-issue the prompt
			}
		}
	}
}
