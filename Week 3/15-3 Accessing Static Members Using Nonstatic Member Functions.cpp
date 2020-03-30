#include<iostream>
using namespace std;

class Cat
{
private:
    int itsAge;
    static int HowManyCats;
public:
    Cat(int age):itsAge(age){HowManyCats++;}
    virtual ~Cat(){HowManyCats--;}
    virtual int GetAge() {return itsAge;}
    virtual void SetAge(int age){itsAge=age;}
    virtual int GetHowMany(){return HowManyCats;}
};

int Cat::HowManyCats=0;

int main(){
    const int MaxCats=5; int i;
    Cat *CatHouse[MaxCats];

    for (i=0;i<MaxCats;i++){
        CatHouse[i]=new Cat(i);
    }
    for (i=0;i<MaxCats;i++){
        cout << "There are " << CatHouse[i]->GetHowMany()<<" cats left"<< endl;
        cout << "Deleting the one that is "<<CatHouse[i]->GetAge()+2 << " years old"<< endl;
        delete CatHouse[i];
        CatHouse[i]=0;
    }
    return 0;
}