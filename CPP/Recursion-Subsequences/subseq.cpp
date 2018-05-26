#include <iostream>
using namespace std;

void subSequences(char *in, char *out, int i, int j){
    //Base Case
    if(in[i]=='\0'){
        out[j] = '\0';
        cout<<out<<", "<<endl;
        return;
    }

    //Rec case

    //1. Include current character
    out[j] = in[i];
    subSequences(in,out,i+1,j+1);

    //2.Exclude current character
    subSequences(in,out,i+1,j);
}

int main(){

    char in[100];
    cin>>in;

    char out[100];
    subSequences(in,out,0,0);

}