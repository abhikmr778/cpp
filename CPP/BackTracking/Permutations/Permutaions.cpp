#include <iostream>
#include "algorithm"
using namespace std;

string ans[100];
int z=0;

void noPermutes(string s){
    int n = s.length();
    int no=1;
    for(int x=0;x<n;x++){
        no*=(n-x);
    }
    cout<<no<<endl;
}
void permute(string a, int i){
    //Base
    if(a[i]=='\0'){
        ans[z++] = a;
        return;
    }
    //Recursive
    for(int j=i; a[j]!='\0'; j++){
        swap(a[i], a[j]);
        permute(a, i+1);

        //Backtracking
        swap(a[i],a[j]);
    }

}

int main(){
    string str;
    cin>>str;
    noPermutes(str);
    permute(str, 0);
    
    sort(ans,ans+z);
    for(int x=0;x<z;x++){
        cout<<ans[x]<<" ";
    }
    return 0;

}