#include<iostream>
using namespace std;

void bubblesort(int *arr,int n)
{
    if(n==0 || n==1)
        return;

    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    bubblesort(arr,n-1);
}

int main()
{
    int arr[6]={12,78,95,111,11,1};
    int n=6;

    bubblesort(arr,n);

    cout<<"The Sorted Array is : "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    return 0;
}
