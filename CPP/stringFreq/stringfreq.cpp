#include <iostream>
using namespace std;

void print(int *arr){
    int max = 0;
    for(int x=0;x<26;x++){
        if(arr[x]>max){
            max = arr[x];
        }
    }
    cout<<max;
}

void freq(string str, int j, int l, int *arr){
    if(j==l){
        return;
    }
    char ch = str[j];
    int x = ch - 'a';
    arr[x]++;
    freq(str, j+1, l, arr);
}

int main(){
    string str;
    cin>>str;
    int l = str.length();
    int arr[26];
    freq(str,0, l, arr);
    print(arr);
    return 0;
}