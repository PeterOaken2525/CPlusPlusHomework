#include<iostream>
#include<vector>
#include"Building.h"

using namespace std;

int main() 
{
	int inputInitialCost;
	int inputMaxAge;
	int inputToAge;
	vector<Building*> buildings;

	while (true) 
	{
		cout << "Enter initial cost of builiding you want to build:" << endl;
		cin >> inputInitialCost;

		cout << "Enter max age of builiding you want to build:" << endl;
		cin >> inputMaxAge;

		buildings.push_back(new Building(inputMaxAge, inputInitialCost));

		cout << "Enter how many years past from previous building construction:" << endl;
		cin >> inputToAge;

		for (Building* building : buildings)
		{
			building->ToAge(inputToAge);
			if (building->GetCost() > 0)
			{
				cout << "Building with id: " << building->BuildingID << " now costs about: " << building->GetCost() << "$" << endl;
			}
		}
	}

	return 0;
}