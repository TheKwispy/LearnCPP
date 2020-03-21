#include <iostream>

using namespace std;
// Public and Private are know as the access control keywords
class Cat
{
	// These are (by default) private memebers, they can't be accessed outside of the class
	unsigned int itsAge;
	unsigned int itsWeight;
	//These are public, we can access these outside the class
public:
	// We declare a constructor
	Cat(int initialAge);
	// We decalre a destructor aswell, it's just the name of the class with a squigly infront ~
	~Cat();
	void Meow() {
		cout << "Eeeh" << endl;
	}
	// These are know as accessor methods, it's good practice to use these to access and alter the private memebers
	void SetAge(unsigned int age) {
		itsAge = age;
	}
	// Functions that don't change anything can be declared as constanst with "const"
	// This is good practise, the compiler can catch the error before it becomes a bug if you messed something up while writing it
	unsigned int GetAge() const {
		return itsAge;
	}
	void SetWeight(unsigned int weight) {
		itsWeight = weight;
	}
	unsigned int GetWeight() const {
		return itsWeight;
	}
};
// Another method to define functions in classes w/out writing them inside a class, good for using same function in
// multiple different ie classes
// Constructor for Cat
Cat::Cat(int initialAge) {
	itsAge = initialAge;
}

// And the destructor which does nothing
Cat::~Cat() {
}


int main() 
{
	

	// Here we say that Jussi is an object of the type Cat same way the itsAge is a variable of the type unsigned int
	// An object is an individual instance of a class, here initialized with the age of 10
	Cat Jussi(10);
	// After defining a Object we can access it's members with the dot operator ie Jussi.itsAge = 14 if it was a public member
	cout << "Starting age" << Jussi.GetAge() << "\nNow we redifine the age using Jussi.SetAge" << endl;
	Jussi.SetAge(14);
	// In the same way we can access it's functions
	Jussi.Meow();
	cout << "The kitteh is " << Jussi.GetAge() << " years old" << endl;
	// Here we ask user input for the weight, set it and then do a check to see if it's a big kitteh  
	unsigned int input;
	cout << "Is he a thicc boi? if yes put in over 5" << endl;
	cin >> input;
	Jussi.SetWeight(input);
	unsigned int chonky = Jussi.GetWeight();
	if (chonky > 5) {
		cout << "He a chonky boi!" << endl;
	}
	else if (chonky >= 10) {
		cout << "Ow lawd he commin" << endl;
	}
	else {
		cout << "He a smoll boi" << endl;
	}
	return 0;
}