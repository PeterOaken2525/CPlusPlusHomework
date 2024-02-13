#pragma once
#include<iostream>

class Building
{
public:
	Building(int MaxAge, int InitialCost);
	~Building() = default;

	int GetCost();
	void ToAge(int years);

public:
	int BuildingID;
	int MaxAge;
	int InitialCost;

private:
	void Destroy() 
	{
		if (CurrentAge > MaxAge) 
		{
			std::cout << "Building with id: " << BuildingID << " was destroyed." << std::endl;
		}
	}

private:
	static int NextBuildingID;
	int CurrentAge = 0;
	int CurrentCost = InitialCost;
};	
