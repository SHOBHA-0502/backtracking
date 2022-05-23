#include<bits/stdc++.h>
using namespace std ;
#define n 9
bool findemptylocation(int grid[n][n],int &row , int &col){
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j<n ; j++){
            if(grid[i][j]==0){
                row =i ;
                col =j;
                return true; 
            }
        }
    }
    return false;
}
bool issafeinrow(int grid[n][n],int row,int num){
    for(int i =0 ;i<n;i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    return true;
}
bool issafeincol(int grid[n][n],int col,int num){
    for(int i =0 ;i<n;i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    return true;
}
bool issafeingrid(int grid[n][n],int row,int col,int num){
  int rowfactor = row - (row%3);
  int colfactor = col - (col%3);
    for(int i =0 ;i<3;i++){
        for(int j =0 ; j<3;j++){
             if(grid[i+rowfactor][col+colfactor]==num){
            return false;
        }
        }
       
    }
    return true;
    
}
bool issafe(int grid[n][n],int row,int col , int num){
if(issafeincol(grid,col,num)&& issafeinrow(grid,row,num) && issafeingrid(grid ,row,col,num)){
    return true;
}
return false;
 }
bool solvesuduko(int grid[n][n]){
     int row , col;

     if(!findemptylocation(grid ,row,col)){
         return true;
     }
     for(int i =0 ; i<=n ; i++){
         if(issafe(grid,row,col,i)){
             grid[row][col] =i;
             if(solvesuduko(grid)){
                 return true;
             }
             grid[row][col]=0;
         }
     }
     return false;
}
int main(){
   int grid[n][n];
  for(int i =0 ; i<n ; i++){
      for(int j =0 ; j<n ; j++){
          cin>>grid[i][j];
      }
  }
  
   if (solvesuduko(grid)){
//    for(int i =0 ; i<n ;i++){
//        for(int j =0 ; j<n ; j++){
//            cout<<grid[i][j]<<" ";
//        }
//        cout<<endl;
//    }
cout<<"true"<<endl;
}
else{
cout<<"false"<<endl;
}
}