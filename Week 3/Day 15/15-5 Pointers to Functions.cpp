/* Left over from C before OOP was a thing*/

#include <iostream>
using namespace std;

void Square(int&, int&);
void Cube (int&, int&);
void Swap(int&, int&);
void GetVals(int&, int&);
void PrintVals(int, int);

int main(){
    void (* pFunc) (int &, int &);
    bool fQuit = false;

    int valOne=1, valTwo=2;
    int choice;
    while(fQuit == false){
        cout << "(0)Quit (1)Change Values (2)Square (3)Cube (4)Swap: ";
        cin >> choice;
        switch (choice)
        {
        case 1: pFunc=GetVals;break;
        case 2: pFunc=Square;break;
        case 3: pFunc=Cube;break;
        case 4: pFunc=Swap;break;
        default: fQuit= true; break; 
        }
        if (fQuit==false){
            PrintVals(valOne, valTwo);
            pFunc(valOne, valTwo);
            PrintVals(valOne,valTwo);
        }
    }
    return 0;
}

void PrintVals(int x, int y){
    cout << "x: " << x << " y: " << y << endl;
}
void Square (int & rX, int & rY){
    rX*=rX;
    rY*=rY;
}
void Cube (int & rX, int & rY){
    int temp;
    
    temp=rX;
    rX*=rX;
    rX=rX*temp;

    temp=rY;
    rY*=rY;
    rY=rY*temp;
}
void Swap(int & rX, int & rY){
    int temp;
    temp = rX;
    rX=rY;
    rY=temp;
}
void GetVals(int & rValOne, int & rValTwo){
    cout << "New value for ValOne: ";
    cin >> rValOne;
    cout << "New value for ValTwo: ";
    cin >> rValTwo;
}