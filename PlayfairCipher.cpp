#include <bits/stdc++.h>
using namespace std;

typedef struct{
	int row;
	int col;
}position;

char mat[5][5]; 

void generateMatrix(string key)
{
    
    int flag[26] = {0};
    int x = 0, y = 0;

    for(int i=0; i<key.length(); i++)
    {
        if(key[i] == 'j') key[i] = 'i'; 

        if(flag[key[i]-'a'] == 0)
        {
            mat[x][y++] = key[i];
            flag[key[i]-'a'] = 1;
        }
        if(y==5) x++, y=0;
    }

    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        if(ch == 'j') continue; 
        
        if(flag[ch - 'a'] == 0)
        {
            mat[x][y++] = ch;
            flag[ch - 'a'] = 1 ;
        }
        if(y==5) x++, y=0;
    }
}


string formatMessage(string msg)
{
    for(int i=0; i<msg.length(); i++)
    {
        if(msg[i] == 'j')  msg[i] = 'i';
    }

    for(int i=1; i<msg.length(); i+=2) 
    {
        if(msg[i-1] == msg[i])  msg.insert(i, "x");
    }
    
    if(msg.length()%2 != 0)  msg += "x";
    return msg;
}


position getPosition(char c)
{
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(c == mat[i][j])
            {
                position p = {i, j};
                return p;
            }
}

string encrypt(string message)
{
    string ctext = "";
    for(int i=0; i<message.length(); i+=2)    
    {
		position p1 = getPosition(message[i]);
		position p2 = getPosition(message[i+1]);
        int x1 = p1.row; int y1 = p1.col;
        int x2 = p2.row; int y2 = p2.col;
    
        if( x1 == x2 ) 
        {
            ctext +=  mat[x1][(y1+1)%5];
            ctext +=  mat[x2][(y2+1)%5];
        }
        else if( y1 == y2 ) 
        {
            ctext += mat[ (x1+1)%5 ][ y1 ];
            ctext += mat[ (x2+1)%5 ][ y2 ];
        }
        else
        {
            ctext += mat[ x1 ][ y2 ];
            ctext += mat[ x2 ][ y1 ];
        }
    }
    return ctext;
}


string Decrypt(string message)
{
    string ptext = "";
    for(int i=0; i<message.length(); i+=2) 
    {
        position p1 = getPosition(message[i]);
		position p2 = getPosition(message[i+1]);
        int x1 = p1.row; int y1 = p1.col;
        int x2 = p2.row; int y2 = p2.col;

        if( x1 == x2 ) 
        {
            ptext += mat[x1][ --y1<0 ? 4: y1 ];
            ptext += mat[x2][ --y2<0 ? 4: y2 ];
        }
        else if( y1 == y2 ) 
        {
            ptext += mat[ --x1<0 ? 4: x1 ][y1];
            ptext += mat[ --x2<0 ? 4: x2 ][y2];
        }
        else
        {
            ptext += mat[ x1 ][ y2 ];
            ptext += mat[ x2 ][ y1 ];
        }
    }
    return ptext;
}

int main()
{    
    string plaintext;
    cout << "Enter message : "; cin >> plaintext;

    int n; 
    cout << "Enter number of keys : "; cin >> n;

    string key[n];
    for(int i=0; i<n; i++)
    {
        cout<< "\nEnter key " << i+1 << " : " << key[i];
        cin >> key[i];

        generateMatrix(key[i]);

        cout << "Key " << i+1 << " Matrix:" << endl;
        for(int k=0;k<5;k++)
        {
            for(int j=0;j<5;j++)
            {
                cout << mat[k][j] << "  ";
            }
            cout << endl;
        }

        cout << "Actual Message \t\t: " << plaintext << endl;

        string fmsg = formatMessage(plaintext);
        cout << "Formatted Message \t: " << fmsg << endl;

        string ciphertext = encrypt(fmsg);
        cout << "Encrypted Message \t: " << ciphertext << endl;

        string decryptmsg = Decrypt(ciphertext);
        cout<< "Decrypted Message \t: " << decryptmsg << endl;
    }
}
//}#include <bits/stdc++.h>
//using namespace std;
//
//int RemoveSpaces(char arr[], int len)
//{
//    int i, count = 0;
//    for (i = 0; i < len; i++)
//        if (arr[i] != ' ')
//            arr[count++] = arr[i];
//    arr[count] = '\0';
//    return count;
//}
//
//void GenerateKeyTable(char keyarr[5], int keylen, char keyTable[5][5])
//{
//    int i, j, k, flag = 0;
//    int map[26] = {0};
//    for (i = 0; i < keylen; i++)
//    {
//        if (keyarr[i] != 'J')
//            map[keyarr[i] - 65] = 2;
//    }
//    map['J' - 65] = 1;
//    i = 0;
//    j = 0;
//    for (k = 0; k < keylen; k++)
//    {
//        if (map[keyarr[k] - 65] == 2)
//        {
//            map[keyarr[k] - 65] -= 1;
//            keyTable[i][j] = keyarr[k];
//            j++;
//            if (j == 5)
//            {
//                i++;
//                j = 0;
//            }
//        }
//    }
//    for (k = 0; k < 26; k++)
//    {
//        if (map[k] == 0)
//        {
//            keyTable[i][j] = (char)(k + 65);
//            j++;
//            if (j == 5)
//            {
//                i++;
//                j = 0;
//            }
//        }
//    }
//}
//
//void search(char keyTable[5][5], char a, char b, int arr[])
//{
//    int i, j;
//    if (a == 'J')
//        a = 'I';
//    else if (b == 'J')
//        b = 'I';
//    for (i = 0; i < 5; i++)
//    {
//        for (j = 0; j < 5; j++)
//        {
//            if (keyTable[i][j] == a)
//            {
//                arr[0] = i;
//                arr[1] = j;
//            }
//            else if (keyTable[i][j] == b)
//            {
//                arr[2] = i;
//                arr[3] = j;
//            }
//        }
//    }
//}
//
//int mod5(int a)
//{
//    if (a < 0)
//        a += 5;
//    return (a % 5);
//}
//
//int Prepare(char arr[], int len)
//{
//    if (len % 2 != 0)
//    {
//        arr[len++] = 'Z';
//        arr[len] = '\0';
//    }
//    return len;
//}
//
//void Encrypt(char textarr[], char keyTable[5][5], int textlen)
//{
//    int i, arr[4];
//    for (i = 0; i < textlen; i += 2)
//    {
//        search(keyTable, textarr[i], textarr[i + 1], arr);
//        if (arr[0] == arr[2])
//        {
//            textarr[i] = keyTable[arr[0]][mod5(arr[1] + 1)];
//            textarr[i + 1] = keyTable[arr[0]][mod5(arr[3] + 1)];
//        }
//        else if (arr[1] == arr[3])
//        {
//            textarr[i] = keyTable[mod5(arr[0] + 1)][arr[1]];
//            textarr[i + 1] = keyTable[mod5(arr[2] + 1)][arr[1]];
//        }
//        else
//        {
//            textarr[i] = keyTable[arr[0]][arr[3]];
//            textarr[i + 1] = keyTable[arr[2]][arr[1]];
//        }
//    }
//}
//
//void Decrypt(char textarr[], char keyTable[5][5], int textlen)
//{
//    int i, arr[4];
//    for (i = 0; i < textlen; i += 2)
//    {
//        search(keyTable, textarr[i], textarr[i + 1], arr);
//        if (arr[0] == arr[2])
//        {
//            textarr[i] = keyTable[arr[0]][mod5(arr[1] - 1)];
//            textarr[i + 1] = keyTable[arr[0]][mod5(arr[3] - 1)];
//        }
//        else if (arr[1] == arr[3])
//        {
//            textarr[i] = keyTable[mod5(arr[0] - 1)][arr[1]];
//            textarr[i + 1] = keyTable[mod5(arr[2] - 1)][arr[1]];
//        }
//        else
//        {
//            textarr[i] = keyTable[arr[0]][arr[3]];
//            textarr[i + 1] = keyTable[arr[2]][arr[1]];
//        }
//    }
//}
//
//string PlayfairEncrypt(char textarr[], char keyarr[])
//{
//    char keyTable[5][5];
//    string result;
//    int keylen = RemoveSpaces(keyarr, strlen(keyarr));
//    int textlen = RemoveSpaces(textarr, strlen(textarr));
//    textlen = Prepare(textarr, textlen);
//    GenerateKeyTable(keyarr, keylen, keyTable);
//    Encrypt(textarr, keyTable, textlen);
//    result = textarr;
//    return result;
//}
//
//string PlayfairDecrypt(char textarr[], char keyarr[])
//{
//    char keyTable[5][5];
//    string result;
//    int keylen = strlen(keyarr);
//    int textlen = strlen(textarr);
//    GenerateKeyTable(keyarr, keylen, keyTable);
//    Decrypt(textarr, keyTable, textlen);
//    result = textarr;
//    return result;
//}
//
//int main()
//{
//    int option;
//    string key, text, cipherText;
//    char keyarr[30], textarr[30], cipher[30];
//    cout << "Enter option:\n1)Console\n2)File\n";
//    cin >> option;
//    cin.ignore();
//    cout << "Enter key: ";
//    getline(cin, key);
//    strcpy(keyarr, key.c_str());
//    switch (option)
//    {
//    case 1:
//        cout << "Enter text: ";
//        break;
//    case 2:
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//        break;
//    }
//    getline(cin, text);
//    strcpy(textarr, text.c_str());
//    cipherText = PlayfairEncrypt(textarr, keyarr);
//    cout << "Cipher Text: " << cipherText << endl;
//    strcpy(cipher, cipherText.c_str());
//    cout << "Deciphered Text: " << PlayfairDecrypt(cipher, keyarr);
//    return 0;
//}
