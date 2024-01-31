#include<iostream>
#include"functions.h"

using namespace std;


int main()
{
	string characterName;
	float characterHealth;
	int classID;
	float damage;
	float power;

	//введенн€ ≥мен≥
	cout << "Enter character name: ";
	cin >> characterName;

	//введенн€ здоров'€
	cout << "Enter character health: ";
	cin >> characterHealth;
	float const characterMaxHealth = characterHealth;

	//виб≥р класу
	cout << "1 - Warrior" << endl;
	cout << "2 - Mage" << endl;
	cout << "Enter character class ID: ";
	cin >> classID;
	if (classID != 1 && classID != 2)
	{
		cout << "Wrong class ID" << endl;
	}

	//введенн€ потужност≥
	cout << "Enter character power: ";
	cin >> power;
	
	//€кщо здоров€ > 0 застосовуЇтьс€ шкода. якщо п≥сл€ отриманн€ шкоди здоров'€ <= 0 то персонаж помер ≥ програма завершена
	while (characterHealth > 0)
	{
		cout << "Enter damage : ";
		cin >> damage;
		characterHealth = calculateDamage(characterHealth, characterMaxHealth, classID, damage, power);
		if (characterHealth <= 0)
		{
			characterHealth = 0;
			cout << "Character health is: 0" << endl;
			cout << "Character died X_X" << endl;
			break;
		}
		cout << "Character health is: " << characterHealth << endl;
	}
	
	return 0;
} 