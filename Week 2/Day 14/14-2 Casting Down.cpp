#include<iostream>
using namespace std;

enum TYPE {HORSE,PEGASUS};

class Horse
{
protected:
    int itsAge;
public:
    virtual void Gallop(){cout << "Galloping...\n";}
};
class Pegasus : public Horse{
public:
virtual void Fly(){ cout << "I can fly! I can fly! I can fly!";}
};
const int NumberHorses=5;
int main(){
    Horse *Ranch[NumberHorses];
    Horse* pHorse;
    int choice, i;
    for (i=0; i< NumberHorses;i++){
        cout << "(1)Horse (2)Pegasus: ";
        cin >> choice;
        if (choice == 2){
            pHorse = new Pegasus;
        } else {
            pHorse=new Horse;
        }
        Ranch[i]= pHorse;
    }
    cout << endl;
    for (i=0; i < NumberHorses;i++){
        Pegasus *pPeg = dynamic_cast< Pegasus *> (Ranch[i]);
        if (pPeg != NULL){
            pPeg->Fly();
        } else {
            cout << "Just a horse\n";
        }
        delete Ranch[i];
    }
    return 0;
}