#include <iostream>

using namespace std;

int main(){
	int arr[10];
	int arr2d[2][2] = { {1,2},
						{3,4}};

	for (int i = 0; i < 10; ++i) {
		arr[i] = 3 * i;
		// cout << arr[i] << ' ';
	}
	//cout << endl;

	short count = 2;

	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count; ++j)
		{
			cout << arr2d[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;


	return 0;
}