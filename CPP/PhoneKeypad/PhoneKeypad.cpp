#include <iostream>
#include "cstring"
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void printString(char *in, char *out, int i, int j){
    //Base 
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //Rec
    int digit = in[i]-'0';
    if(digit == 1 || digit == 0){
        printString(in,out,i+1,j);
    }
    for(int k=0; keypad[digit][k]!='\0'; k++){
        out[j] = keypad[digit][k];
        printString(in,out,i+1,j+1);
    }
}

int main(){

    char in[100];
    char out[100];
    cin>>in;
    printString(in,out,0,0);
    return 0;
}