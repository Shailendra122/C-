#include<iostream>
using namespace std;

int partitions(int arr[],int s,int e)
{

    int pivot=arr[s];
    int cnt=0;

    for(int i=s+1; i<=e; i++)
    {
        if(arr[i]<=pivot)
            cnt++;
    }

    //Place Pivot at Right Position
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);

    //Left and Right Wala Part
    int i=s;
    int j=e;

    while(i<pivotIndex && j>pivotIndex)
    {
        while(arr[i]<=pivot)
            i++;

        while(arr[j>pivot])
            j--;

        if(i<pivotIndex && j>pivotIndex)
            swap(arr[i++],arr[j--]);

    }

    return pivotIndex;

}

void quickSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
        return ;

    //Partition Karenge
    int p=partitions(arr,s,e);

    //Left Part Sort Karenge
    quickSort(arr,s,p-1);

    //Right Part Sort Karenge
    quickSort(arr,p+1,e);
}

int main()
{
    int n;
    cin>>n;

    int *arr = new int[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    quickSort(arr,0,n-1);                   // (arr,s,e)

    cout<<"Sorted Array is ";

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    delete[] arr;

    return 0;
}

