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

	//�������� ����
	cout << "Enter character name: ";
	cin >> characterName;

	//�������� ������'�
	cout << "Enter character health: ";
	cin >> characterHealth;
	float const characterMaxHealth = characterHealth;

	//���� �����
	cout << "1 - Warrior" << endl;
	cout << "2 - Mage" << endl;
	cout << "Enter character class ID: ";
	cin >> classID;
	if (classID != 1 && classID != 2)
	{
		cout << "Wrong class ID" << endl;
	}

	//�������� ���������
	cout << "Enter character power: ";
	cin >> power;
	
	//���� ������� > 0 ������������� �����. ���� ���� ��������� ����� ������'� <= 0 �� �������� ����� � �������� ���������
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