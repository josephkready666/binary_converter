/*
Title: Convert from one number system to another
Group #: 6
Members: 
    Joseph Kready: T00655228
    Kush Patel: T
    Kwame Williams: T
    Lauren Nowlin: T
*/

//Imports
#include<iostream>
#include<numeric>
#include <algorithm>
#include<string>
using namespace std;

//Function Declariaton 
void main_menu(int*, int*, string* );
int get_number_system();
string get_value_base(int );


int main() {
    
    //Variables
    int baseNumberSystem, targetNumberSystem;
    string valueInBase; 

    //While loop for menu
    bool playing = true;
    while(playing) {
        
        //Main menu
        main_menu(&baseNumberSystem, &targetNumberSystem, &valueInBase); 



    }



    return (0);
}


//Funcitons definations

void main_menu(int* baseNumberSystem, int* targetNumberSystem, string* valueInBase) {
    cout << "\n-------Number system converter-------" << endl;

    cout << "Enter the base number system: ";
    *baseNumberSystem = get_number_system(); 
    
    cout << "Enter the target number system: "; 
    *targetNumberSystem = get_number_system(); 
    
    cout << "Enter the value in base: "; 
    *valueInBase = get_value_base(*baseNumberSystem); 
    
}

int get_number_system() {
    //Checks if inputed range is within 1-16
    
    //Error checking loop
    bool inputLoop = true; 
    while (inputLoop){
        //Get number system from user
        int numSystem; 
        cin >> numSystem; 

        const int possibleBase[15] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

        for (int i=0; i < 15; i++){
            if (numSystem == possibleBase[i])
                return numSystem; 
        }
        cout << "Invalid input! Enter in base number system again: "; 
    }
}


string get_value_base(int baseNumberSystem) {
    //Checks if inputed range is within 1-F
        
    //Get number system from user
    string valueBase; 
    cin.ignore();
    getline(cin, valueBase);

		
    const char hexValues[] = {'A','B','C','D','E','F'};
    const unsigned char baseValues[] = {'0','1','2','3','4','5','6','7','8','9'};

    //Checking base 2-10
    if (baseNumberSystem <= 10){
        for (int i=0; i < valueBase.length(); i++){ //iterate through input
			if (any_of(begin(baseValues), end(baseValues), [=](int n) {return n == valueBase[i]; })) {
				cout << "Invalid input! Enter the value in base again: ";
				return get_value_base(baseNumberSystem);
			}
			break; 
        }
    }

    //Checkign base 11-f
    else if (baseNumberSystem > 10){
		//Converting input into uppercase
		for (int u = 0; u < valueBase.length(); u++) {
			if (isascii(valueBase[u])) {
				valueBase[u] = toupper(valueBase[u]);
			}
		}

        for (int i=0; i < valueBase.length(); i++){ //iterate through input
			if (!any_of(begin(baseValues), end(baseValues), [=](int n) {return n == valueBase[i]; }) || !any_of(begin(hexValues), end(hexValues), [=](int n) {return n == valueBase[i]; })) {
				cout << "Invalid input! Enter the value in base again: ";
				return get_value_base(baseNumberSystem);
			}
        }

    }

    //Passes all input checks. 
    else{
        return valueBase;
    }
}

