#include <iostream>
using namespace std;
class Mammal
{
public:
	void Move() const { cout << "Mammal moves one step.\n"; }
	void Move(int distance)const {
		cout << "Mammal moves " << distance << " steps.\n";
	}
protected:
	int itsAge;
	int itsWeight;
};

class Dog : public Mammal
{
public:
	// You might recieve a warning that you're hiding a function!
	void Move() const { cout << "Dog moves 5 steps.\n"; }
};
int main() {
	Mammal bigAnimal;
	Dog Fido;
	bigAnimal.Move();
	bigAnimal.Move(2);
	Fido.Move();
	// Fido.Move(10);		Causes a compile-time error, since we overrid the Move function and didn't overload our Move function in Dog 
	return 0;
}