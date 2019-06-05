#include<bits/stdc++.h>
using namespace std;

bool placed_possible(int i,int j,int n,int *chess){
    //to check whether the queens are placed in the same column or not
    for(int k=0;k<n;k++)
        if(k==i)
            continue;
        else{
            if(*(chess+k*n+j)==1)
                return false;
        }
    //to check whether the queens are placed diagonally or not
    for(int k=0;k<n;k++)
        if(k==i)
            continue;
        else{
            for(int l=0;l<n;l++)
                if(*(chess+k*n+l)==1&&abs(i-k)==abs(j-l))
                    return false;
        }
    return true;
}

void print(int n, int *chess,int placed){
    if(placed==0){
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<*(chess+i*n+j)<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=n-placed;i<n;i++){
        for (int j=0;j<n;j++){
            if(placed_possible(i,j,n,chess)){
                *(chess+i*n+j)=1;
                print(n,chess,placed-1);
                *(chess+i*n+j)=0;
            }
        }
        return;
    }
}

void placeNQueens(int n){
    int chess[n][n];
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            chess[i][j]=0;
        }
    }
    print(n,(int *)chess,n);
}

int main(){
    cout<<"Enter the size of the chess board"<<endl;
    int n;
    cin >> n ;
    cout<<"The possible solutions are (1->queen placed)"<<endl;
    placeNQueens(n);

}