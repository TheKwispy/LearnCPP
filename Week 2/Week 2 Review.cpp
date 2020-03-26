#include<iostream>
using namespace std;

// *** Part ***
// Abstract base class of parts
class Part
{
private:
    int itsPartNumber;
public:
    Part():itsPartNumber(1){}
    Part(int PartNumber):itsPartNumber(PartNumber){}
    virtual ~Part(){};
    int GetPartNumber() const {return itsPartNumber;}
    virtual void Display()const = 0; // Must be overridden
};
void Part::Display() const{
    cout << "\nPart Number: "<<itsPartNumber << endl;
}

// *** Car Part ***
class CarPart : public Part
{
private:
    int itsModelYear;
public:
    CarPart():itsModelYear(94){}
    CarPart(int year, int partNumber);
    virtual void Display() const {
        Part::Display(); 
        cout<<"Model Year: " << itsModelYear << endl;
    }
};

CarPart::CarPart(int year, int partNumber):
    itsModelYear(year),
    Part(partNumber)
{}

// *** AirPlane Part ***
class AirPlanePart : public Part
{
private:
    int itsEngineNumber;
public:
    AirPlanePart():itsEngineNumber(1){};
    AirPlanePart(int EngineNumber, int PartNumber);
    virtual void Display() const {
        Part::Display();
        cout << "Engine No.: " << itsEngineNumber << endl;
    }
};

AirPlanePart::AirPlanePart(int EngineNumber, int PartNumber):
    itsEngineNumber(EngineNumber),
    Part(PartNumber)
{}

// *** Part Node ***
class PartNode
{
private:
    Part *itsPart;
    PartNode * itsNext;
public:
    PartNode(Part*);
    ~PartNode();
    void SetNext(PartNode * node){itsNext = node;}
    PartNode * GetNext() const;
    Part * GetPart() const;
};
// PartNode Implementations...

PartNode::PartNode(Part* pPart):
    itsPart(pPart),
    itsNext(0)
{}

PartNode::~PartNode()
{
    delete itsPart;
    itsPart = 0;
    delete itsNext;
    itsNext = 0;
}

// Returns NULL if no next PartNode

PartNode * PartNode::GetNext() const {
    return itsNext;
}
Part * PartNode::GetPart() const {
    if (itsPart){
        return itsPart;
    } else {
        return NULL; // error
    }
}

// *** Part List ***
class PartsList
{
private:
    PartNode * pHead;
    int itsCount;
public:
    PartsList();
    ~PartsList();
    // needs copy constructor and operator equals!
    Part* Find(int & position, int PartNumber) const;
    int GetCount() const {return itsCount;}
    Part* GetFirst() const;
    void Insert(Part*);
    void Iterate() const;
    Part* operator[](int) const;
};
// Implementation for Lists...
PartsList::PartsList():
pHead(0),
itsCount(0)
{}

PartsList::~PartsList() { delete pHead; }

Part* PartsList::GetFirst() const{
    if (pHead){
        return pHead->GetPart();
    } else {
        return NULL; // error catch here
    }
}

Part * PartsList::operator[](int offSet) const {
    PartNode * pNode = pHead;
    if (!pHead){
        return NULL; // Error catch here
    }
    if (offSet>itsCount){
        return NULL; // Error
    }
    for (int i = 0; i < offSet; i++)
    {
        pNode=pNode->GetNext();
    }
    return pNode->GetPart();
}

Part* PartsList::Find(int & position, int PartNumber) const {
    PartNode * pNode=0;
    for (pNode = pHead, position=0; 
        pNode!=NULL; 
        pNode = pNode->GetNext(), position++)
        {
        if (pNode->GetPart()->GetPartNumber() == PartNumber)
            break;
            }
        if (pNode == NULL)
            return NULL;
         else 
            return pNode->GetPart();
}

void PartsList::Iterate() const{
    if (!pHead){
        return;
    }
    PartNode* pNode = pHead;
    do
    {
        pNode->GetPart()->Display();
    } while (pNode = pNode->GetNext());    
}

void PartsList::Insert(Part* pPart){
    PartNode * pNode = new PartNode(pPart);
    PartNode * pCurrent = pHead;
    PartNode * pNext = 0;

    int New = pPart->GetPartNumber();
    int Next=0;
    itsCount++;

    if (!pHead){
        pHead = pNode;
        return;
    }
    // if this one is smaller than head
    // this one is the new head
    if (pHead->GetPart()->GetPartNumber() > New){
        pNode->SetNext(pHead);
        pHead = pNode;
        return;
    }
    for (;;){
        //if there is no next, append this new one
        if (!pCurrent->GetNext()){
            pCurrent->SetNext(pNode);
            return;
        }
        // if this goes after this one and before the next
        // then insert it here, otherwise get the next
        pNext=pCurrent->GetNext();
        Next = pNext->GetPart()->GetPartNumber();
        if (Next>New){
            pCurrent->SetNext(pNode);
            pNode->SetNext(pNext);
            return;
        }
        pCurrent=pNext;
    }
}

int main() {
    PartsList pl;
    Part* pPart=0;
    int PartNumber;
    int value;
    int choice = 99;

    while (choice != 0){
        cout << "(0)Quit (1)Car (2)Plane: ";
        cin >> choice;

        if (choice!=0){
            cout << "New PartNumber?: ";
            cin >> PartNumber;

            if (choice ==1){
                cout << "Model Year?: ";
                cin >> value;
                pPart = new CarPart(value,PartNumber);
            } else {
                cout << "Engine Number?: ";
                cin >> value;
                pPart=new AirPlanePart(value, PartNumber);
            }
            pl.Insert(pPart);
        }
    }
    pl.Iterate();
    return 0;
}