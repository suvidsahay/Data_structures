#include <iostream>

using namespace std;

void merge(int input[],int a[],int b[],int n,int m){
    int i=0,j=0,k=0;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            input[k++]=a[i++];
        }
        else if(a[i]>=b[j]){
            input[k++]=b[j++];
        }
    }
    while(i<n)
        input[k++]=a[i++];
    while(j<m)
        input[k++]=b[j++];
}

void mergeSort(int input[], int size){
    if(size==1)
        return;
    int n=size/2;
    int m=size/2+size%2;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        a[i]=input[i];
    for(int i=0;i<m;i++)
        b[i]=input[n+i];
    mergeSort(a,n);
    mergeSort(b,m);
    merge(input,a,b,n,m);
}

int main() {
  int input[1000],length;
  cout<<"Enter the number of inputs"<<endl;
  cin >> length;
  cout<<"Enter the values"<<endl;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  cout<<"Sorted Array is"<<endl;
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
