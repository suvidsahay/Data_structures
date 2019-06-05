#include<bits/stdc++.h>

using namespace std;

void sol(int present_row,int present_column,int maze[][20],int solution_maze[][20],int n){

    if(present_row==-1||present_row==n||present_column==-1||present_column==n||maze[present_row][present_column]==0||solution_maze[present_row][present_column]==1)
        return;
    solution_maze[present_row][present_column]=1;

    if(present_row==n-1&&present_column==n-1){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<solution_maze[i][j]<<" ";
        cout<<endl;
        solution_maze[present_row][present_column]=0;
        return;
    }
    sol(present_row+1,present_column,maze,solution_maze,n);
    sol(present_row-1,present_column,maze,solution_maze,n);
    sol(present_row,present_column+1,maze,solution_maze,n);
    sol(present_row,present_column-1,maze,solution_maze,n);
    solution_maze[present_row][present_column]=0;
}

void ratInAMaze(int maze[][20], int n){

    int start_row=0,start_column=0;
    int solution_maze[20][20];
    memset(solution_maze,0,20*20*sizeof(int));
    sol(start_row,start_column,maze,solution_maze,n);
}

int main(){

  int n;
  cout<<"Enter the size of the maze"<<endl;
  cin >> n ;
  cout<<"Enter the values in maze"<<endl;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }
  }
  cout<<"The possible solutions are"<<endl;
  ratInAMaze(maze, n);
}
