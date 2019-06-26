#include <iostream>
using namespace std;

int main(){

	int count = 5;
	int *ptr_count = NULL;
	ptr_count = &count;
	cout << ptr_count << '\t' << *ptr_count << endl;
	cout << count << '\t' << &count << endl;

	return 0;
}