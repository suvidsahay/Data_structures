#include <iostream>
#include <string>

using namespace std;

string a[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int keypad(int num, string output[]){
    int i;
    if(num==0||num==1){
        output[0]=a[num];
        return 1;
    }
    else{
        int count=keypad(num/10,output);
        for( i=1;i<=a[num%10].length();i++){
            for(int j=0;j<count;j++){
                output[j+i*count]=output[j]+a[num%10][i-1];
            }
        }
        for(i=0;i<count*a[num%10].length();i++){
            if(i<count){
                for(int j=0;j<count*a[num%10].length()+count-i;j++){
                    output[j]=output[j+1];
                }
            }
        }
        return count*a[num%10].length();
    }

}

int main(){
    int num;
    cout<<"Enter the number"<<endl;
    cin >> num;
    string output[10000];
    int count = keypad(num, output);
    cout<<"The possible codes associated that appears on the dial are"<<endl;
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
