#include<iostream>
using namespace std;
class Cat {
public:
	Cat();	// default constructor
	Cat(const Cat&); // Copy constructor
	~Cat();	// Destructor
	int GetAge() const { return *itsAge; }
	int Getweight() const { return *itsWeight; }
	void SetAge(int age) { *itsAge = age; }
private:
	int* itsAge;
	int* itsWeight;
};
// Defining constructors
Cat::Cat() {
	itsAge = new int;
	itsWeight = new int;
	*itsAge = 5;
	*itsWeight = 9;
}
Cat::Cat(const Cat& rhs) {
	itsAge = new int;
	itsWeight = new int;
	*itsAge = rhs.GetAge(); // Public access
	*itsWeight = *(rhs.itsWeight); // Private Access
}
Cat::~Cat() {
	delete itsAge;
	itsAge = 0;
	delete itsWeight;
	itsWeight = 0;
}

int main() {
	Cat Frisky;
	cout << "Frisky's age: " << Frisky.GetAge() << endl;
	cout << "Setting Frisky to 6...\n";
	Frisky.SetAge(6);
	cout << "Creating Boots from Frisky"<<endl;
	Cat Boots(Frisky);
	cout << "Frisky's age: " << Frisky.GetAge() << endl;
	cout << "Boots' age: " << Boots.GetAge() << endl;
	Frisky.SetAge(7);
	cout << "Frisky's age: " << Frisky.GetAge() << endl;
	cout << "Boots' age: " << Boots.GetAge() << endl;
	return 0;
}