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

        virtual void attack()
        {
            cout << name << " attacks with " << weaponType << "!" << endl;
        }

        virtual void defend()
        {
            cout << name << " defends!" << endl;
        }

        virtual void displayStats()
        {
            cout << "Character ID: " << characterID << endl;
            cout << "Name: " << name << endl;
            cout << "Level: " << level << endl;
            cout << "Health Points: " << healthPoints << endl;
            cout << "Weapon Type: " << weaponType << endl;
        }

    virtual ~Character() {}
};

class Warrior : public Character
{
    protected:
        int armorStrength;
        int meleeDamage;

    public:
        Warrior(string id, string n, int lvl, int hp, string wT, int armor, int dmg): Character(id, n, lvl, hp, wT), armorStrength(armor), meleeDamage(dmg) {}

        void attack() override
        {
            cout << name << " performs a powerful melee attack! Damage: " << meleeDamage << endl;
        }

        void displayStats() override
        {
            Character::displayStats();
            cout << "Armor Strength: " << armorStrength << endl;
            cout << "Melee Damage: " << meleeDamage << endl << endl;
        }
};

class Mage : public Character
{
    protected:
        int manaPoints;
        int spellPower;

    public:
        Mage(string id, string n, int lvl, int hp, string wT, int mana, int sp): Character(id, n, lvl, hp, wT), manaPoints(mana), spellPower(sp) {}

        void defend() override
        {
            cout << name << " casts a magical shield! Spell power: " << spellPower << endl;
        }

        void displayStats() override
        {
            Character::displayStats();
            cout << "Mana Points: " << manaPoints << endl;
            cout << "Spell Power: " << spellPower << endl << endl;
        }
};

class Archer : public Character
{
    protected:
        int arrowCount;
        double rangedAccuracy;

    public:
        Archer(string id, string n, int lvl, int hp, string wT, int arrows, double accuracy): Character(id, n, lvl, hp, wT), arrowCount(arrows), rangedAccuracy(accuracy) {}

        void attack() override
        {
            cout << name << " fires an arrow! Arrows left: " << --arrowCount << ", Accuracy: " << rangedAccuracy << "%" << endl;
        }

        void displayStats() override
        {
            Character::displayStats();
            cout << "Arrow Count: " << arrowCount << endl;
            cout << "Ranged Accuracy: " << rangedAccuracy << "%" << endl << endl;
        }
};

class Rogue : public Character
{
    protected:
        int stealthLevel;
        int agility;

    public:
        Rogue(string id, string n, int lvl, int hp, string wT, int stealth, int agi): Character(id, n, lvl, hp, wT), stealthLevel(stealth), agility(agi) {}

        void displayStats() override
        {
            Character::displayStats();
            cout << "Stealth Level: " << stealthLevel << endl;
            cout << "Agility: " << agility << endl << endl;
        }
};

int main()
{
    Character* c1 = new Warrior("C001", "Thorn", 10, 120, "Axe", 80, 50);
    Character* c2 = new Mage("C002", "Elara", 12, 100, "Staff", 200, 60);
    Character* c3 = new Archer("C003", "Lyn", 8, 90, "Bow", 15, 85.5);
    Character* c4 = new Rogue("C004", "Shade", 11, 95, "Daggers", 95, 88);

    c1->attack();
    c1->displayStats();

    c2->defend();
    c2->displayStats();

    c3->attack();
    c3->displayStats();

    c4->displayStats();

    delete c1;
    delete c2;
    delete c3;
    delete c4;

    return 0;
}
