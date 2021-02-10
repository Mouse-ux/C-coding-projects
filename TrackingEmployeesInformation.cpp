// Author:      Matthew McCormack 
// Class:       CS 2020 Fall 2019
// Written in C++

// Program task is to help BGSU dining center with tracking employees information.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee {
 int id; // unique employee identifier
 string name; // employee’s full name
 double rate; // employee’s hourly rate
 double hours; // how many hours they worked since last pay
 double taxable; // the current year’s taxable income
};

// Functions
int menu();
void addEmp( Employee [], int);
void addHours(Employee [], int);
void printPaychecks(Employee [], int);
int findEmp(int, Employee [], int);
void exit(int);

// Main
int main(){

    int Employee = 50;
    Employee EMPlist[EMPLOYEES];

    
    int Endless;
    int currentEMPLOYEES = 0;
    
    do {

        Endless = menu();
        switch(Endless) {
            case 1:
             if (currentEMPLOYEES < EMPLOYEES) {
                addEmp(EMPlist, currentEMPLOYEES);
            currentEMPLOYEES++;
            }
                    break;
            case 2:
                addHours(EMPlist, currentEMPLOYEES);
                    break;
            case 3:
                printPaychecks(EMPlist, currentEMPLOYEES);
                    break;
            case 4: exit(0);
                    
         
        }

    } while(Endless !=4);
    

}

// Function:    Menu 
// Description: Displays menu 
// Parameters:  int x 
// Returns:     x 

// FOR HERU, please make a menu that displays to the user options and what they do. 
int menu(){
    int x = 0;
    cout << " BGSU Dining Center " << endl;
    cout << " ----------------------------------" << endl;
    cout << " 1. Enter new employee information " << endl; 
    cout << " 2. Add hours " << endl;
    cout << " 3. Print paychecks " << endl;
    cout << " 4. Exit " << endl;
    cin >> x; 
    return x;
}

// Function:    addEmp 
// Description: Add new employee to database 
// Parameters:  bool duck, int i 
// Returns:     nothing
void addEmp( Employee EMPlist[], int currentEMPLOYEES ){
    bool duck = true;
    int i=0;

    while(EMPlist[i].id!=0)
    {
        i++;
    }
    cout << "Please enter new employee ID" << endl;
    cin >> EMPlist[i].id;
    while(EMPlist[i].id <= 0 || duck == false)
    {
        cout << "Enter a valid ID" << endl;
        cin >> EMPlist[i].id;
        for (int x=0; x <= i; x++){
            duck = false;
        }
    }
  cout << " Enter employee full name please" << endl;
  cin >> EMPlist[i].name;
  cout << " Enter employee rate please" << endl;
  cin >> EMPlist[i].rate;
  while (EMPlist[i].rate <= 0)
  {
      cout << " Rate incorrect, Please try again." << endl;
      cin >> EMPlist[i].rate;
  }
  EMPlist[i].hours = 0;
  EMPlist[i].taxable = 0;
}

// Function:    addHours 
// Description: To add hours of work to current employed people 
// Parameters:  int tempID, bool found, int i, int hours 
// Returns:     nothing
void addHours( Employee EMPlist[], int currentEMPLOYEES ){
    int tempID = 0;
    bool found = false;
    int i = 0;
    int hours = 0;
    cout << "Please enter employee ID" << endl;
    cin >> tempID;
    while(found == false || tempID <= 0){
        i = findEmp(tempID, EMPlist, currentEMPLOYEES);
            if(i == -1){
                cout << "Not a valid ID, try again" << endl;
                cin >> tempID;
            }
            else {
                break;
            }   
    }
     cout << "Please enter hours worked" << endl;
         cin >> hours;
         EMPlist[i].hours = hours + EMPlist[i].hours;
}

// Function:    printPaychecks 
// Description: To print the paychecks 
// Parameters:  int i, int c 
// Returns:     nothing
void printPaychecks( Employee EMPlist[], int currentEMPLOYEES ){
    cout << " ID# " << " Name " << " Rate " << " Total " << endl;
    for(int i = 0; i < currentEMPLOYEES; i++){
        if( EMPlist[i].hours > 0){
            int c = EMPlist[i].hours * EMPlist[i].rate;
            EMPlist[i].taxable = c;
            cout << "   " << EMPlist[i].id << "       " << EMPlist[i].name << "      " << EMPlist[i].rate << "     " << c << endl;
            EMPlist[i].hours = 0;
        }
    }
   

}

// Function:    findEMP 
// Description: To find employee in database 
// Parameters:  int i 
// Returns:     i or -1
int findEmp( int id ,Employee EMPlist[], int currentEMPLOYEES){
    for(int i = 0; i < currentEMPLOYEES; i++){
        if( EMPlist[i].id == id){
            return i;
        }
    }
    return -1;
}
