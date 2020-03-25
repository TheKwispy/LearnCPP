#include<iostream>
using namespace std;

class Cat
{
private:
    int itsAge;
    int itsWeight;
public:
    Cat(){itsAge = 1; itsWeight=5;}
    ~Cat(){}
    int GetAge()const{return itsAge;}
    int GetWeight() const{return itsWeight;}
    void SetAge(int age){ itsAge = age;}
};
int main(){
    Cat * Family[500];
    int i;
    Cat * pCat;
    for ( i = 0; i < 500; i++)
    {
        pCat=new Cat;
        pCat->SetAge(2*i+1);
        Family[i]=pCat;
    }
    for ( i = 0; i < 500; i++)
    {
        cout << "Cat #" << i+1<<": "<<Family[i]->GetAge() << endl;
    }
    return 0;
    
}