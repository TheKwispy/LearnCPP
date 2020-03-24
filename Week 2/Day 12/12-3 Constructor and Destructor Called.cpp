#include<iostream>
using namespace std;
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal
{
public:
	Mammal();
	~Mammal();
	// Accessors
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
	int GetWeight() const { return itsWeight; }
	void SetWeight(int weight) { itsWeight = weight; }
	// Other methods
	void Speak()const { cout << "Mammal sound!\n"; }
	void Sleep() const { cout << "Shhh. I'm sleeping.\n"; }
protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal
{
public:
	// Constructors
	Dog();
	~Dog();
	// Accessors
	BREED GetBreed() const { return itsBreed; }
	void SetBreed(BREED breed) { itsBreed = breed; }
	// Other method
	void WagTail() const { cout << "tail wagging...\n"; }
	void BegForFood() const { cout << "Begging for food... \n"; }
private:
	BREED itsBreed;
};

Mammal::Mammal() : itsAge(3), itsWeight(5) {
	cout << "Mammal Constructor..." << endl;
}
Mammal::~Mammal() {
	cout << "Mammaal Destructor..." << endl;
}
Dog::Dog() : itsBreed(GOLDEN) {
	cout << "Dog Constructor... " << endl;
}
Dog::~Dog() {
	cout << "Dog Destructor..." << endl;
}
int main() {
	Dog Fido;
	Fido.Speak();
	Fido.WagTail();
	cout << "Fido is " << Fido.GetAge() << " years old" << endl;
	return 0;
}