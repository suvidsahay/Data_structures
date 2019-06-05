#include<bits/stdc++.h>

using namespace std;

bool sudoku_empty(int sudoku[9][9],int &row,int &column){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            if(sudoku[i][j]==0){
                row=i;
                column=j;
                return true;
            }
    return false;
}

bool isPossible(int sudoku[9][9],int row,int column,int value){
    for(int i=0;i<9;i++){
        if(i==row)
            continue;
        else if(sudoku[i][column]==value)
            return false;
    }
    for(int i=0;i<9;i++){
        if(i==column)
            continue;
        else if(sudoku[row][i]==value)
            return false;
    }
    for(int i=(row/3)*3;i<((row/3)+1)*3;i++)
        for(int j=(column/3)*3;j<((column/3)+1)*3;j++)
            if(sudoku[i][j]==value)
                return false;
    return true;
}

void solveSudoku(int sudoku[9][9],int row, int column){
    if(!sudoku_empty(sudoku, row, column)){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                cout<<sudoku[i][j]<<" ";
            cout<<endl;
        }


    }
    else {
            for(int i=1;i<=9;i++){
                if(isPossible(sudoku,row,column,i)){
                    sudoku[row][column]=i;
                    solveSudoku(sudoku,row,column);
                    sudoku[row][column]=0;
                }
            }
        }
}

int main(){
    cout<<"Enter the values in sudoku with 0 as blank space"<<endl;
    int sudoku[9][9];
    for(int i = 0; i < 9 ;i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
        }
    }
    cout<<"The solution is"<<endl;
    solveSudoku(sudoku,0,0);
}