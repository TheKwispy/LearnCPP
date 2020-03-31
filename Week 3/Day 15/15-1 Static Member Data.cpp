#include<iostream>
using namespace std;

class Cat
{
private:
    int itsAge;
public:
    Cat(int age):itsAge(age){HowManyCats++;}
    virtual ~Cat() {HowManyCats--;}
    virtual int GetAge() const {return itsAge;}
    virtual void SetAge(int age) {itsAge=age;}
    static int HowManyCats;
};

int Cat::HowManyCats=0;

int main(){
    const int MaxCats=5; int i;
    Cat *CatHouse[MaxCats];

    for (int i = 0; i < MaxCats; i++)
    {
        CatHouse[i] = new Cat(i);
    }
    
    for (int i = 0; i < MaxCats; i++)
    {
        cout << "Thera are " << Cat::HowManyCats << " cats left!"<<endl;
        cout << "Deleting the one that is "<<CatHouse[i]->GetAge() << " years old"<<endl;
        delete CatHouse[i];
        CatHouse[i]=0;
    }
    return 0;
}