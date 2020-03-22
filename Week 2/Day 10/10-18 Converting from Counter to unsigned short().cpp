#include<iostream>
using namespace std;
class Counter {
public:
	Counter();
	Counter(int val);
	~Counter() {}
	int GetItsVal()const { return itsVal; }
	void SetItsVal(int x) { itsVal = x; }
	operator unsigned int();
private:
	int itsVal;
};
Counter::Counter() :
	itsVal(0) {}
Counter::Counter(int val) :
	itsVal(val) {}
Counter::operator unsigned int() {
	return (int(itsVal));
}

int main() {
	Counter ctr(5);
	int theInt = ctr;
	cout << "theInt: " << theInt << endl;
	return 0;
}