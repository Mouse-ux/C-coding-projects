// Author:      Matthew McCormack
// Class:       CS 3320
// Date:        Fall 2020


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

// Function prototypes
int menu();
void Symbols();
void Definition();
void CheckPassword();

using namespace std;
int main()
{
   int choice = menu();
    while (choice != 4) {
        switch (choice) {
            case 1:
                Symbols();
                break;
            case 2:
                Definition(); 
                break;
            case 3:
                CheckPassword();
                break;
        }
        choice = menu();
    }

}

// Function:    menu()
// Description: displays a menu to users, asks for input, validates the input
// Parameters:  none
// Returns:     a valid menu choice
int menu() 
{
    int input;
    cout << "                        " << endl;
    cout << "        Password Checker" << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Examples of special characters (Symbols)" << endl;
    cout << "2. Brief definition of strong password" << endl;
    cout << "3. Check password strength" << endl;
    cout << "4. Exit Program" << endl << endl;
    cout << "Select a menu option (press enter): ";
    cin >> input;

    // validate the input
    if (input < 1 || input > 4)
        return menu();

    return input;
}

void Symbols() 
{
    cout << " The following list will show all special characters you may use in your password to help inprove the strength of the password " << endl;
    cout <<"----------------------------------------------------------------" << endl;
    cout <<" !	Exclamation	"<< endl;
    cout <<" ”	Double quote " << endl;	
    cout <<" #	Number sign (hash) " << endl;	
    cout <<" $	Dollar sign " << endl;	
    cout <<" %	Percent	" << endl;
    cout <<" & 	Ampersand " << endl;	
    cout <<" ’	Single quote " << endl;	
    cout <<" (	Left parenthesis " << endl;	
    cout <<" )	Right parenthesis " << endl;	
    cout <<" *	Asterisk " << endl;	
    cout <<" +	Plus " << endl;	
    cout <<" ,	Comma " << endl;	
    cout <<" -	Minus " << endl;	
    cout <<" .	Full stop " << endl;	
    cout <<" /	Slash " << endl;	
    cout <<" :	Colon " << endl;	
    cout <<" ;	Semicolon " << endl;	
    cout <<" <	Less than " << endl;	
    cout <<" =	Equal sign " << endl;	
    cout <<" >	Greater than " << endl;	
    cout <<" ?	Question mark " << endl;	
    cout <<" @	At sign " << endl;
    cout <<" [	Left bracket " << endl;		
    cout <<" ]	Right bracket " << endl;	
    cout <<" ^	Caret " << endl;	
    cout <<" _	Underscore " << endl;	
    cout <<" `	Grave accent (backtick) " << endl;	
    cout <<" {	Left brace " << endl;	
    cout <<" |	Vertical bar " << endl;	
    cout <<" }	Right brace " << endl;	
    cout <<" ~	Tilde " << endl;

}

void Definition()
{
    cout <<" The following definition is taken from support.microsoft.com " << endl;
    cout <<"------------------------------------------------------------- " << endl;
    cout <<" A strong password is: At least 12 characters long but 14 or more is better." << endl; cout << " A combination of uppercase letters, lowercase letters, numbers, and symbols. Not a word that can be found in a dictionary. ... Significantly different from your previous passwords. " << endl;


}

void CheckPassword()
{
    string password;
    cout << " Please enter your password to be checked " << endl;
    cin >> password;
    
    int n = password.length();
    // Checking lower alphabet in string 
    bool hasLower = false;
    bool hasUpper = false; 
    bool hasDigit = false; 
    bool specialChar = false; 
    string normalChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 "; 
  
    for (int i = 0; i < n; i++) { 
        if (islower(password[i]))
        {
            hasLower = true;
        } 
        if (isupper(password[i]))
        {
            hasUpper = true;
        }
        if (isdigit(password[i]))
        { 
            hasDigit = true;
        }
        size_t special = password.find_first_not_of(normalChars); 
        if (special != string::npos)
        { 
            specialChar = true;
        } 
    }

    /*for(int x = 0; x < n; x++){
        if(!hasLower)
        {
            cout << " Password must include lowercase letter(s) " << endl;
            CheckPassword();
        }
        if(!hasUpper)
        {
            cout << " Password must include uppercase letter(s) " << endl;
            CheckPassword();
        }
        if(!hasDigit)
        {
            cout << " Password must include numbers " << endl;
            CheckPassword();
        }
        if(!specialChar)
        {
            cout << " Password must include special characters (Symbols) " << endl;
            CheckPassword();
        }
    }*/
 
    if (hasLower && hasUpper && hasDigit &&  specialChar && (n >= 12)) 
        cout << " Password is strong " << endl; 
    else
        cout << " Password is Weak " << endl; 

}
