#include <iostream>
using namespace std;
// Creating Class
class SimpleCat {
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};
// Defining Constructor
SimpleCat::SimpleCat() {
	cout << "SimpleCat Constructor... " << endl;
	itsAge = 1;
}
// Defining Copy Constructor
SimpleCat::SimpleCat(SimpleCat&) {
	cout << "Simple Cat Copy Constructor... " << endl;
}
// Defining Destructor
SimpleCat::~SimpleCat() {
	cout << "Simple Cat Destructor... " << endl;
}
// Declaring Function
const SimpleCat* const FunctionTwo(const SimpleCat* const theCat);

int mainb() {
	cout << "Making a cat..." << endl;
	SimpleCat Frisky;
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " years old" << endl;
	int age = 5;
	Frisky.SetAge(age);
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " years old" << endl;
	cout << "Calling FunctionTwo..." << endl;
	FunctionTwo(&Frisky);
	cout << "Frisky is ";
	cout << Frisky.GetAge();
	cout << " years old" << endl;
	return 0;
}

// Defining Function
// FunctionTwo, passes a const pointer
const SimpleCat* const FunctionTwo(const SimpleCat* const theCat) {
	cout << "FunctionTwo. Returning..." << endl;
	cout << "Frisky is now " << theCat->GetAge();
	cout << " years old " << endl;
	// theCat->SetAge(8); const!
	return theCat;
}