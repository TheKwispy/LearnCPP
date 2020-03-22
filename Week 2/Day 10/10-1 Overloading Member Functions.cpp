#include <iostream>
using namespace std;

// Class Declaration
class Rectangle {
public:
	//constructor
	Rectangle(int width, int height);
	~Rectangle(){}

	//Overload class function DrawShape
	void DrawShape() const;
	void DrawShape(int aWidth, int aHeight) const;
private:
	int itsWidth;
	int itsHeight;
};

// Constructor implementation
Rectangle::Rectangle(int width, int height) {
	itsWidth = width;
	itsHeight = height;
}

/* Overload DrawShape - takes no value
Draws based on current class member values*/
void Rectangle::DrawShape() const {
	// This calls the second function but passes the values from the object, thus using the default values specified when creating the object.
	DrawShape(itsWidth, itsHeight);
}
/*Overloaded DrawShape - takes two values
Draws shape based on the parameters*/
void Rectangle::DrawShape(int width, int height) const {
	// simple for loop that as long as i is smaller than the given height, it runs the second loop
	// When j is no longer smaller than the given width it goes to the next section (which is back in the first loop)
	// The first loop then ends the line and then loops back to the start of the first loop
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << "*";
		}
		cout << endl;
	}
}
// Driver program to demo overloaded functions
int main() {
	// Initialize a rectangle to 30 width and 5 height
	Rectangle theRect(30, 5);
	cout << "DrawShape():" << endl;
	// Activates the function that uses the args defined when creating the object
	theRect.DrawShape();
	cout << endl << "DrawShape (40,2):" << endl;
	// Activates the overloaded function that takes to args
	theRect.DrawShape(40, 2);
	return 0;
}