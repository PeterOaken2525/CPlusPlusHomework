#include "Building.h"

int Building::NextBuildingID = 0;

Building::Building(int _MaxAge, int _InitialCost)
	: MaxAge{ _MaxAge }, InitialCost{ _InitialCost }
{
	BuildingID = NextBuildingID;
	++NextBuildingID;
}

int Building::GetCost()
{
	CurrentCost = (InitialCost - ((InitialCost/MaxAge)*CurrentAge));
	if (CurrentCost < 0)
	{
		CurrentCost = 0;
	}
	return CurrentCost;
}

void Building::ToAge(int years)
{	
	CurrentAge = CurrentAge + years;
	if (CurrentAge > MaxAge) 
	{
		Building::Destroy();
	}
}