#include<iostream>
using namespace std;

int main()
{
    int arr[6]={1,3,5,6,7,9};
    int n=6,d;
    int dup=0;

    cout<<"enter the number (1-10) :"<<endl;
    cin>>d;

    for(int i=0; i<n; i++)
    {
        if(arr[i]==d)
        {
            cout<<"wow! you are lucky!"<<endl;
            dup=1;
        }
    }

    if(dup==0)
      cout<<"sorry! you are unlucky! "<<endl;

      return 0;
}