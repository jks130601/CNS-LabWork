//Cryptanalysis of caesar cipher
#include <iostream>
using namespace std;
 
int main()
{
    string cipher;
    cout << "Enter cipher text STRICTLY IN CAPITAL LETTERS AND WITHOUT SPACES: ";
    cin >> cipher;
 
    string temps;
 
    for (int key = 0; key < 26; key++)
    {
        temps = cipher;
        int temp;
        for (int i = 0; i < temps.size(); i++)
        {
            temp = (temps[i] - key - 65) % 26;
            if (temp < 0)
                temp = 26 + temp;
            temps[i] = temp + 97;
        }
 
        cout << key << " : " << temps << endl;
    }
}

