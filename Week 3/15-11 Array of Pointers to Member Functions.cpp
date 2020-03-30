#include<iostream>
using namespace std;

class Dog{
    public:
    void Speak()const{cout << "Woof!"<<endl;}
    void Move() const {cout << "Walking to heel..."<<endl;}
    void Eat() const{ cout << "Gobbling food..."<<endl;}
    void Growl() const {cout << "Grrrr"<<endl;}
    void Whimper() const {cout << "Whining noices..."<<endl;}
    void RollOver() const {cout << "Rolling over... "<<endl;}
    void PlayDead() const {cout << "The end of Little Ceasar?" << endl;}
};
typedef void (Dog::*PDF)()const;
int main(){
    const int MaxFuncs=7;
    PDF DogFunctions[MaxFuncs] = {
        Dog::Speak,
        Dog::Move,
        Dog::Eat,
        Dog::Growl,
        Dog::Whimper,
        Dog::RollOver,
        Dog::PlayDead };

    Dog* pDog=0;
    int Method;
    bool fQuit = false;
    while (fQuit == false){
        cout << "(0)Quit (1)Speak (2)Move (3)Eat (4)Growl\n(5)Whimper (6)Roll Over (7)Play Dead: ";
        cin >> Method;
        if (Method<=0 || Method >=8){
            fQuit = true;
        } else {
            pDog = new Dog;
            (pDog->*DogFunctions[Method-1])();
            delete pDog;
        }
    }
    return 0;
}