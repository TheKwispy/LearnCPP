#include<iostream>
using namespace std;
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };
class Mammal
{
public:
	// Constructors
	Mammal();
	Mammal(int age);
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
	Dog(int age);
	Dog(int age, int weight);
	Dog(int age, BREED breed);
	Dog(int age, int weight, BREED breed);
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

Mammal::Mammal() : itsAge(1), itsWeight(5) {
	cout << "Mammal Constructor..." << endl;
}
Mammal::Mammal(int age) : itsAge(age), itsWeight(5) {
	cout << "Mammal(int) constructor..." << endl;
}
Mammal::~Mammal() {
	cout << "Mammaal Destructor..." << endl;
}
// Not necessary to call the default Mammal constructor, this just illustrates what is happening
Dog::Dog() : Mammal(), itsBreed(GOLDEN) {
	cout << "Dog Constructor... " << endl;
}
Dog::Dog(int age) : Mammal(age), itsBreed(GOLDEN) {
	cout << "Dog(int) constructor..." << endl;
}
Dog::Dog(int age, int weight) : Mammal(age), itsBreed(GOLDEN) {
	itsWeight = weight;
	cout << "Dog(int, int) constructor..." << endl;
}
Dog::Dog(int age, int weight, BREED breed) : 
	Mammal(age), 
	itsBreed(breed) 
{
	itsWeight = weight;
	cout << "Dog(int, int, BREED) constructor..." << endl;
}
Dog::Dog(int age, BREED breed) :
	Mammal(age),
	itsBreed(breed) {
	cout << "Dog(int, BREED) constructor... " << endl;
}
Dog::~Dog() {
	cout << "Dog Destructor..." << endl;
}
int main() {
	Dog Fido;
	Dog rover(5);
	Dog buster(6, 8);
	Dog yorkie(3, GOLDEN);
	Dog dobbie(4, 20, DOBERMAN);
	Fido.Speak();
	rover.WagTail();
	cout << "Yorkie is " << yorkie.GetAge() << " years old" << endl;
	cout << "Dobbie weighs " << dobbie.GetWeight() << " pounds" << endl;
	return 0;
}