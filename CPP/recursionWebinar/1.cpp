#include "iostream"
using namespace std;

void generateStrings(char *a, int i, char *out, int j){
    //base
    if(a[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    //current digit
    int digit = a[i] - '0';
    char ch = digit + 64;
    out[j] = ch;
    generateStrings(a,i+1,out,j+1);

    //two digits case
    if(a[i+1]!='\0'){
        int digit2 = a[i+1] - '0';
        int no = digit*10 + digit2;
        if(no<=26){
            ch = no + 64;
            out[j] = ch;
            generateStrings(a,i+2,out,j+1);
        }

    }

}


int main(){
    char in[100];
    cin>>in;

    char out[100];

    generateStrings(in, 0, out, 0);
    return 0;
}