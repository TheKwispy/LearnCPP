#include<iostream>
using namespace std;
int main(){
    int AllocationSize=5;
    int *pArryOfNumbers= new int[AllocationSize];
    int ElementsUsedSoFar=0;
    int MaximumElementsAllowed=AllocationSize;
    int InputNumber = -1;
    
    cout << endl << "Next number = ";
    cin >> InputNumber;

    while(InputNumber>0){
        pArryOfNumbers[ElementsUsedSoFar++]=InputNumber;
        if ( ElementsUsedSoFar == MaximumElementsAllowed){
            int *pLargerArray=new int[MaximumElementsAllowed+AllocationSize];
        
        for (int CopyIndex = 0; CopyIndex < MaximumElementsAllowed; CopyIndex++)
        {
            pLargerArray[CopyIndex]=pArryOfNumbers[CopyIndex];
        };
        delete [] pArryOfNumbers;
        pArryOfNumbers=pLargerArray;
        MaximumElementsAllowed += AllocationSize;
        };
        cout << endl << "Next number = ";
        cin >> InputNumber;
    }
    for (int Index = 0; Index < ElementsUsedSoFar; Index++)
    {
        cout << pArryOfNumbers[Index] << endl;
    }
    return 0;
}