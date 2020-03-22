#include<iostream>
using namespace std;
class Counter {
public:
	Counter();
	~Counter() {}
	int GetItsVal()const { return itsVal; }
	void SetItsVal(int x) { itsVal = x; }
	// Listing 10.7
	void Increment() { ++itsVal; }
	// Listing 10.9
	Counter operator++();
private:
	int itsVal;
};
Counter::Counter():
	itsVal(0)
{}
// Listing 10.9
Counter Counter::operator++() {
	++itsVal;
	Counter temp;
	temp.SetItsVal(itsVal);
	return temp;
}
int main() {
	Counter i;
	int resI = i.GetItsVal();
	cout << "The value of i is " << res << endl;
	i.Increment();
	resI = i.GetItsVal();
	cout << "The value of i is " << res << endl;
	++i;
	resI = i.GetItsVal();
	cout << "The value of i is " << res << endl;
	Counter a = ++i;
	resI = i.GetItsVal();
	int resA = a.GetItsVal();
	cout << "The value of a: " << resA;
	cout << " and i: " << resI << endl;
	return 0;
}