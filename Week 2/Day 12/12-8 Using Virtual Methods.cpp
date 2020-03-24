#include <iostream>
using namespace std;

class Mammal {
public:
	Mammal() : itsAge(1) { cout << "Mammal constructor...\n"; }
	virtual ~Mammal() { cout << "Mammal destructor...\n"; }
	void Move()const { cout << "Mammal moves one step\n"; }
	virtual void Speak() const { cout << "Mammal speak!\n"; }
protected:
	int itsAge;
};
class Dog : public Mammal {
public:
	Dog() { cout << "Dog Constructor...\n"; }
	virtual ~Dog() { cout << "Dog Destructor...\n"; }
	void WagTail() { cout << "Wag tail...\n"; }
	void Speak()const { cout << "Woof!\n"; }
	void Move()const { cout << "Dog moves 5 steps...\n"; }
};
int main() {
	Mammal* pDog = new Dog;
	pDog->Move();
	pDog->Speak();

	return 0;
}