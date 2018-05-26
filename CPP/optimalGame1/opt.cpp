#include <iostream>
using namespace std;
int c = 0;
int maxM = 0;
bool coin(int *value, int i, int j, int n){
	if(i >= n || j<=0){
		if(c>maxM){
			maxM = c;
			// return true;
		}
			return false;
		
	}

	c+=value[i];
	coin(value,i+2,j,n);
	coin(value,i+1,j-1,n);
	c-=value[i];
	// c+=value[j];
	// if(coin(value,i+1, j-1, n)){
	// 	return true;
	// }
	// if(coin(value, i, j-2, n)){
	// 	return true;
	// }
	// c-=value[j];
}


int main(){
	int n;
	cin>>n;
	int value[30];
	for(int x=0;x<n;x++){
		cin>>value[x];
	}
	coin(value, 0 , n-1,n);
	cout<<maxM;
	return 0;
}