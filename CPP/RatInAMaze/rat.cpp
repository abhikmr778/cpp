#include "iostream"
using namespace std;

bool isSafe(char maze[][1000], int i, int j,int n, int m){
    if(maze[i][j]=='X'){
        return false;
    }
    if(i>n || j>m){
        return false;
    }
    return true;
}

bool path(char maze[][1000],int sol[][1000], int i, int j, int n, int m){
   if(i==n && j==m){
        sol[n][m]=1;
        for(int x=0;x<=n;x++){
            for(int y=0;y<=m;y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
   }
   
   if(isSafe(maze,i,j,n,m)==true){
    
       sol[i][j]=1;

       if(path(maze,sol,i,j+1,n,m)==true) return true;

       if(path(maze,sol,i+1,j,n,m)==true) return true;

       sol[i][j]=0;
    
       return false;

   }

    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    char maze[1000][1000];
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>maze[x][y];
        }
    }

    int sol[1000][1000] = {0};
    
    bool ans = path(maze,sol,0,0,n-1,m-1);
    if(!ans){
        cout<<-1;
    }
    
    return 0;
}