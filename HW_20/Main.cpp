#include<iostream>
#include<vector>

using namespace std;

class IDamageble
{
public:
    virtual void ApplyDamage(float Damage) = 0;
    virtual ~IDamageble() {};
};

class IHealthReciever
{
public:
    virtual void RecieveNewHealth(float Health) = 0;
};

class IHealthSender
{
public: 
    virtual void Subscribe(IHealthReciever*) = 0;
    virtual void Unsubscribe(IHealthReciever*) = 0;

};

class MyHero : public IHealthSender, public IDamageble
{
public: 
    MyHero(float Health)
    {
        m_Health = Health;
    }

    virtual void ApplyDamage(float Damage)
    {
        m_Health -= Damage;
        cout << Damage << " damage was applied" << endl;
        for (IHealthReciever* Reciever : Subs)
        {
            if (Reciever)
            {
                Reciever->RecieveNewHealth(m_Health);
            }
        }
    }

    virtual void Subscribe(IHealthReciever* sub) override
    {
        Subs.push_back(sub);
    }

    virtual void Unsubscribe(IHealthReciever* sub) override
    {
        Subs.erase(std::find(Subs.begin(), Subs.end(), sub));
    }

private:
    float m_Health;
    vector<IHealthReciever*> Subs;

};

class HealthBar : public IHealthReciever
{
public:
    virtual void RecieveNewHealth(float Health) override
    {
        cout << "Health Bar :" << Health << endl;
    }
};

class WorldHealthBar : public IHealthReciever
{
public:
    virtual void RecieveNewHealth(float Health) override
    {
        cout << "World Health Bar :" << Health << endl;
    }
};


int main() 
{
    MyHero arnold(150);
    HealthBar healthBar;
    WorldHealthBar worldHealthBar;
    
    arnold.Subscribe(&healthBar);
    arnold.Subscribe(&worldHealthBar);

    arnold.ApplyDamage(5);
    arnold.ApplyDamage(3);

    arnold.Unsubscribe(&healthBar);

    arnold.ApplyDamage(10);

    arnold.Unsubscribe(&worldHealthBar);

    arnold.ApplyDamage(2);

    return 0;
}
