#include "iostream"
using namespace std;

int count = 0;

bool isSafe(int board[][15],int i,int j,int n){
    for(int x=0;x<i;x++){
        if(board[x][j]==1){
            return false;
        }
    }
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueen(int board[][15], int i, int n){
    if(i==n){
        count++;
        return false;
    }
    for(int j=0; j<n; j++){
        if(isSafe(board,i,j,n)){
            board[i][j]=1;
            if(nQueen(board,i+1,n)){
                return true;
            }
            board[i][j]=0;
        }

    }
    return false;

}

int main(){
    int n;
    cin>>n;

    int board[15][15] = {0};
    nQueen(board, 0, n);
    cout<<count;
    return 0;
}