// Wilson Lopez
// Created on October 31, 2021
// Updated on December 8, 2023

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool DFA(string x)
{
	const size_t input_size = x.size();
	char state = 'S';

	for (int i = 0; i < input_size; i++)
	{
		if (state == 'S')	// Start State.
		{
			switch (x[i])
			{
			case 'A': state = '1';
				break;

			default: state = '3';
				break;
			}
		}
		if (state == '1')	// State 1
		{
			switch (x[i])
			{
			case 'A': state = '1';
				break;

			case 'T':
				if (x[i] == x.back())
					state = '2';
				else
					state = '1';
				break;

			case 'G': state = '1';
				break;

			case 'C': state = '1';
				break;

			default: state = '3';
				break;
			}
		}
		if (state == '2')	// Final State.
			return true;

		if (state == '3')	// Dead State.
			return false;
	}

}

int main()
{
	string user_input, RE, A, temp;
	vector<string> matches;

	A = "{A, T, G, C}";				// The Alphabet for generating DNA sequences.
	RE = "A (A + T + G + C)* T";	// The Regular Expression.

	cout << "The alphabet A is " << A;
	cout << " and the regular expression is " << RE << ".\n";

	cout << "Enter a DNA sequence: ";
	cin >> user_input;
	
	const size_t length = user_input.size();

	// For each character inside the user_input string:
	for (int c = 0; c < (length - 1); c++)
	{
		if (user_input[c] == 'A')
		{
			temp = user_input[c]; // Initialize temporary match variable with 'A'.

			// Continue iterating through the user_input string, after finding 'A'.
			for (int k = c + 1; k < (length - 1); k++)
			{
				temp += user_input[k]; // Add characters after 'A' inside the temporary match variable.

				// Once positioned at 'T', check if temp is a pattern that matches the regular expression.
				if (user_input[k] == 'T')
				{
					if (DFA(temp))
					{
						matches.push_back(temp);
						continue;
					}

				}
			}
		}
	}

	cout << endl << "The matching patterns are: " << endl;
	for (int i = 0; i < matches.size(); i++)
	{
		if (matches.empty())
			cout << "There was no matches.";
		else
			cout << matches[i] << endl;
	}

	return 0;
}