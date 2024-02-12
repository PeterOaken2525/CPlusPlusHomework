#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;


struct PlayerInfo
{
    string playerName;
    float playerPower;
};

map<string, vector<PlayerInfo>> clanMap;

 void addPlayerToClan(const string& clanName, const string& playerName, float playerPower)
{
    PlayerInfo player = { playerName, playerPower };
    clanMap[clanName].push_back(player);
}

int getPlayerCount(const string& clanName)
{
   if (clanMap.find(clanName) != clanMap.end())
   {
        return clanMap.at(clanName).size();
   }
    return 0;
}

int clanFight(const string& firstClanName, const string& secondClanName)
{
    float firstClanPower = 0;
    float secondClanPower = 0;

    if (clanMap.find(firstClanName) != clanMap.end())
    {
        for (const auto& player : clanMap.at(firstClanName))
        {
            firstClanPower += player.playerPower;
        }
    }

    if (clanMap.find(secondClanName) != clanMap.end())
    {
        for (const auto& player : clanMap.at(secondClanName))
        {
            secondClanPower += player.playerPower;
        }
    }

    if (firstClanPower == secondClanPower)
    {
        return 0;
    }
    else if (firstClanPower > secondClanPower)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int maxPlayers;
    cout << "Enter number of max players in game: ";
    cin >> maxPlayers;

    for (int i = 0; i < maxPlayers; ++i)
    {
        string clanName, playerName;
        float playerPower;
        cout << "Enter Clan Name " << endl;
        cin >> clanName;
        cout << "Enter Player Name " << endl;
        cin >> playerName;
        cout << "Enter Player Power " << endl;
        cin >> playerPower;
        addPlayerToClan(clanName, playerName, playerPower);
    }

    string firstClan;
    string secondClan;
    cout << "Enter first clan name to start clan war: " << endl;
    cin >> firstClan;
    cout << "Enter second clan name to start clan war: " << endl;
    cin >> secondClan;

    int playerCountFirstClan = getPlayerCount(firstClan);
    int playerCountSecondClan = getPlayerCount(secondClan);

    cout << "There are " << playerCountFirstClan << "players in " << firstClan << " clan." << endl;
    cout << "There are " << playerCountSecondClan << "players in " << secondClan << " clan." << endl;

    int result = clanFight(firstClan, secondClan);
    if (result == 0) {
        cout << "The match ended in a draw." << endl;
    }
    else if (result == 1) {
        cout << "Win " << firstClan << "." << endl;
    }
    else {
        cout << "Win " << secondClan << "." << endl;
    }

    return 0;
}