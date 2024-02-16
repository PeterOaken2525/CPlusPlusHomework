#include<iostream>
#include<string>

using namespace std;

class Weapon
{
public:
	virtual float GetDamage() = 0;
	virtual string GetName() = 0;
};

class DamageModifier {
public:
	virtual float CalculateDamage(float currentHealth, float damage) = 0;
};

class Character
{
protected:
	Weapon* weapon;
	DamageModifier* damageModifier;
	float maxHealth;
	float currentHealth;

public:

	Character(const string& name, float maxHealth) : currentHealth(maxHealth), maxHealth(maxHealth), weapon(nullptr), damageModifier(nullptr) {
		cout << "Character " << name << " created with max health " << maxHealth << endl;
	}

	void SetWeapon(Weapon* newWeapon)
	{
		weapon = newWeapon;
	}

	Weapon* GetWeapon() const 
	{
		return weapon;
	}

	void SetDamageModifier(DamageModifier* newDamageModifier) 
	{
		damageModifier = newDamageModifier;
	}

	float GetModifiedDamage() const 
	{
		if (weapon && damageModifier)
			return damageModifier->CalculateDamage(0, weapon->GetDamage());
		else if (weapon)
			return weapon->GetDamage();
		else
			return 0.0f;
	}

	float ApplyDamageAndReturnHealth(float damage) 
	{
		currentHealth = currentHealth - damage;
		if(currentHealth<0)
		{
			currentHealth = 0;
		}
		return currentHealth;
	}

};

//вепони
class Machinegun :  public  Weapon
{
public:
	virtual float GetDamage() override
	{
		return 3.0f;
	}
	virtual string GetName() override
	{
		return "Machinegun";
	}
};

class Laser : public  Weapon
{
public:
	virtual float GetDamage() override
	{
		return 1.5f;
	}
	virtual string GetName() override
	{
		return "Laser";
	}
};

class RocketLauncher : public  Weapon
{
public:
	virtual float GetDamage() override
	{
		return 12.0f;
	}
	virtual string GetName() override
	{
		return "Rocketlauncher";
	}
};


//множники шкоди
class MultiplicationDamageModifier : public DamageModifier {
private:
	float multiplicator;

public:
	MultiplicationDamageModifier(float multiplicator) : multiplicator(multiplicator) {}

	virtual float CalculateDamage(float currentHealth, float damage) override 
	{
		return damage * multiplicator;
	}
};

class AdditionDamageModifier : public DamageModifier {
private:
	float addition;

public:
	AdditionDamageModifier(float addition) : addition(addition) {}

	virtual float CalculateDamage(float currentHealth, float damage) override 
	{
		float modifiedDamage = damage + addition;
		return (modifiedDamage > 0) ? modifiedDamage : 0;
	}
};

class ParityDamageModifier : public DamageModifier {
private:
	float multiplicator;

public:
	ParityDamageModifier(float multiplicator) : multiplicator(multiplicator) {}

	virtual float CalculateDamage(float currentHealth, float damage) override 
	{
		if (currentHealth > 0 && ((int)currentHealth % 2 == 0))
			return damage * multiplicator;
		else
			return damage;
	}
};


int main() 
{
	while (true) {
		string name;
		float maxHealth;
		cout << "Enter character name: ";
		cin >> name;
		cout << "Enter max health: ";
		cin >> maxHealth;

		Character hero(name, maxHealth);

		// Додавання зброї
		Machinegun _machinegun;
		Laser _laser;
		RocketLauncher _rocketLauncher;

		int choice1;
		cout << "Choose weapon (1 - Machinegun, 2 - Laser, 3 - Rocket Launcher): ";
		cin >> choice1;
		switch (choice1) {
		case 1:
			
			hero.SetWeapon(&_machinegun);
			break;
		case 2:
			hero.SetWeapon(&_laser);
			break;
		case 3:
			hero.SetWeapon(&_rocketLauncher);
			break;
		} 

		// Модифікація шкоди
		float damageModification;
		cout << "Enter damage modification amount: ";
		cin >> damageModification;

		MultiplicationDamageModifier modifier1(damageModification);
		AdditionDamageModifier modifier2(damageModification);
		ParityDamageModifier modifier3(damageModification);

		int choice2;
		cout << "Choose damage modifier (1 - Multiplication, 2 - Addition, 3 - Parity): ";
		cin >> choice2;
		switch (choice2) {
		case 1:
			hero.SetDamageModifier(&modifier1);
			break;
		case 2:
			hero.SetDamageModifier(&modifier2);
			break;
		case 3:
			hero.SetDamageModifier(&modifier3);
			break;
		}

		cout << "Modified Damage: " << hero.GetModifiedDamage() << endl;
		cout << "Health left: " << hero.ApplyDamageAndReturnHealth(hero.GetModifiedDamage()) << endl;
	}

	return 0;
}