//Rail Fence Cipher
#include <bits/stdc++.h>
using namespace std;

// encryption
string encryptRailFence(string text, int key)
{
	// create the matrix to cipher plain text
	char rail[key][(text.length())];

	// filling the rail matrix to distinguish filled spaces from blank ones
	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	bool dir_down = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++)
	{
		// check the direction of flow
		if (row == 0 || row == key-1)
			dir_down = !dir_down;

		// fill the corresponding alphabet
		rail[row][col++] = text[i];

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);

	return result;
}

// decryption
string decryptRailFence(string cipher, int key)
{
	// create the matrix to cipher plain text
	char rail[key][cipher.length()];

	for (int i=0; i < key; i++)
		for (int j=0; j < cipher.length(); j++)
			rail[i][j] = '\n';

	// to find the direction
	bool dir_down;

	int row = 0, col = 0;

	// mark the places with '*'
	for (int i=0; i < cipher.length(); i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		rail[row][col++] = '*';

		// find the next row using direction flag
		dir_down?row++ : row--;
	}

	int index = 0;
	for (int i=0; i<key; i++)
		for (int j=0; j<cipher.length(); j++)
			if (rail[i][j] == '*' && index<cipher.length())
				rail[i][j] = cipher[index++];


	string result;

	row = 0, col = 0;
	for (int i=0; i< cipher.length(); i++)
	{
		// check the direction of flow
		if (row == 0)
			dir_down = true;
		if (row == key-1)
			dir_down = false;

		// place the marker
		if (rail[row][col] != '*')
			result.push_back(rail[row][col++]);

		// find the next row using direction flag
		dir_down?row++: row--;
	}
	return result;
}

int main()
{
    string plainText = "";
    string cipherText = "";
    int key;
    cout << "Enter plain text : ";
    cin >> plainText;
    cout << "Enter the depth : ";
    cin >> key;
	string cipher = encryptRailFence(plainText, key);
    transform(cipher.begin(), cipher.end(), cipher.begin(), ::toupper);
    cout << "Cipher text: " << cipher << endl;

    cout << "Cipher text : ";
    cin >> cipherText;
    int depth;
    cout << "Enter the depth : ";
    cin >> depth;
	cout << "Plain Text: " << decryptRailFence(cipherText, depth) << endl;

	return 0;
}

