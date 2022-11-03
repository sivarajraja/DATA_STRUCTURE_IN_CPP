#include<iostream>
using namespace std;

class array_delete
{
    public:

    int n=5,d=2;
    int arr[10]={2,4,6,8,10};

    void b_del()
    {
        cout<<"before deletion !"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void a_del()
    {
        cout<<"\nafter deletion !"<<endl;
        for(int j=d; j<n; j++)
        {
            arr[j]=arr[j+1];
        }

        for(int k=0; k<n-1; k++)
        {
            cout<<arr[k]<<" ";
        }
    }

};

int main()
{
    array_delete d1;
    d1.b_del();
    d1.a_del();

    return 0;
}