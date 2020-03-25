#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
bool GetWord(char* theString, char* word, int& wordOffset);
int main(){
    const int bufferSize=255;
    char buffer[bufferSize+1];
    char word[bufferSize+1];
    int wordOffset = 0;

    cout << "Enter a string: ";
    cin.getline(buffer,bufferSize);

    while (GetWord(buffer, word, wordOffset))
    {
        cout<<"Got this word: "<<word<<endl;
    }
    return 0;
}

// function to parse words from a string.
bool GetWord(char* theString, char* word, int& wordOffset){
    if (theString[wordOffset]==0){
        return false;
    } //end of string?
    char *p1, *p2;
    p1=p2=theString+wordOffset; // point to the next word

    // eatr leading space
    for ( int i = 0; i < (int)strlen(p1) && !isalnum(p1[0]); i++)
    {
        p1++;
    }
    // see if you have a word
    if (!isalnum(p1[0])){
        return false;
    }
    // p1 now points to the start of the next word
    // point p2 there aswell
    p2=p1;
    //march p2 to the end of word
    while (isalnum(p2[0])){
        p2++;
    }
    // p2 is now at the end of word
    // p1 is at beginnihng of word
    // length of word is the difference
    int len = int (p2-p1);

    // copy the word into the buffer
    strncpy(word,p1,len);

    // null terminate it
    word[len]='\0';

    // now find the beginning of the next word
    for (int j = int(p2-theString); j < (int)strlen(theString) && !isalnum(p2[0]); j++)
    {
        p2++;
    }
    wordOffset = int(p2-theString);
    return true;
}
