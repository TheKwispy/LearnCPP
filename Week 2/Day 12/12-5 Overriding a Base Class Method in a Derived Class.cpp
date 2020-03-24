#include<iostream>
using namespace std;
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal
{
public:
	// Constructor
	Mammal() { cout << "Mammal Constructor... "; }
	~Mammal() { cout << "Mammal Destructor... "; }
	// Other Methods
	void Speak()const { cout << "Mammal sounds!\n"; }
	void Sleep()const { cout << "shhh. I'm sleeping.\n"; }
protected:
	int itsAge;
	int itsWeight;
};

class Dog: public Mammal
{
public:
	// Constructors
	Dog() { cout << "Dog Constructor... "; }
	~Dog() { cout << "Dog Destructor..."; }
	// Other methods
	void WagTail() const { cout << "Tail wagging...\n"; }
	void BegForFood() const { cout << "Begging for food...\n"; }
	void Speak() const { cout << "Woof!\n"; }
private:
	BREED itsBreed;
};

int main() {
	Mammal bigAnimal;
	Dog Fido;
	bigAnimal.Speak();
	Fido.Speak();
	return 0;
}