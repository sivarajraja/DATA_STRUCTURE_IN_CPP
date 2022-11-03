#include<iostream>
using namespace std;

class reverse_array
{
    public:
     
     int arr[7]={1,2,3,4,5,6,7};
     int n=7,d=2;
     int temp[5];

     void b_rev()
     {
         cout<<"before reverse !"<<endl;

         for(int i=0; i<n; i++)
           cout<<arr[i]<<" ";

     }

     void a_rev()
     {

         for(int j=0; j<d; j++)
         {
             temp[j]=arr[j];
         }

         for(int k=0; k<n-d; k++)
         {
             arr[k]=arr[k+d];
         }

         
     }

     void display()
     {
        cout<<"\nafter reverse !"<<endl;
        for(int i=0; i<n-d; i++)
          cout<<arr[i]<<" ";
        
        for(int i=0; i<d; i++)
        {
            cout<<temp[i]<<" ";
        }
     }

};

int main()
{
    reverse_array r1;
    r1.b_rev();
    r1.a_rev();
    r1.display();

    return 0;

}