#include<iostream>
using namespace std;

// More Optimized  Code of Bubble Sort
void bubble(int* arr,int n)
{
    for(int i=1; i<n; i++)
    {
        bool swapped=false;
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false)
            break;
    }
}


/* // Iterative Code of Bubble Sort
void bubble(int* arr,int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
*/
int main()
{
    int arr[20];
    int n;
    cout<<"Enter the Size of Array : "<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    bubble(arr,n);

    cout<<"Sorted Array is : "<<endl;
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}
