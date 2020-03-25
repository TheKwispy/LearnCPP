#include<iostream>
using namespace std;
class Cat{
private:
    int itsAge;
    int itsWeight;
public:
    Cat() {itsAge=1; itsWeight=5;}
    ~Cat(){}
    int GetAge() const { return itsAge;}
    int GetWeight() const { return itsWeight;}
    void SetAge(int age) { itsAge=age;}
};

int main(){
    Cat Litter[5];
    int i;
    for (i=0; i<5; i++){
        Litter[i].SetAge(2*i+1);
    }
    for(i=0;i<5;i++){
        cout << "Cat #"<<i<<": " << Litter[i].GetAge()<<endl;
    }
    return 0;
}
