#include <iostream>

using namespace std;

int main ()
{
    int x = 1,
    	y = 2;
    cout << "x1 = " << x << " x1 adress = " << &x << endl;
    cout << "y1 = " << y << " y1 adress = " << &y << endl;
    int& num = x;
    cout << "num1 = " << num << " num1 adress = " << &num << endl;
    num = y;
    cout << "x2 = " << x << " x2 adress = " << &x << endl;
    cout << "y2 = " << y << " y2 adress = " << &y << endl;
    cout << "num2 = " << num << " num2 adress = " << &num << endl;
}