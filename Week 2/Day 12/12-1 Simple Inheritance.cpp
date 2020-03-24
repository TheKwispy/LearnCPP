#include <iostream>
using namespace std;
enum BREED { GOLDEN, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal {
public:
	// Constructor
	Mammal();
	~Mammal();
	// Accessors
	int GetAge()	const;
	void SetAge(int);
	int GetWeight() const;
	void SetWeight(int);
	// Other methods
	void Speak();
	void Sleep();
protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal {
public:
	// Constructor
	Dog();
	~Dog();
	// Accessors
	BREED GetBreed() const;
	void SetBreed(BREED);
	// Other methods
	WagTail();
	BegForFood();
protected:
	BREED itsBreed;
};