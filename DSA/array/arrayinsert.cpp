#include<iostream>
using namespace std;

class array_insert
{
    public:

    int n=5,d=2,a=5;
    int arr[10]={2,4,6,8,10};

    void b_ins()
    {
        cout<<"before insertion !"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void a_ins()
    {
        cout<<"\nafter insertion !"<<endl;
        for(int j=n+1; j>=d; j--)
        {
            arr[j]=arr[j-1];

        }

        for(int i=d; i<=d; d++)
        {
            arr[i]=a;
        }

        for(int k=0; k<n+1; k++)
        {
            cout<<arr[k]<<" ";
        }
    }

};

int main()
{
    array_insert d1;
    d1.b_ins();
    d1.a_ins();

    return 0;
}