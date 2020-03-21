#include <iostream>
using namespace std;
int main()
{
    enum Days { Monday, Tuesdat, Wednesday, Thursday, Friday, Saturday, Sunday};
    Days today;
    today = Monday;

    if (today == Saturday || today == Sunday)
        cout << "Gotta love the weekend" << endl;
    else
        cout << "Back to work" << endl;
    system("pause");
    return 0;
}

