#include <iostream>
#include <string>
#include <cstring> // <string.h>

using namespace std;

int main() {
	int arr[] = {1,4,2,5};
	char a[5];

	cout << arr[1] << endl;
	a[0] = 'm';
	a[1] = 'i';
	a[2] = 'k';
	a[3] = 'e';
	a[4] = '\0';
	char b[4] = {'m','i','k','e'};	
	char str[] = "hello";

	//string street;
	//cin >> street;
	// string myName;
	// getline(cin, myName);


	//cout << street << endl;
	// cout << myName << endl;

	char name[255];
	char street[15];
	cin.getline(street, 15); //20
	cout << street << endl;

	return 0;
}