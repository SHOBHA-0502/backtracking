#include<bits/stdc++.h>
using namespace std ;
void printsolution(int **solution,int n){
   for(int i =0 ; i<n ; i++){
       for(int j =0 ; j<n ; j++){
           cout<<solution[i][j]<<" ";
       }
   }
   cout<<endl; 
}
void mazehelp(int maze[][20] , int n , int**solution,int x,int y)
{    if(x==n-1 && y ==n-1){
    solution[x][y]=1;
    printsolution(solution,n);
    return ;

}
    if(x>=n|| y>=n||x<0|| y<0|| maze[x][y]==0||solution[x][y]==1){
        return;
    }
  solution[x][y]=1;
  mazehelp(maze , n , solution,x-1,y);
  mazehelp(maze , n , solution,x+1,y);
  mazehelp(maze , n , solution,x,y-1);
  mazehelp(maze , n , solution,x,y+1);
  solution[x][y]=0;

}
 void ratinmaze(int maze[][20],int n ){
      int** solution = new int*[n];
      for(int i =0 ; i<n ; i++){
          solution[i] = new int [n];
      }
    mazehelp(maze , n , solution,0,0);
 }
int main(){
    int n ;
    cin>>n ;

int maze[n][n];
for(int i =0; i<n; i++){
    for(int j =0 ; j<n ; j++){
        cin>>maze[i][j];
    }
}
ratinmaze(maze, n );

}