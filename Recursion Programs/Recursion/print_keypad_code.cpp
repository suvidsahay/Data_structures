#include <iostream>
#include <string>
using namespace std;


string a[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void print(int num, string output){
    if(num==0||num==1){
        cout<<""<<endl;
        return;
    }
    else if(num/10==0){
        for(int i=0;i<a[num%10].length();i++){
            cout<<a[num%10][i]+output<<endl;
        }
        return;
    }
    else
        for(int i=0;i<a[num%10].length();i++){
            print(num/10,a[num%10][i]+output);
        }
}

int main(){
    int num;
    cout<<"Enter the number"<<endl;
    cin >> num;
    cout<<"The possible codes associated that appears on the dial are"<<endl;
    print(num,"");
    return 0;
}
