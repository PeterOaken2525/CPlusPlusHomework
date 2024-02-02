#pragma once


float GetHighestDamage(const std::vector<float>& damages)
{
    float highestDamage = damages[1];
    int index;

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] > 0 && damages[i] > highestDamage)
        {
            highestDamage = damages[i];
        }
        
    }

    std::cout << "Highest damage is: " << highestDamage << " under index: ";

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] == highestDamage)
        {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

float GetLowestDamage(const std::vector<float>& damages)
{

    float lowestDamage = damages[1];

    for (size_t i = 1; i < damages.size(); ++i)
    {

        if (damages[i] > 0)
        {
            lowestDamage = damages[i];
            break;
        }
    }
    for (size_t i = 1; i < damages.size(); ++i)
    {

        if (damages[i] > 0 && damages[i] < lowestDamage)
        {
            lowestDamage = damages[i];
        }
    }
    std::cout << "Lowest damage is: " << lowestDamage << " under index: ";

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] == lowestDamage)
        {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

float GetHeal(const std::vector<float>& damages)
{
    float heal = damages[0];

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] < 0 && damages[i] < heal)
        {
            heal = damages[i];
        }
    }

    std::cout << "Heals is: "; 

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] < 0)
        {
            std::cout << damages[i] << ", ";
        }
    }

    std::cout << " under index: ";

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] < 0)
        {
            std::cout << i << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

float GetTotalDamageOrHeal(const std::vector<float>& damages, bool damageOrHeal)
{
    float sum = damages[0];

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] > 0 && damageOrHeal==true)
        {
            sum = sum + damages[i];
        }
        if (damages[i] < 0 && damageOrHeal == false)
        {
            sum = sum + damages[i];
        }
    }

    if (damageOrHeal == true)
    {
        std::cout << "Total damage is: " << sum << std::endl;
    }
    else
    {
        std::cout << "Total heal is: " << -sum << std::endl;
    }

    return 0;
}

float IsThereAZeroDamage(const std::vector<float>& damages)
{
    bool zeroDamage = false;

    for (size_t i = 1; i < damages.size(); ++i)
    {
        if (damages[i] == 0)
        {
            zeroDamage = true;
        }
    }

    if (zeroDamage == true)
    {
        std::cout << "There is a zero damage" << std::endl;
    }
    else
    {
        std::cout << "There is NO zero damage" << std::endl;
    }

    return 0;
}