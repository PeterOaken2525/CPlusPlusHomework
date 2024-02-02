#include<iostream>
#include <vector>
#include <string>
#include"functions.h"

using namespace std;


int main()
{
	vector<float> damages;
	damages.push_back(0);
	string input;
	
	cout << "Enter number of damage or number with - to heal "<< endl;
	cout << "For stat press enter" << endl;
	
	while (true) 
	{
		
		getline(cin, input);
		
		if (input.empty()) {
			break;
		}
		else {
			try {
				float num = stof(input);
				damages.push_back(num);
			}
			catch (invalid_argument const& ex) {

				cout << "You can enter only numbers. Try again." << endl;
			}
		}
	}

	GetHighestDamage(damages);
	GetLowestDamage(damages);
	GetHeal(damages);
	GetTotalDamageOrHeal(damages, true);
	GetTotalDamageOrHeal(damages, false);
	IsThereAZeroDamage(damages);

	return 0;
}

