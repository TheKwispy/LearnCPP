#include <iostream>
using namespace std;
int main(){
    char buffer[80];
    cout<<"Enter a string: ";
    cin.get(buffer,79);         //get up to 79 or newline
    cout << "Here's the buffer: "<<buffer<<endl;
    return 0;
}