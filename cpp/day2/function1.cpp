#include <iostream>
#include <string>
using namespace std;

string get_name();
void printName(string name); // (string)

int main(){
	string str = get_name();
	printName(str);

	return 0;
}



string get_name() {
	cout << "Enter your name: ";
	string name;
	cin >> name;
	return name;
}
void printName(string name) {
	cout << "Hello, " << name << endl;
}