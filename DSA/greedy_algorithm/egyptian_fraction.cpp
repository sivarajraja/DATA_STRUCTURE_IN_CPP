#include<bits/stdc++.h>
using namespace std;

int print_egyptian(int nr, int dr)
{
    if(nr==0 && dr==0)
        return 0 ; 

    else if (dr%nr == 0)
    {
        cout<<"1/"<<dr/nr;
         return 0 ;
    }

    else if(nr%dr == 0)
    {
        cout<<nr/dr;
         return 0 ;
    }

    else if(nr>dr)
    {
        cout<<nr/dr<<" + ";
        print_egyptian(nr%dr, dr);
         return 0 ; 
    }

    else
    {
        int n= dr/nr+1;
        cout<<"1/"<<n<<" + ";
        print_egyptian(nr*n-dr, dr*n);
    }

    return 0;
}

int main()
{
    int nr = 6;
    int dr = 14;

    print_egyptian(nr,dr);
     return 0;
}