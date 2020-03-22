// Day 9 Exploiting Referenses
//

#include <iostream>
using namespace std;

class SimpleCat {
public:
    SimpleCat(int age, int weight);
    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }
private:
    int itsAge;
    int itsWeight;
};
SimpleCat::SimpleCat(int age, int weight) {
    itsAge = age;
    itsWeight = weight;
}

class Cat {
public:
    Cat();  //Constructor
    Cat(Cat&); //Copy Constructor
    ~Cat(); // Destructor
};
Cat::Cat() {
    cout << "Cat Constructor... " << endl;
}
Cat::Cat(Cat&) {
    cout << "Cat Copy Constructor" << endl;
}
Cat::~Cat() {
    cout << "Cat Destructor... " << endl;
}
Cat FunctionOne(Cat theCat);
Cat* FunctionTwo(Cat* theCat);

void first() {
    int intOne;
    int& rSomeRef = intOne;
    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;

    rSomeRef = 7;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;
}
void dos() {
    int intOne;
    int& rSomeRef = intOne;
    intOne = 5;
    cout << "intOne: " << intOne << endl;
    cout << "rSomeRef: " << rSomeRef << endl;
    cout << "&intOne: " << &intOne << endl;
    cout << "&rSomeRef: " << &rSomeRef << endl;
}
void tres() {
    SimpleCat Frisky(5, 8);
    SimpleCat& rCat = Frisky;
    cout << "Frisky is ";
    cout << Frisky.GetAge() << " years old." << endl;
    cout << "And Frisky weighs: ";
    cout << rCat.GetWeight() << " pounds." << endl;
}
void swap(int &rx, int &ry) {
    int temp;
    cout << "Swap. Before swap, rx: " << rx << " ry: " << ry << endl;
    temp = rx;
    rx = ry;
    ry = temp;
    cout << "Swap. After swap, rx: " << rx << " ry: " << ry << endl;
}
short FactorPointer(int n, int* pSquared, int* pCubed) {
    short Value = 0;
    if (n > 20)
        Value = 1;
    else {
        *pSquared = n * n;
        *pCubed = n * n * n;
        Value = 0;
    }
    return Value;
}
enum ERR_CODE { SUCCESS,ERROR};
ERR_CODE Factor(int, int&, int&);
int main()
{
    int choise;
    int x = 5, y = 10;
    cout << "enter the number of the case you want to run: ";
    cin >> choise;
    switch (choise) {
    case(1):
        first();
        break;
    case(2):
        dos();
        break;
    case(3):
        tres();
        break;
    case(4):
        cout << "Main. Before swap, x: "<< x << " y: "<< y << endl;
        swap(x, y);
        cout << "Main. After swap, x: " << x << " y: " << y << endl;
        break;
    case(5):
        int number, squared, cubed;
        short error;
        cout << "Enter a number (0-20): ";
        cin >> number;
        error = FactorPointer(number, &squared, &cubed);
        if (!error) {
            cout << "number: " << number << endl;
            cout << "square: " << squared << endl;
            cout << "cubed: " << cubed << endl;
        }
        else {
            cout << "Error encountered!!" << endl;
        }
        return 0;
        break;
    case(6):
        // Return Values by Reference
        int number2, squared2, cubed2;
        ERR_CODE resault;
        cout << "Enter a number (0-20): ";
        cin >> number2;
        resault = Factor(number2, squared2, cubed2);
        if (resault == SUCCESS) {
            cout << "number: " << number2 << endl;
            cout << "squared: " << squared2 << endl;
            cout << "cubed: " << cubed2 << endl;
        }
        else {
            cout << "Error encountered!!" << endl;
        }
        break;
    

    default:
        cout << "Instructions unclear" << endl;
        system("pause");
        break;
    }
    cout << "Making the cat... " << endl;
    Cat Frisky;
    cout << "Calling FuctionOne" << endl;
    FunctionOne(Frisky);
    cout << "calling FunctionTwo" << endl;
    FunctionTwo(&Frisky);
    

    return 0;
}

// Function definition
ERR_CODE Factor(int n, int& rSquared, int& rCubed) {
    if (n > 20)
        return ERROR;
    else {
        rSquared = n * n;
        rCubed = n * n * n;
        return SUCCESS;
    }
}

// FunctionOne, passed by value
Cat FunctionOne(Cat theCat) {
    cout << "FunctionOne. Returning..." << endl;
    return theCat;
}
// FunctionTwo, passed by reference
Cat* FunctionTwo(Cat* theCat) {
    cout << "FunctionTwo. Return..." << endl;
    return theCat;
}