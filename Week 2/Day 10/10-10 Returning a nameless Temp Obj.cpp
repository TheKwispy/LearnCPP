#include<iostream>
using namespace std;
class Counter {
public:
	Counter();
	//Changes here
	Counter(int val);
	~Counter() {}
	int GetItsVal()const { return itsVal; }
	void SetItsVal(int x) { itsVal = x; }
	void Increment() { ++itsVal; }
	Counter operator++();
private:
	int itsVal;
};
Counter::Counter():
	itsVal(0)
{}
// Here
Counter::Counter(int val):
	itsVal(val)
{}
Counter Counter::operator++() {
	// And here
	++itsVal;
	// inits a temp Counter object to the value itsVal then returned as the res of the operator++
	return Counter(itsVal);
}
int main() {
	Counter i;
	int resI = i.GetItsVal();
	cout << "The value of i is " << resI << endl;
	i.Increment();
	resI = i.GetItsVal();
	cout << "The value of i is " << resI << endl;
	++i;
	resI = i.GetItsVal();
	cout << "The value of i is " << resI << endl;
	Counter a = ++i;
	resI = i.GetItsVal();
	int resA = a.GetItsVal();
	cout << "The value of a: " << resA;
	cout << " and i: " << resI << endl;
	return 0;
}