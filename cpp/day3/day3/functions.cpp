#include <iostream>
#include <string>

using namespace std;

double sum(double, double);

int main()
{
    cout << "Enter your name: ";
    string name;
    cin >> name;
    cout << sum(14.5,25.6)<< endl;
    return 0;
}

double sum(double a, double b){
    return a+b;
}
