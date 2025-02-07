#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cout << "Enter the number of strings: ";
    cin >> n;

    string *strings = new string[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        cin >> strings[i];
    }

    string temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(strings[j][0] > strings[j + 1][0])    
            {
                temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << strings[i] << endl;
    }

    delete[] strings;

    return 0;
}
