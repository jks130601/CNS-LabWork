//ceasar cipher encryption and decryption

#include <iostream>

using namespace std;

int main() {
	int option;
	cout<<"Ceasar Cipher: \n"<<"Options: 1.Encryption   2.Decryption "<<endl;
	cin>>option;
	cout<<endl;
//	fflush();
    string msg;
    cout<<"Enter your message: ";
    cin>>msg;
    int shift;
    cout<<"Enter the shift: ";
    cin>>shift;
    string encrypt="";
    string decrypt="";
    int msglen =msg.size();
    if(option == 1)
    {
    	for(int i=0; i<msglen; i++)
	    {
	        if(msg[i]>= 65 && msg[i]<= 90)
	        {
	           
	            encrypt += char(((int(msg[i]) + shift - 65)  % 26) +65 );
	        }
	        if(msg[i]>= 97 && msg[i]<= 122)
	        {
	           
	            encrypt += char(((int(msg[i]) + shift - 97)  % 26) +97 );
	        }
	        
	    }
	    cout<<"Encrypted message : "<< encrypt<< endl;
    	
	}
    
    else{
    	for(int i=0; i<msglen; i++)
	    {
	        if(msg[i]>= 65 && msg[i]<= 90)
	        {
	           
	            decrypt += char(((int(msg[i]) - shift - 65 +26)  % 26) +65 );
	        }
	        if(msg[i]>= 97 && msg[i]<= 122)
	        {
	           
	            decrypt += char(((int(msg[i]) - shift - 97 +26)  % 26) +97 );
	        }
	        
	    }
	    cout<<"Decrypted message : "<< decrypt<< endl;
	}

    
    
    return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
 
string encrypt(string text, int s)
{
    string res = "";
 
    s%=26;
 for (int i=0;i<text.length();i++)
    {
        if (isupper(text[i])){
            if(text[i]+s > 90)
                res += char(64+int(text[i]+s)%90);
            else
                res += char(int(text[i]+s));
        }
        else{
            if(text[i]+s > 122)
                res += char(96+int(text[i]+s)%122);
            else
                res += char(int(text[i]+s));
        }
           
    }
 
    return res;
}
 
void decrypt(string text)
{
    string result = "";
    for (int i = 1; i < 26; i++)
    {
        for (int j = 0; j < text.length(); j++)
        {
            int a = text[j]-i;
            if(a <65)
                result += char(91-(65-a));
            else
                result += char(a);
        }
        cout << "Using key " << i << ": " << result << "\n";
        result.clear();
    }
}
 
 
 
int main()
{
    int option;
    cout << "Enter choice:\n1) Console Encrypt\n2) File\n3) Console Decrypt\n";
    cin >> option;
     int shift;
    string text;
   
    switch (option)
    {
        case 1:
            cout << "Enter Text: ";
             cin >> text;
           
            cout << "Enter Shift: ";
            cin >> shift;
            cout << "Cipher Text: "<< encrypt(text, shift) << "\n";
            break;
 
        case 2:
           
            cout << "Enter Shift: ";
            cin >> shift;
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            break;
        case 3 :
            cout << "Enter Text: ";
            cin >> text;
            cout << "Cipher Text:\n ";
            decrypt(text);
            break;
 
 
 
        default:
            break;
    }
   
    return 0;
}*/

