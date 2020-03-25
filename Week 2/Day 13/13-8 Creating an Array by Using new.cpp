#include<iostream>
using namespace std;
class Cat
{
private:
    int itsAge;
    int itsWeight;
public:
    Cat(){itsAge=1;itsWeight=5;}
    ~Cat(){/*cout << "Destructor called"<<endl;*/}
    int GetAge() const{return itsAge;}
    int GetWeight() const {return itsWeight;}
    void SetAge(int age){itsAge = age;} 
};
int main(){
    Cat * Family = new Cat[500];
    int i;
    for (int i = 0; i < 500; i++)
    {
        Family[i].SetAge(2*i+1);
    }
    for (int i = 0; i < 500; i++)
    {
        cout << "Cat #"<<i+1<<": "<<Family[i].GetAge() << endl;
    }
    delete [] Family;
    return 0;
}