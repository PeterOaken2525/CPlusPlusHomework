#pragma once

//перевірка чи парне число чи ні
bool isNumEven(float inputNum)
{
	int num = round(inputNum);
	bool numIsEven;

	if (num % 2 == 0)
	{
		numIsEven = true;
	}
	else
	{
		numIsEven = false;
	}
	return numIsEven;
}

//перевірка чи здоров'я персонажа менше 30% від максимального здоров'я
bool isHealthLessThan30(float characterHealth, float characterMaxHealth)
{
	float treshold = (characterMaxHealth / 100) * 30;
	return characterHealth < treshold;
}

//надає випадкове значення 0 або 1
int getRandomBool()
{
	srand((unsigned)time(NULL));

	int random = rand() % 2;
	return random;
}

//розрахунок шкоди залежно від здоров'я, класу, шкоди і потужності.
float calculateDamage(float characterHealth, float characterMaxHealth, int classID, float damage, float power)
{
	bool damageParity = isNumEven(damage);

	if (classID == 1) //Warrior Case
	{
		bool berserk = isHealthLessThan30(characterHealth, characterMaxHealth);
		if (damageParity == false && berserk != true)
		{
			characterHealth = characterHealth - (damage * 3);
		}
		if (damageParity == false && berserk == true)
		{
			float damageBlocked = ((damage * 3) - power);
			if (damageBlocked < 0)
			{
				damageBlocked = 0;
			}
			characterHealth = characterHealth - damageBlocked;
			std::cout << "Berserk - when health less than 30% some damage blocked by power" << std::endl;
		}
	}
	if (classID == 2) //Mage Case
	{
		if (damage > (power * 2))
		{
			bool blockDamage = (getRandomBool() == 1);

			if (damageParity == true && blockDamage == false)
			{
				characterHealth = characterHealth - (damage * 2);
			}
			if (damageParity == false && blockDamage == false)
			{
				characterHealth = characterHealth - damage;
			}
			if (blockDamage == true)
			{
				std::cout << "Magic shield - 50% chance when damage 2x more than power" << std::endl;
			}
		}
		if (damageParity == true && damage <= (power * 2))
		{
			characterHealth = characterHealth - (damage * 2);
		}
		if (damageParity == false && damage <= (power * 2))
		{
			characterHealth = characterHealth - damage;
		}
	}
	return characterHealth;
}



