#include <iostream>
using namespace std;

class Character
{
    protected:
        string characterID;
        string name;
        int level;
        int healthPoints;
        string weaponType;
    
    public:
        Character(string id, string n, int lvl, int hp, string wT): characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(wT) {}

        void attack()
        {

        }

        void defend()
        {

        }

        void displayStats()
        {
            
        }
};

int main()
{


    return 0;
}