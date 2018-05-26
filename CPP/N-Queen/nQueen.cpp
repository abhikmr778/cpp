#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n){
    //check col
    for(int row = 0; row<i; row++){
        if(board[row][j]==1){
            return false;
        }
    }

    //left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    //right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }

    //this position is safe
    return true;
}

bool nQueen(int board[][10], int i, int n){
    //Base Case
    if(i==n){
        //Successfuly placed all queens
        //Print board
        for(int x=0;x<n;x++){
            for(int y=0; y<n; y++){
                if(board[x][y]==1){
                    cout<<"Q"<<" ";
                }
                else{
                    cout<<"_"<<" ";
                }
            }
            cout<<endl;
        }
        cout<<endl<<endl;
        return false;
    } 
    //Recursive Case
    //Try to place the queen in the current row and call on ramaining part
    for(int j=0;j<n;j++){
        //If i,j is safe to place queen or not
        if(isSafe(board,i,j,n)){
            //place the queen - assuming i,j is right postion
            board[i][j]=1;

            bool nextQueenPossible = nQueen(board,i+1,n);
            if(nextQueenPossible){
                return true;
            }
            //means i,j isnt right position, wrong assumption
            board[i][j]=0; //backtracking
        }
    }
    //You have tried for all positions in the current row but couldn't place the queen
    return false;

}

int main(){
    int n;
    cin>>n;

    int board[10][10] = {0};
    nQueen(board,0,n);

    return 0;
}