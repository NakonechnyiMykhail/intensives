#include <iostream>
#include <string>
using namespace std;

int main(){
//1
//	for (int i = 0; i <= 10; i++){
//		cout << i *2 << endl;
//	}
//2
//	int array[] = {7, 5, 6, 4, 9, 8, 2, 1, 3};
//	int dim = sizeof(array)/sizeof(array[0]);
//	for (int i = 0; i < dim; i++){
//		cout << array[i] << endl;
//	}
//3 
	cout << "Enter your full name: ";
	string name;
	getline(cin, name);
	cout << "Enter your age: ";
	short age;
	cin >> age;
	cout << "Name: " << name << '\t' << "Age: " << age << endl;
	cout << "Length: " << name.length() << endl;
//4
	cout << ((true && true) || false) << endl;
	cout << ((false && true) || true) << endl;
	cout << ((false && true) || false || true) << endl;
	cout << ((5>6 || 4>3) && (7 > 8)) << endl;
	cout << (!(7>6 || 3>4)) << endl;



	return 0;
}
