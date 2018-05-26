#include "iostream"
using namespace std;
int sum=0;
int steps(int n){
    if(n==0){
        return 1;
    }
    else if(n<0){
        return 0;
    }
    // for(int x=1;x<=3;x++){
    //     return steps(n-x);
    // }
    return steps(n-1)+steps(n-2)+steps(n-3);
}

int main(){
    int n;
    cin>>n;
    cout<<steps(n);
    return 0;
}