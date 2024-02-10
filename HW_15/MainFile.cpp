#include <iostream>
#include <vector>

using namespace std;

enum class CharacterClass 
{
	Warrior,
	Archer,
	Mage,

};

struct CharacterInfo
{
    int characterID = 0;
    CharacterClass characterClass;
    float meleeAttackPower;
    float rangedAttackPower;
};

CharacterInfo getStrongestCharacter(const vector<CharacterInfo>& characters) 
{
    CharacterInfo strongest = characters[0];
    float maxPower = strongest.meleeAttackPower + strongest.rangedAttackPower;
    for (const auto& character : characters) 
    {
        float power = character.meleeAttackPower + character.rangedAttackPower;
        if (power > maxPower) {
            maxPower = power;
            strongest = character;
        }
    }
    return strongest;
}

vector<CharacterInfo> getStrongestCharactersByClass(const vector<CharacterInfo>& characters) 
{
    vector<CharacterInfo> strongestCharacters(static_cast<int>(CharacterClass::Mage) + 1); 

    for (const auto& character : characters) {
        int index = static_cast<int>(character.characterClass);
        if (strongestCharacters[index].characterID == 0) 
        { 
            strongestCharacters[index] = character;
        }
        else 
        { 
            float currentPower = character.meleeAttackPower + character.rangedAttackPower;
            float strongestPower = strongestCharacters[index].meleeAttackPower + strongestCharacters[index].rangedAttackPower;
            if (currentPower > strongestPower) 
            {
                strongestCharacters[index] = character;
            }
        }
    }

    return strongestCharacters;
}

int main() 
{

    CharacterInfo character;
    vector<CharacterInfo> characters;
    int numCharacters;
    cout << "Enter the number of characters: ";
    cin >> numCharacters;

    for (int i = 0; i < numCharacters; ++i) 
    {
        CharacterInfo character;
        cout << "Enter data for character " << i + 1 << ":" << endl;
        character.characterID++;
        cout << "Character ID: ";
        cin >> character.characterID;
        cout << "Character Class (0 - Warrior, 1 - Archer, 2 - Mage): ";
        int classIndex;
        cin >> classIndex;
        while (classIndex > 2 || classIndex < 0) 
        {
            cout<<"Wrong class index. Please, retry." << endl;
            cin >> classIndex;
        }
        character.characterClass = static_cast<CharacterClass>(classIndex);
        cout << "Melee Attack Strength: ";
        cin >> character.meleeAttackPower;
        cout << "Ranged Attack Strength: ";
        cin >> character.rangedAttackPower;

        characters.push_back(character);
    }


    CharacterInfo strongestCharacter = getStrongestCharacter(characters);

    cout << "The strongest character is:" << endl;
    cout << "Character ID: " << strongestCharacter.characterID << endl;
    std::cout << "Character Class: ";
    switch (strongestCharacter.characterClass) {
    case CharacterClass::Warrior:
        std::cout << "Warrior" << endl;
        break;
    case CharacterClass::Archer:
        std::cout << "Archer" << endl;
        break;
    case CharacterClass::Mage:
        std::cout << "Mage" << endl;
        break;
    }
    cout << "Melee Attack Strength: " << strongestCharacter.meleeAttackPower << endl;
    cout << "Ranged Attack Strength: " << strongestCharacter.rangedAttackPower << endl;
    cout << endl;


    auto strongestCharacters = getStrongestCharactersByClass(characters);
    
    for (size_t i = 0; i < strongestCharacters.size(); ++i) {
        cout << "Strongest character in class ";
        switch (static_cast<CharacterClass>(i)) {
        case CharacterClass::Warrior:
            cout << "Warrior:" << endl;
            break;
        case CharacterClass::Archer:
            cout << "Archer:" << endl;
            break;
        case CharacterClass::Mage:
            cout << "Mage:" << endl;
            break;
            
        }
        cout << "  Character ID: " << strongestCharacters[i].characterID << endl;
        cout << "  Melee Attack Strength: " << strongestCharacters[i].meleeAttackPower << endl;
        cout << "  Ranged Attack Strength: " << strongestCharacters[i].rangedAttackPower << endl;
        cout << endl;
    }

    return 0;
}

