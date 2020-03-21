
#include <iostream>
using namespace std;

// Functions
//default values
int add(int x = 1, int y = 2) {
    int sum = x + y;
    return sum;
}

// Program start
int main()
{
    // Running with defalut values
    cout << add() << endl;
    // Running with own values
    cout << add(4, 5) << endl;
return 0;
}