// Day 8 Understanding pointers
//

#include <iostream>
using namespace std;
typedef unsigned short int USHORT;
// Creating and deleting objects on the free store

// For func 6
class SimpleCat {
public:
	SimpleCat();
	~SimpleCat();
private:
	int itsAge;
};
SimpleCat::SimpleCat()
{
	cout << "Constructor called." << endl;
	itsAge = 1;
}
SimpleCat::~SimpleCat()
{
	cout << "Destructor called." << endl;
}
// For func 7
class Cat {
public:
	Cat() { itsAge = 2; }
	~Cat(){}
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};
// For func 8
class MemberCat {
public:
	MemberCat();
	~MemberCat();
	int GetAge()const { return *itsAge; }
	void SetAge(int age) { *itsAge = age; }
	int GetWeight() const { return *itsWeight; }
	void setWeight(int weight) { *itsWeight = weight; }
private:
	int* itsAge;
	int* itsWeight;
};
MemberCat::MemberCat() {
	itsAge = new int(2);
	itsWeight = new int(5);
}
MemberCat::~MemberCat() {
	delete itsAge;
	delete itsWeight;
}


// Funcs
void first() {
	// Adress-Of operator demo
	unsigned short shortVar = 5;
	unsigned long longVar = 65535;
	long sVar = -65535;

	cout << "shortVar:\t" << shortVar;
	cout << "\tAdress of shortVar:\t";
	// adress-of (&) comes in here
	cout << &shortVar << endl;

	cout << "longVar:\t" << longVar;
	cout << "\tAdress of longVar:\t";
	cout << &longVar << endl;

	cout << "sVar:\t\t" << sVar;
	cout << "\tAdress of sVar:\t";
	cout << &sVar << endl;
}
void sec() {
	unsigned short int howOld = 25;
	// Stores the mem adress in pAge
	// the * after the value type and before the name indicates a pointer
	unsigned short int* pAge = &howOld;
	unsigned short int yourAge;
	// using a pointer to provide indirect access to the value
	// if you skip the * your assigning the value stored in pAge, the mem adress not the value
	yourAge = *pAge;
	cout << yourAge << endl;
}
void third() {
	// Manipulate data using pointers
	USHORT myAge;
	USHORT* pAge=0;

	myAge = 5;
	
	cout << "myAge: " << myAge << endl;
	pAge = &myAge;	//Assign adress of myAge to pAge
	cout << "*pAge: " << *pAge << endl << endl;

	cout << "Setting *pAge = 7... " << endl;
	*pAge = 7;	// sets myAge to 7

	cout << "*pAge: " << *pAge << endl;
	cout << "myAge: " << myAge << endl;

	cout << "Setting myAge=9..." << endl;
	myAge = 9;
	cout << "myAge: " << myAge << endl;
	cout << "*pAge: " << *pAge << endl;
}
void fourth() {
	USHORT myAge = 5, yourAge = 10;
	// a pointer
	USHORT* pAge = &myAge;
	cout << "myAge:\t" << myAge << "\t\tyourAge:\t" << yourAge << endl;
	cout << "&myAge:\t" << &myAge << "\t\t&yourAge:\t" << &yourAge << endl;
	
	cout << "pAge:\t" << pAge << endl;
	cout << "&pAge:\t" << *pAge << endl;

	cout << "\nReassigning: pAge= &yourAge..." << endl << endl;
	pAge = &yourAge; // Reassigning the pointer

	cout << "myAge:\t" << myAge << "\t\tyourAge:\t" << yourAge << endl;
	cout << "&myAge:\t" << &myAge << "\t\t&yourAge:\t" << &yourAge << endl;

	cout << "pAge:\t" << pAge << endl;
	cout << "&pAge:\t" << *pAge << endl;
}
void fifth() {
	int localVariable = 5;
	int * pLocal = &localVariable;
	// "new" tells the program that we want a cubbyhole in the heap for a value in the future
	int * pHeap = new int;
	// Assigning the value 7 to the mem adress specified in the line above
	*pHeap = 7;
	cout << "localVariable: " << localVariable << endl;
	cout << "*pLocal: " << *pLocal << endl;
	cout << "*pHeap: " << *pHeap << endl;
	// "delete" tell the program to change the value at the pointer to null
	delete pHeap;
	pHeap = new int;
	*pHeap = 9;
	cout << "*pHeap: " << *pHeap << endl;
	delete pHeap;
}
void sixth () {
	// Creating and Deleting Objects on the Free Store
	// SimpleCat defined at the top
	cout << "SimpleCat Jussi... " << endl;
	SimpleCat Jussi;
	cout << "SimpleCat *pRags = new SimpleCat..." << endl;
	SimpleCat* pRags = new SimpleCat;
	cout << "delete pRags..." << endl;
	delete pRags;
	cout << "Exiting, watch Jussi go... " << endl;
}
void seveth() {
	Cat* Jussi = new Cat;
	cout << "Jussi is " << Jussi->GetAge() << " year old" << endl;
	Jussi->SetAge(5);
	cout << "Jussi is " << Jussi->GetAge() << " year old" << endl;
	delete Jussi;
}
void ateh() {
	MemberCat *Jussi= new MemberCat;
	cout << "Jussi is " << Jussi->GetAge() << " years old " << endl;
	Jussi->SetAge(5);
	cout << "Jussi is " << Jussi->GetAge() << " years old " << endl;
	delete Jussi;
}
void ninth() {
	USHORT yourAge;
	USHORT* pAge = &yourAge;
	*pAge = 50;
	cout << *pAge << endl;
}
// Prog start
int main()
{
 
	int choice;
	cout << "Press number for function(1-8): ";
	cin >> choice;
	cout << endl;
	switch (choice) {
	case (1):
		first();
		break;
	case(2):
		sec();
		break;
	case(3):
		third();
		break;
	case(4):
		fourth();
		break;
	case(5):
		fifth();
		break;
	case(6):
		sixth();
		break;
	case(7):
		seveth();
		break;
	case(8):
		ateh();
		break;
	case(9):
		ninth();
		break;
	default:
		cout << "You really can't follow instructions, can you?" << endl;
	}
	
	return 0;
}

