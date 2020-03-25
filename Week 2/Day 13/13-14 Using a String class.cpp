#include<iostream>
#include<string.h>
using namespace std;

// Rudimentary string class
class String
{
private:
    String (unsigned short);
    char * itsString;
    unsigned short itsLen;
public:
    String();
    String(const char *const);
    String(const String &);
    ~String();

    // Overloaded Operators
    char & operator[](unsigned short offset);
    char operator[](unsigned short offset) const;
    String operator+(const String&);
    void operator+=(const String&);
    String & operator=(const String &);
    // General Accessors
    unsigned short GetLen()const{return itsLen;}
    const char * GetString() const {return itsString;}
};
// Default constructor creates a string of 0 bytes
String::String()
{
    itsString=new char[1];
    itsString[0]='\0';
    itsLen=0;
}
// Private (helper) constructor, used only by class methods for creating new
// string of required size. Null filled.
String::String(unsigned short len){
    itsString=new char[len+1];
    for (unsigned short i=0;i<=len;i++){
        itsString[i]= '\0';
    }
    itsLen=len;
}
// Converts a character array into a String
String::String(const char * const cString){
    itsLen = strlen(cString);
    itsString = new char[itsLen+1];
    for (unsigned short i = 0; i<itsLen;i++){
        itsString[i]=cString[i];
    }
    itsString[itsLen]='\0';
}
// Copy Constructor
String::String(const String & rhs){
    itsLen= rhs.GetLen();
    itsString = new char[itsLen+1];
    for (unsigned short i = 0; i<itsLen; i++){
        itsString[i]=rhs[i];
    }
    itsString[itsLen]='\0';
}
// Destructor, free allocated memory
String::~String()
{
    delete [] itsString;
    itsLen=0;
}
// Operator equals, frees existing memory
// Then copies string and size
String& String::operator=(const String & rhs){
    if (this == &rhs){
        return *this;
    }
    delete [] itsString;
    itsLen=rhs.GetLen();
    itsString= new char[itsLen+1];
    for (unsigned short i = 0; i<itsLen;i++){
        itsString[i]=rhs[i];
    }
    itsString[itsLen]='\0';
    return *this;
}
// nonoconstant offset operator, returns reference to character so it can be changed!
char & String::operator[](unsigned short offset){
    if (offset>itsLen){
        return itsString[itsLen-1];
    } else {
        return itsString[offset];
    }
}

// constant offset operator for use on const objects (see copy constructor!)
char String::operator[](unsigned short offset) const {
    if (offset>itsLen){
        return itsString[itsLen-1];
    } else {
        return itsString[offset];
    }
}
// creates a new string by adding current string to rhs
String String::operator+(const String& rhs){
    unsigned short totalLen=itsLen + rhs.GetLen();
    String temp(totalLen);
    unsigned short i;
    for (i=0; i<itsLen; i++){
        temp[i]= itsString[i];
    }
    for (unsigned short j = 0; j<rhs.GetLen(); j++, i++){
        temp[i]= rhs[j];
    }
    temp[totalLen]='\0';
    return temp;
}
// Changes current string, return nothing
void String::operator+=(const String& rhs){
    unsigned short rhsLen=rhs.GetLen();
    unsigned short totalLen=itsLen + rhsLen;
    String temp(totalLen);
    unsigned short i;
    for (i = 0; i < itsLen; i++)
    {
        temp[i]=itsString[i];
    }
    for (unsigned short j=0;j<rhs.GetLen();j++, i++){
        temp[i]=rhs[i-itsLen];
    }
    temp[totalLen]= '\0';
    *this = temp;
}

int main(){
    String s1("initial test");
    cout << "S1:\t"<<s1.GetString()<< endl;

    char * temp = "Hello World";
    s1 = temp;
    cout << "S1:\t"<<s1.GetString() << endl;

    char tempTwo[20];
    strcpy(tempTwo,"; nice to be here!");
    s1+=tempTwo;
    cout << "tempTwo:\t"<<tempTwo << endl;
    cout << "S1:\t"<<s1.GetString()<<endl;

    cout << "S1[4]:\t"<<s1[4]<<endl;
    s1[4]='x';
    cout << "S1:\t"<<s1.GetString()<<endl;

    cout << "S1[999]:\t"<< s1[999] << endl;

    String s2(" Another string");
    String s3;
    s3 = s1+s2;
    cout << "S3:\t"<<s3.GetString()<<endl;
    
    String s4;
    s4 ="Why does this work?";
    cout << "S4:\t"<<s4.GetString() << endl;
    return 0;

}