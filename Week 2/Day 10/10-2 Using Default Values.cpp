#include<iostream>
using namespace std;
// Rectangle class declaration
class Rectangle {
public:
	//constructors
	Rectangle(int width, int height);
	~Rectangle(){}
	void DrawShape(int aWidth, int aHeight, bool UseCurrentVals = false) const;
private:
	int itsWidth;
	int itsHeight;
};
// Constructor implementation
Rectangle::Rectangle(int width, int height):
	itsWidth(width),	//initializations
	itsHeight(height) 
{}						// empty body

// Default values used for third param
void Rectangle::DrawShape(int width, int height, bool UseCurrentValues) const {
	int printWidth;
	int printHeight;
	if (UseCurrentValues == true) {
		printWidth = itsWidth;	// Use Current class value
		printHeight = itsHeight;
	}
	else {
		printWidth = width;		// Use param values
		printHeight = height;
	}
	for (int i = 0; i < printHeight; i++) {
		for (int j = 0; j < printWidth; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

// Driver program to demo overloaded function
int main() {
	// initing a rectangle to 30,5
	Rectangle theRect(30, 5);
	cout << "DrawShape(0,0,true)..." << endl;
	theRect.DrawShape(0, 0, true);
	cout << "DrawShape(40,2)... " << endl;
	theRect.DrawShape(40, 2);
	return 0;
}