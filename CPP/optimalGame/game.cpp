#include <iostream>
using namespace std;

int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int min(int a, int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}

int optimise(int i, int j, int *arr){
    if(j==i){
        return arr[i];
    }
    else if(j==i+1){
        return max(arr[i],arr[j]);
    }
    return max( (arr[i] + min(optimise(i+2,j, arr),optimise(i+1, j-1, arr))), arr[j] + min(optimise(i+1,j-1, arr), optimise(i, j-2, arr)));
}

int main(){
    int n;
    cin>>n;
    int arr[30];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    cout<<optimise(0, n-1, arr);
    return 0;
}