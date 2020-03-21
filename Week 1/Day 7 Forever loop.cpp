#include <iostream>
using namespace std;

// Prototypes
int menu();
void DoTaskOne();
void DoTaskMany(int);

int main()
{
    bool exit = false;
    for (;;)
    {
        int choise = menu();
        switch (choise) {
        case (1):
            DoTaskOne();
            break;
        case(2):
            DoTaskMany(2);
            break;
        case(3):
            DoTaskMany(3);
            break;
        case(4):
            continue;
            break;
        case (5):
            exit = true;
            break;
        default:
            cout << "Please select again!" << endl;
            break;
        }                   // End switch
        if (exit == true) {
            break;
        }
    }                       // End forever loop
    return 0;
}                           // End main

// Function Specs
int menu() {
    int choise;
    cout << "**** Menu ****" << endl;
    cout << "(1) Choise One." << endl;
    cout << "(2) Choise Two." << endl;
    cout << "(3) Choise Three." << endl;
    cout << "(4) Redisplay menu." << endl;
    cout << "(5) Quit." << endl;
    cout << ": ";
    cin >> choise;
    return choise;
}

void DoTaskOne() {
    cout << "Task One!" << endl;
}

void DoTaskMany(int which) {
    if (which == 2) {
        cout << "Task Two!" << endl;
    }
    else {
        cout << "Task Three!" << endl;
    }
}