/*
Title: Convert from one number system to another
Group #: 6
Members: 
    Joseph Kready: T00655228
    Kush Patel: T00640682
    Kwame Williams: T00629167
    Lauren Nowlin: T00616689
*/

//Imports
#include<iostream>
#include<numeric>
#include<algorithm>
#include<string>
#include<stdio.h> 
#include<vector>
using namespace std;

//Function Declariaton 
void main_menu(int*, int*, string* );
int get_number_system();
string get_value_base(int );
int val(char c);
int toDeci(char*, int);
char reVal(int);
void strev(char*);
char* fromDeci(char[], int, int);



int main() {
    
    //Variables
    int baseNumberSystem, targetNumberSystem;
    string valueInBase; 

    //While loop for menu
    bool playing = true;
    while(playing) {
        
        //Main menu
        main_menu(&baseNumberSystem, &targetNumberSystem, &valueInBase); 

		//Solution Switch
		string solution;
		switch (targetNumberSystem)
		{
		case(2):

			break;

		case(10):

			break;

		case(16):

			break;

		default:
			break;
		}

		//BONUS
		char* charValueInBase = &valueInBase[0];
		solution = to_string(toDeci(charValueInBase, baseNumberSystem));
		if(targetNumberSystem != 10){
			char res[100];
			solution = fromDeci(res, targetNumberSystem, stoi(solution));
		}		
		//BONUS

		//Conversion Answer
		cout << "\nAnswer: " << valueInBase << " in base " << baseNumberSystem << " is equal to " << solution << " in base " << targetNumberSystem << endl;

    }

    return (0);
}


//Funcitons definations

void main_menu(int* baseNumberSystem, int* targetNumberSystem, string* valueInBase) {
	//Displays Menu

    cout << "\n-------Number system converter-------" << endl;

    cout << "Enter the base number system: ";
    *baseNumberSystem = get_number_system(); 
    
    cout << "Enter the target number system: "; 
    *targetNumberSystem = get_number_system(); 
    
    cout << "Enter the value in base: "; 
	cin.ignore();
    *valueInBase = get_value_base(*baseNumberSystem); 
    
}

int get_number_system() {
    //Checks if inputed range is within 1-16
    
    //Get number system from user
	string numSystem; 
    cin >> numSystem; 

    const int possibleBase[15] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	//Error checks
	for (int i = 0; i < numSystem.length(); i++) { //Checking if user inputs char
		if (isalpha(numSystem[i])) {
			cout << "Invalid input! Enter in base number system again: ";
			return get_number_system();
			 
		}
	}

	//check if user inputs > 16
	int int_numSystem = stoi(numSystem);
	for (int i = 0; i < 15; i++) {
		if (int_numSystem == possibleBase[i]) {
			return int_numSystem;
		}
	}
	cout << "Invalid input! Enter in base number system again: ";
	return get_number_system();
}

string get_value_base(int baseNumberSystem) {  
	//Checks if inputed range is within 1-F
        
    //Get number system from user
    string valueBase; 
    getline(cin, valueBase);

     vector<char> hexValues = {'A','B','C','D','E','F'};
     vector<char> baseValues = {'0','1','2','3','4','5','6','7','8','9'};

    //Checking base 2-10
    if (baseNumberSystem <= 10){
		vector<char> search_vec(baseValues.begin(), baseValues.begin() + baseNumberSystem); //Vector used for the searching
        for (int i=0; i < valueBase.length(); i++){ //iterate through input
			//Error checking
			auto searchIterator = find(search_vec.begin(), search_vec.end(), valueBase[i]);
			if (searchIterator == search_vec.end() || isalpha(valueBase[i])) {
				cout << "Invalid input! Enter the value in base again: ";
				return get_value_base(baseNumberSystem);
			}
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
		int charVecLength = baseNumberSystem - 10; 
		vector<char> charSearchVec(hexValues.begin(), hexValues.begin() + charVecLength); //Vector used for the searching
        for (int i=0; i < valueBase.length(); i++){ //iterate through input
			auto charSearchIterator = find(charSearchVec.begin(), charSearchVec.end(), valueBase[i]);
			if (isalpha(valueBase[i])) { //checking letters
				if (charSearchIterator == charSearchVec.end()) {
					cout << "Invalid input! Enter the value in base again: ";
					return get_value_base(baseNumberSystem);
				}
			}
        }

    }

    //Passes all input checks. 
    return valueBase;
    
}



int val(char c){
	//Source: https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// To return value of a char. For example, 2 is returned for '2'.  10 is returned for 'A', 11 for 'B' 
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

 
int toDeci(char* str, int base){
	//Source: https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// Function to convert a number from given base 'b' to decimal
	int len = strlen(str);
	int power = 1; // Initialize power of base 
	int num = 0;  // Initialize result 
	int i;

	// Decimal equivalent is str[len-1]*1 + 
	// str[len-1]*base + str[len-1]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be 
		// less than number's base 
		if (val(str[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(str[i]) * power;
		power = power * base;
	}

	return num;
}


char reVal(int num){
	//Source: https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// To return char for a value. For example '2' is returned for 2. 'A' is returned for 10. 'B' for 11 
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}


void strev(char* str){
	//Source: https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// Utility function to reverse a string 
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}


char* fromDeci(char res[], int base, int inputNum){
	//Source: https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
	// Function to convert a given decimal number  to a base 'base' and 
	int index = 0;  // Initialize index of result 

		// Convert input number is given base by repeatedly 
		// dividing it by base and taking remainder 
	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);

	return res;
}

