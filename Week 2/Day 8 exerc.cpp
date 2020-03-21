#include<iostream>
using namespace std;

int main() {

	unsigned short int yourAge;
	unsigned short int* pAge = &yourAge;
	*pAge = 50;
	cout << *pAge << endl;
	return 0;
}