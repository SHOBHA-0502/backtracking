#include<bits/stdc++.h>
using namespace std;

int board[11][11];
bool ispossible(int n , int row,int column ){
    for(int i = row-1; i>=0;i--){
        if(board[i][column]==1){
            return false;
        }
    }
    for(int i = row-1, j = column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;     
        }
    }
     for(int i = row-1, j = column+1;i>=0 && j<=n;i--,j++){
        if(board[i][j]==1){
            return false;     
        }
    }
    return true; 
}
void nQueenHelper(int n,int row){
    if(row == n){
        //we have reach the solution 
        // we have to print the materix 
        // now we have to return 
        for(int i =0 ; i<n ;i++){
            for(int j =0 ; j<n ; j++){
                cout<< board[i][j]<<" ";
            }
        }
        cout<<endl;
        return ;

    }
    // place at all possible position 
    // and move to smaller problem
    for(int j =0 ; j<n ; j++){
        if(ispossible(n,row,j)){
            board[row][j]=1;
            nQueenHelper(n, row+1);
             board[row][j]=0;
        }

    }
    return ;
}
void placeNqueens(int n){
    memset(board,0,sizeof(board));
    nQueenHelper(n,0);
}


int main(){
   int n ;
   cin>>n;
   placeNqueens(n); 
}