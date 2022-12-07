#include<bits/stdc++.h>
using namespace std ;

string encrypt(string pt , string key)
{
    string ct = ""; // ciphertext
    int k = 0;      // plaintext iterator

    int num_row = ceil((float) pt.length()/key.length());
    int num_col = key.length();
    char mat[num_row][num_col];
    
    cout << "\nEncryption Matrix :" << endl;
    cout << "---------------------" << endl;
    for(int i=0; i<num_row ; i++)
    {
        for(int j=0; j<num_col; j++)
        {
            if(k < pt.length())
            {
                cout << (mat[i][j] = pt[k++]) << "  ";
            }
            else
            {
                cout << (mat[i][j] = 'x') << "  " ;
            }
        }
        cout << endl;
    }
    for(int i=0; i<num_col; i++)
    {
        for(int j=0; j<num_row; j++)
        {
            ct += mat[j][key.find(i+'1')];
        }
    }
    return ct;
}

string decrypt(string ct , string key)
{
    string pt = ""; // plaintext
    int k = 0; // ciptext iterator

    int num_row = ceil((float)ct.length() / key.length());
    int num_col = key.length();
    char mat[num_row][num_col];

    for(int i=0; i<num_col; i++)
    {
        for(int j=0; j<num_row; j++)
        {
             mat[j][key.find(i+'1')] = ct[k++];
        }
    }

    cout << "\nDecryption Matrix :" << endl;
    cout << "---------------------" << endl;
    for(int i=0; i<num_row ; i++)
    {
        for(int j=0; j<num_col; j++)
        {
            cout << mat[i][j] << "  ";
            pt += mat[i][j];
        }
        cout << endl;
    }
    return pt;
}

int main()
{
    string plaintext , key , ciphertext , decryptext;

    cout << "Enter text : ";
    cin >> plaintext;

    cout << "Enter key  : ";
    cin >> key;

    ciphertext = encrypt(plaintext , key);
    cout << "\nEncrypted text \t: " << ciphertext << endl;

    decryptext = decrypt(ciphertext , key);
    cout << "\nDecrypted text \t: " << decryptext << endl;
}

/*#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

string toUpper (string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (c == ' ')
            continue;
        if (c >= 'a' and c <= 'z')
            ans += c - 32;
        else
            ans += c;
    }
    return ans;
}

int main()
{
    string plainText = "";
    cout << "Enter plain text : ";
    cin >> plainText;

    string next;
    getline (cin, next);

    plainText += next;

    plainText = toUpper (plainText);

    // cout << plainText;

    string key;
    cout << "Enter key : (should strictly contain the sequence of columns only) : ";
    cin >> key;

    vector <vector <char> > mat (ceil (float (plainText.size())/key.size()), vector <char> (key.size(), 'X'));


    int n = key.size(), m = mat.size();

    for (int i = 0; i < plainText.size(); i++)
        mat[i/n][i%n] = plainText[i];

    vector <string> ct (key.size(), "");
    // cout << ct.size();

    string cipherText = "";

    for (int i = 0; i < key.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < m; j++)
            temp += mat[j][i];
        // cout << temp << " ";
        ct[key[i]-48-1] = temp;
        // cout << ct[key[i]  -48- 1];
    }

    for (int i = 0; i < ct.size(); i++)
        cipherText += ct[i];

    cout << "Cipher Text : " << cipherText;
}*/
