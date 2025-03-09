#include <iostream>
using namespace std;

class Level
{
    string name;
    int difficulty;

    public:
        Level(string n, int d): name(n), difficulty(d) {}

        void display() const
        {
            cout << "Level name: " << name << endl;
            cout << "Level difficulty: " << difficulty << endl << endl;
        }

        ~Level(){}
};

class VideoGame
{
    string title;
    string genre;
    Level *levels[10];
    int levelsNum;

    public:
        VideoGame(string t, string g): title(t), genre(g), levelsNum(0) {}

        void addLevel(string name, int difficulty)
        {
            if (levelsNum < 10)
            {
                levels[levelsNum] = new Level(name, difficulty);
                levelsNum++;
            }
            else
            {
                cout << "Maximum levels achieved!" << endl;
            }
        }

        void display() const
        {
            cout << "Game title: " << title << endl;
            cout << "Game genre: " << genre << endl << endl;
            cout << "Levels and their details:\n";
            for (int i = 0; i < levelsNum; i++)
            {
                levels[i]->display();
            }
        }

        ~VideoGame(){}
};

int main()
{
    VideoGame game("Shadow Quest", "RPG");

    game.addLevel("Forest of Doom", 3);
    game.addLevel("Cave of Wonders", 5);
    game.addLevel("Castle of Shadows", 7);

    game.display();

    return 0;
}
