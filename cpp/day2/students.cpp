#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	short age;
	string university;
}; 

int main(){
	Student ivan = {"Ivanov Ivan", 20, "MIT"};
	Student petya;
	petya.name = "Petrov Petya";
	petya.university = "Harvard";

	cout << "Petya: " << petya.name << ", " << petya.age << ", " << petya.university << endl;
	cout << "Ivan: " << ivan.name << ", " << ivan.age << ", " << ivan.university << endl;


	return 0;
}