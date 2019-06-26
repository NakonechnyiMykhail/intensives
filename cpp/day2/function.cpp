#include <iostream>
#include <string>
using namespace std;

void printName(string name) {
	cout << "Hello, " << name << endl;
}

void get_name() {
	cout << "Enter your name: ";
	string name;
	cin >> name;
	printName(name);
	printName("Mike");
}

int main(){
	get_name();
	// cout << name << endl; - > ERROR
	return 0;
}