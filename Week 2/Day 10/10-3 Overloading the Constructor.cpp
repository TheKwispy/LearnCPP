#include<iostream>
using namespace std;

class Rectangle {
public:
	Rectangle();
	Rectangle(int width, int length);
	~Rectangle(){}
	int GetWidth() const { return itsWidth; }
	int GetLength() const { return itsLength; }
private:
	int itsWidth;
	int itsLength;
};
// Definging methods
// Constructor - no args
Rectangle::Rectangle() {
	itsWidth = 5;
	itsLength = 10;
}
// Constructor - with args
Rectangle::Rectangle(int width, int lenght) {
	itsWidth = width;
	itsLength = lenght;
}

int main() {
	Rectangle Rect1;
	/* Due to compiler to printing out the 
	"cout << "Rect1 width: " << Rect1.GetWidth()<< endl;" 
	propperly so I had to assign the values to new int variables*/
	int Rect1W = Rect1.GetWidth();
	int Rect1L = Rect1.GetLength();
	cout << "Rect1 width: " << Rect1W << endl;
	cout << "Rect1 length: " << Rect1L<< endl;
	// Getting values from user for the second Rect
	int aWidth, aLength;
	cout << "Enter a width: ";
	cin >> aWidth;
	cout << endl << "Enter a length: ";
	cin >> aLength;
	Rectangle Rect2(aWidth, aLength);
	int Rect2W = Rect2.GetWidth();
	int Rect2L = Rect2.GetLength();
	cout << endl << "Rect2 width: " << Rect2W << endl;
	cout << "Rect2 length: " << Rect2L << endl;

	return 0;
}