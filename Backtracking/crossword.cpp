/*
INPUT FORMAT:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV

OUTPUT FORMAT: 
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include<bits/stdc++.h>
using namespace std;

char crossword[10][10];


bool if_present(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)
            if(crossword[i][j]=='-')
                return true;
    }
    return false;
}

bool if_horizontal(int &row, int &column, string st,int n){
    int k=0,count=0;
    for(int i=0;i<n;i++){
        if(crossword[row][column+i]!='-' && crossword[row][column+i]!=st[k]){
            return false;
        }
        k++;
    }
    return true;
}

bool if_vertical(int &row, int &column, string st,int n){
    int k=0,count=0;
    for(int i=0;i<n;i++){
        if(crossword[row+i][column]!='-' && crossword[row+i][column]!=st[k]){
            return false;
        }
        k++;
    }
    return true;

}

void fill_horizontal(int row, int column,string st, bool arr[10],int n){
    for(int i=0;i<n;i++){
        if(crossword[row][column+i]!='-'){
            arr[i]=false;
        }
        crossword[row][column+i]=st[i];
    }

}

void fill_vertical(int row, int column,string st, bool arr[10],int n){
    for(int i=0;i<n;i++){
        if(crossword[row+i][column]!='-'){
            arr[i]=false;
        }
        crossword[row+i][column]=st[i];
    }
}

void remove_horizontal(int row,int column,string st,bool arr[10],int n){
    for(int i=0;i<n;i++){
        if(arr[i]){
            crossword[row][column+i]='-';
        }
    }
    for(int i=0;i<10;i++){
        arr[i]=true;
    }
}

void remove_vertical(int row,int column,string st,bool arr[10],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==true){
            crossword[row+i][column]='-';
        }
    }
    for(int i=0;i<10;i++){
        arr[i]=true;
    }

}

void fill_crossword(vector<string> str,int index){
    int row=0,column=0;
    if(index==str.size()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
                cout<<crossword[i][j];
            cout<<endl;
        }
        return;
    }
    bool arr[10];
    for(int i=0;i<10;i++){
        arr[i]=true;
    }
    for(row=0;row<10;row++)
        for(column=0;column<10;column++)
            if(if_horizontal(row,column,str[index],str[index].length())){
                fill_horizontal(row,column,str[index],arr,str[index].length());
                fill_crossword(str,index+1);
                remove_horizontal(row,column,str[index],arr,str[index].length());
            }
    for(column=0;column<10;column++)
        for(row=0;row<10;row++)
            if(if_vertical(row,column,str[index],str[index].length())){
                fill_vertical(row,column,str[index],arr,str[index].length());
                fill_crossword(str,index+1);
                remove_vertical(row,column,str[index],arr,str[index].length());
            }
}

int main() {
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            cin>>crossword[i][j];
    string s,st="";
    cin>>s;
    vector<string> str;
    for(int i=0;i<s.length();i++){
        if(s[i]==';'){
            str.push_back(st);
            st="";
        }
        else st=st+s[i];
    }
    str.push_back(st);
    fill_crossword(str,0);
}