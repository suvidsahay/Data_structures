#include<iostream>

using namespace std;

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
            i++;
        while(a[i]<v&&i<=u);
        do
            j--;
        while(v<a[j]);
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    a[l]=a[j];
    a[j]=v;
    return(j);
}
void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        j=partition(a,l,u);
        quick_sort(a,l,j-1);
        quick_sort(a,j+1,u);
    }
}

void quickSort(int input[], int n) {
    quick_sort(input,0,n-1);
}

int main(){
    int n;
    cout<<"Enter the number of inputs"<<endl;
    cin >> n;
    int *input = new int[n];
    cout<<"Enter the values"<<endl;
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    quickSort(input, n);
    cout<<"Sorted array is"<<endl;
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    delete [] input;

}

