#include<iostream>
using namespace std;

void rotate(int arr[],int start,int end)
{
    while(start < end)
    {
        int temp[end];
        temp[start]=arr[start];
        arr[start]=arr[end];
        arr[end]=temp[start];

        start++;
        end--;
    }
}

void leftrotate(int arr[],int d,int n)
{
    rotate(arr,0,d-1);
    rotate(arr,d,n-1);
    rotate(arr,0,n-1);
}
    

int main()
{
    int n=7,d=2;
    int arr[]={1,2,3,4,5,6,7};

    leftrotate(arr,d,n);
    
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}