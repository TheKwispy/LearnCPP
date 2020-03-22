#include<iostream>
using namespace std;
class Counter {
public:
	Counter();
	Counter(int val);
	~Counter(){}
	int GetItsVal()const { return itsVal; }
	void SetItsVal(int x) { itsVal = x; }
private:
	int itsVal;
};
Counter::Counter():
	itsVal(0){}
Counter::Counter(int val):
	itsVal(val){}


int main() {
	int theInt = 5;
	Counter theCtr = theInt;
	cout << "theCtr: " << theCtr.GetItsVal() << endl;
	return 0;
}