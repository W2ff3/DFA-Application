// October 31, 2021
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool DFA(string x)
{
	int input_size = x.size();
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
			case 'A': 
				if (x[i + 1] == 'T')
					state = '1';
				else
					state = '3';
				break;
			case 'T':
				if (x[i] == x[input_size - 1])
					state = '2';
				else
					state = '1';
				break;
			case 'G':
				if (x[i + 1] == 'T')
					state = '1';
				else
					state = '3';
				break;
			case 'C':
				if (x[i + 1] == 'T')
					state = '1';
				else
					state = '3';
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
	bool tchange = false;
	string user_input, RE, A;
	string valid, temp, temp2;
	vector<string> matches;

	RE = "A (A + T + G + C)* T";	// The Regular Expression.
	A = "{A, T, G, C}";				// The Alphabet for generating DNA sequences.

	cout << "The alphabet A is " << A;
	cout << " and the regular expression is " << RE << ".\n";

	cout << "Enter a DNA sequence: ";
	cin >> user_input;
	
	int length = user_input.size();

	for (int c = 0; c < (length - 1); c++)
	{
		for (int k = c + 1; k < (length - 1); k++)
		{
			if (user_input[c] == 'A')
			{
				if (user_input[k] == 'T')
				{
					if (tchange == false)
						temp = user_input[c];
					else
						temp = valid;

					valid = temp + user_input[k];
					if (DFA(valid) == true)
					{
						matches.push_back(valid);
						tchange = true;
					}
				}
				else if (user_input[k] == 'A' || user_input[k] == 'G' || user_input[k] == 'C')
				{
					if (tchange == false)
						temp = user_input[c];
					else
						temp = valid;
					valid = temp + user_input[k];
				}
			}
		}

		// valid = temp + user_input[c + 1];
		//if (DFA(valid) == true)
		//{
		//	matches.push_back(valid);
		//	tchange = true;
		//}
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