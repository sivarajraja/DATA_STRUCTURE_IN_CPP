#include<iostream>
using namespace std;

void arrange(int arr[],int n)
{
    int i,j,temp;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(arr[j]==i)
            {
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        if(arr[i]!=i)
            arr[i]=-1;
    }

    cout<<"after rearranging "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int n=10;
    int arr[n]={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};

    arrange( arr ,n );

    return 0;
}