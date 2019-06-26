#include <iostream>

using namespace std;
int main() {
	int x = 3;
	int y = 5;
	if (x > y) 
	{
		cout << x << "is bigger than " << y << endl;
	}
	else if (x < y) 
	{
		cout << "y = " << y << "is bigger than " << x << endl;
	}
	else 
	{
		cout << "x & y are equal" << endl;
	}


	return 0;
}