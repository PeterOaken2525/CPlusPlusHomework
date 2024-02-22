#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Weapon 
{
public:
    virtual float GetDamage() = 0;
    virtual string GetName() = 0;
};

class DamageModifier 
{
public:
    virtual float CalculateDamage(float currentHealth, float damage) = 0;
};

class Character 
{
protected:
    shared_ptr<Weapon> weapon;
    shared_ptr<DamageModifier> damageModifier;
    float maxHealth;
    float currentHealth;

public:
    Character(const string& name, float maxHealth) : currentHealth(maxHealth), maxHealth(maxHealth), weapon(nullptr), damageModifier(nullptr) 
    {
        cout << "Character " << name << " created with max health " << maxHealth << endl;
    }

    void SetWeapon(shared_ptr<Weapon> newWeapon)
    {
        weapon = newWeapon;
    }

    shared_ptr<Weapon> GetWeapon() const 
    {
        return weapon;
    }

    void SetDamageModifier(shared_ptr<DamageModifier> newDamageModifier)
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

    float ApplyDamageAndReturnHealth(float damage) {
        currentHealth -= damage;
        if (currentHealth < 0) {
            currentHealth = 0;
        }
        return currentHealth;
    }
};

class Machinegun : public Weapon 
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

class Laser : public Weapon 
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

class RocketLauncher : public Weapon 
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

class MultiplicationDamageModifier : public DamageModifier 
{
private:
    float multiplicator;

public:
    MultiplicationDamageModifier(float multiplicator) : multiplicator(multiplicator) {}

    virtual float CalculateDamage(float currentHealth, float damage) override 
    {
        return damage * multiplicator;
    }
};

class AdditionDamageModifier : public DamageModifier 
{
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

class ParityDamageModifier : public DamageModifier 
{
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
    while (true) 
    {
        string name;
        float maxHealth;
        cout << "Enter character name: ";
        cin >> name;
        cout << "Enter max health: ";
        cin >> maxHealth;

        Character hero(name, maxHealth);

        shared_ptr<Weapon> weapon;
        int choice1;
        cout << "Choose weapon (1 - Machinegun, 2 - Laser, 3 - Rocket Launcher): ";
        cin >> choice1;
        switch (choice1) 
        {
        case 1:
            weapon = make_shared<Machinegun>();
            break;
        case 2:
            weapon = make_shared<Laser>();
            break;
        case 3:
            weapon = make_shared<RocketLauncher>();
            break;
        }
        hero.SetWeapon(weapon);

        float damageModification;
        cout << "Enter damage modification amount: ";
        cin >> damageModification;

        shared_ptr<DamageModifier> modifier;
        int choice2;
        cout << "Choose damage modifier (1 - Multiplication, 2 - Addition, 3 - Parity): ";
        cin >> choice2;
        switch (choice2) 
        {
        case 1:
            modifier = make_shared<MultiplicationDamageModifier>(damageModification);
            break;
        case 2:
            modifier = make_shared<AdditionDamageModifier>(damageModification);
            break;
        case 3:
            modifier = make_shared<ParityDamageModifier>(damageModification);
            break;
        }
        hero.SetDamageModifier(modifier);

        cout << "Modified Damage: " << hero.GetModifiedDamage() << endl;
        cout << "Health left: " << hero.ApplyDamageAndReturnHealth(hero.GetModifiedDamage()) << endl;
 
    }

    return 0;
}
