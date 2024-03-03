#include<iostream>
using namespace std;

void selection(int* arr,int n)
{
    for(int i=0; i<n-1; i++)
    {
        int mini=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[mini])
                mini=j;
        }
        swap(arr[mini],arr[i]);
    }
}

int main()
{
    int arr[20];
    int n;
    cout<<"Enter the Size of Array : "<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    selection(arr,n);

    cout<<"Sorted Array is : "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
