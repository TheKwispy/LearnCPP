#include<iostream>
using namespace std;

enum BREED{GOLDEN,CAIRN,DANDIE,SHETLAND,DOBERMAN,LAB};

class Mammal
{
public:
	// Constructors
	Mammal():itsAge(2),itsWeight(5){}
	~Mammal(){}
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
	Dog():itsBreed(GOLDEN){}
	~Dog(){}
	// Accessors
	BREED GetBreed() const { return itsBreed; }
	void SetBreed(BREED breed) { itsBreed = breed; }
	// Other method
	void WagTail() const { cout << "tail wagging...\n"; }
	void BegForFood() const { cout << "Begging for food... \n"; }
private:
	BREED itsBreed;
};

int main() {
	Dog Fido;
	Fido.Speak();
	Fido.WagTail();
	cout << "Fido is " << Fido.GetAge() << " years old" << endl;
	return 0;
}