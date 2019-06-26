#include <iostream>
#include <string>
using namespace std;
//прототипы
double sum(double a, double b);
double pow(double value, int power);
int randrange(int low,int high);

int main(){
	//1
	double x = 23.2, y = 12.3;
	int z = 14;
	cout << sum(x,y) << endl;
	cout << sum(x,z) << endl;
	//2
	cout << sum(5.2,4.5) << endl;
	//3
	cout << pow(5.3,2) << endl;
	//4
	srand(time(0));
 	cout << pow(randrange(0, 10),2) << endl;

	return 0;
}
double sum(double a, double b){
	return a + b;
}

double pow(double value, int power) {
	double temp = value;
	for (int i = 1; i < power; i++) {
		// temp = temp * value;
		temp *= value;
	}
	return temp;
}

int randrange(int low,int high)
{
    return rand()%(high-low+1)+low;
}

 








