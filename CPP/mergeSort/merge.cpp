#include <iostream>
using namespace std;

void merge(int *a, int s, int e){
    int mid = (s+e)/2;
    int i = s; // start of first array
    int j = mid+1; // start of second array
    int k = s; // start of temporary array
    
    int temp[100];
    
    while(i<=mid && j<=e){
        if(a[i] < a[j]){
            temp[k++] = a[i++];
        }
        else{
            temp[k++] = a[j++];
        }
    }
    while(i<=mid){
        temp[k++] = a[i++];
    }
    while(j<=e){
        temp[k++] = a[j++];
    }
    
    //copy elements from temp to original
    for(int x=s;x<=e;x++){
        a[x] = temp[x];
    }
}

void mergeSort(int a[], int s, int e){
    //Base case
    if(s>=e){
        return;
    }
    
    //3 steps
    
    //1. Divide
    int mid = (s+e)/2;
    
    //2. Sort Recursively
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    
    //3. Merge
    merge(a,s,e);
    
}

int main() {
    int a[100];
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<", ";
    }
}
