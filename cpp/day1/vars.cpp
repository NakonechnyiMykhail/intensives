#include <iostream>
#include <string>

using namespace std;

int main() {
	char a = 'c';
	char b = 86;
	//cout << a << '\t' << b << endl;
/*
asfas
asf
asf
asf
*/
	bool 		t 		= true;
	bool 		f 		= false;
	
	short 		q 		= 1.7;
	int 		w 		= 224124;
	long long 	r 		= 12312412412512512512l;

	float 		y 		= 2.0;
	double 		x 		= 123.2e12;

	string str1 = "work";
	string str2 = "space";

	// cout << str1 << str2 << endl;
	// cout << str1 + str2 << endl;
	string name;
	cout << "Enter your name: ";
	cin >> name;
	cout << "Hello, " << name << endl;

	return 0;
}