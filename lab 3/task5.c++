#include <iostream>
using namespace std;

class MusicPlayer
{
    int listNum = 0;
    string *playlist = nullptr;
    string currentlyPlayingSong;

    public:
        void addSongs(string song)
        {
            string *newPlaylist = new string[listNum + 1];
            for (int i = 0; i < listNum; i++)
            {newPlaylist[i] = playlist[i];}

            newPlaylist[listNum] = song;

            delete[] playlist;

            playlist = newPlaylist;
            listNum++;
        }

        void removeSongs(string song)
        {
            bool found = false;
            
            for (int i = 0; i < listNum; i++)
            {
                if (playlist[i] == song)
                {
                    string *newPlaylist = new string[listNum - 1];

                    for (int j = 0, k = 0; j < listNum; j++)
                    {
                        if (j != i)
                        {
                            newPlaylist[k] = playlist[j];
                            k++;
                        }
                    }

                    delete[] playlist;
                    playlist = newPlaylist;
                    listNum--;

                    found = true;
                    cout << "Song removed: " << song << endl;
                    break;
                }
            }

            if (!found)
            {
                cout << "Song not found in the playlist!" << endl;
            }
        }


        void playSong(string song)
        {
            for (int i = 0; i < listNum; i++)
            {
                if (playlist[i] == song)
                currentlyPlayingSong = song;
                {cout << "Song playing: " << song << endl << endl; return;}
            }

            cout << "The song is not in the playlist!" << endl;
        }

        void displayPlaylist()
        {
            cout << "Playlist:" << endl;
            for(int i = 0; i < listNum; i++)
            {cout << playlist[i] << endl;}

            cout << endl;
        }

        void memoryDeallocation()
        {
            delete[] playlist;
        }
};

int main()
{
    MusicPlayer mp;

    mp.addSongs("Creep");
    mp.addSongs("Shape of You");
    mp.addSongs("Stay");
    mp.addSongs("Levitating");
    mp.addSongs("On My Way");
    mp.displayPlaylist();
    
    mp.addSongs("Wake Me Up");
    mp.displayPlaylist();

    mp.removeSongs("Creep");
    mp.displayPlaylist();

    mp.playSong("Wake Me Up");
    mp.displayPlaylist();

    mp.memoryDeallocation();
    return 0;
}