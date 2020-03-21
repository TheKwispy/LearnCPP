
#include <iostream>
using namespace std;


int main()
{
    // While loop, if you use while(true) make sure to set an if statement with a "break;" when the condition you're looping is complete
    
    int counter;
    cout << "How many hellos?" << endl;
    cin >> counter;
    do {
        cout << "Hello" << endl;
        counter--;
    } while (counter > 0);
    cout << "Aah General Kenobi" << endl;
    
    // do-while loop, makes sure the statement is run atleast once
    
    cout << "Printing alphabet with a do-while loop" << endl;
    char ch = 'a';
    do {
        cout << ch << " ";
        ch++;
    } while (ch <= 'z');
    cout << "\n";
    system("pause");

    // For loop this time
    
    int antal;
    for (antal = 0; antal < 5; antal++)
        cout << "Hello there! " << endl;
    cout << "Antal: " << antal << endl;
    system("pause");

    // For loop with multiple statements
    for (int i = 0, j = 0; i < 3; i++, j++)
        cout << "i:" << i << " j:" << j << endl;

    // null in for loop

    int counter2 = 0;
    for (; counter2 < 5; ) {
        counter2++;
        cout << "Looping! ";
    }
    cout << "\nCounter: " << counter2 << endl;
    system("pause");

    // Empty for loop

    int counter3=0;
    int max;
    cout << "How many hellos this time: ";
    cin >> max;
    for (;;) {
        if (counter3 < max) {
            cout << "Hello!" << endl;
            counter3++;
        }
        else {
            break;
        }
    }
    system("pause");
    
    // Nesting loops
    
    int rows, columns;
    char theChar;
    cout << "How many rows? ";
    cin >> rows;
    cout << "How many columns? ";
    cin >> columns;
    cout << "What char to use? ";
    cin >> theChar;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << theChar;
            
        }
        cout << endl;
    }
    system("pause");

    // Switch statment

    unsigned short int number;
    cout << "Enter a number between 1 and 5: ";
    cin >> number;
    switch (number) {
    case 0: cout << "Too smoll";
        break;
    case 5: cout << "Nice" << endl;
    case 4: cout << "Nice" << endl;
    case 3: cout << "Nice" << endl;
    case 2: cout << "Nice" << endl;
    case 1: cout << "Nice" << endl;
        break;
    default: cout << "It's too big." << endl;
        break;
    }
    
    return 0;
}

