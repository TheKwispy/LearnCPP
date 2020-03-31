#include<iostream>
using namespace std;

class Mammal
{
protected:
    int itsAge;
public:
    Mammal():itsAge(1){}
    virtual ~Mammal(){}
    virtual void Speak() const = 0;
    virtual void Move() const = 0;
};

class Dog : public Mammal
{
public:
    void Speak() const {cout << "Woof!"<<endl;}
    void Move() const { cout << "Walking to heel..."<<endl;}
};
class Cat : public Mammal
{
public:
    void Speak() const {cout << "Meow!"<<endl;}
    void Move() const {cout << "Sneaking..."<<endl;}
};
class Horse : public Mammal
{
public:
    void Speak() const {cout << "Whinnie!"<<endl;}
    void Move() const { cout << "Galloping..."<<endl;}
};

int main() {
    void (Mammal::*pFunc)()const = 0;
    Mammal* ptr = 0;
    int Animal;
    int Method;
    bool fQuit= false;

    while (fQuit == false){
        cout << "(0)Quit (1)dog (2)cat (3)horse: ";
        cin >> Animal;
        switch (Animal)
        {
        case 1: ptr = new Dog; break;
        case 2: ptr = new Cat; break;
        case 3: ptr = new Horse; break;
        default: fQuit = true; break;
        }
        if (fQuit == false){
            cout <<"(1)Speak    (2)Move: ";
            cin >> Method;
            switch(Method){
                case 1: pFunc = Mammal::Speak; break;
                default: pFunc = Mammal::Move; break;
            }
            (ptr->*pFunc)();
            delete ptr;
        }
    }
    return 0;
}
