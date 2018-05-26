#include <iostream>
using namespace std;

int no=0;

bool canPlace(int chess[][100], int i, int j, int n){
    if(chess[i-1][j-2]==1 && i>0 && j>1) return false;
    if(chess[i+1][j-2]==1 && i<n-1 && j>1) return false;
    if(chess[i-1][j+2]==1 && i>0 && j<n-2) return false;
    if(chess[i+1][j+2]==1 && i<n-1 && j<n-2) return false;
    if(chess[i-2][j-1]==1 && i>1 && j>0) return false;
    if(chess[i-2][j+1]==1 && i>1 && j<n-1) return false;
    if(chess[i+2][j-1]==1 && i<n-2 && j>0) return false;
    if(chess[i+2][j+1]==1 && i<n-2 && j<n-1) return false;
    return true;
}

bool placeKnight(int chess[][100], int i, int j, int n, int k){
    if(k==n){
        no++;
        for(int x=0;x<n;x++){
            for(int y=0; y<n; y++){
                cout<<chess[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }

    for(int x=0;x<n;x++){
        for(int y=0; y<n; y++){
            if(canPlace(chess,x,y,n)){
                chess[x][y]=1;
                if(placeKnight(chess, x, y+1, n, k+1)){
                    return true;
                }
                chess[x][y]=0;
            }
        }
    }

}

int main(){
    int n;
    cin>>n;

    int chess[100][100]={0};
    placeKnight(chess, 0, 0, n, 0);
    cout<<no;
    return 0;
}