#include<bits/stdc++.h>
using namespace std;
int s,i9,i8,i7,i6,i5,i4,i3,i2,i1,i0;
char n[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for(int i=0;i<=1000005;i++)
    {
        if(n[i]=='9')
        {
            i9++;
        }
        else if(n[i]=='8')
        {
            i8++;
        }
        else if(n[i]=='7')
        {
            i7++;
        }
        else if(n[i]=='6')
        {
            i6++;
        }
        else if(n[i]=='5')
        {
            i5++;
        }
        else if(n[i]=='4')
        {
            i4++;
        }
        else if(n[i]=='3')
        {
            i3++;
        }
        else if(n[i]=='2')
        {
            i2++;
        }
        else if(n[i]=='1')
        {
            i1++;
        }
        else if(n[i]=='0')
        {
            i0++;
        }
    }
    for(int i=1;i<=i9;i++)
    {
        cout<<9;
    }
    for(int i=1;i<=i8;i++)
    {
        cout<<8;
    }
    for(int i=1;i<=i7;i++)
    {
        cout<<7;
    }
    for(int i=1;i<=i6;i++)
    {
        cout<<6;
    }
    for(int i=1;i<=i5;i++)
    {
        cout<<5;
    }
    for(int i=1;i<=i4;i++)
    {
        cout<<4;
    }
    for(int i=1;i<=i3;i++)
    {
        cout<<3;
    }
    for(int i=1;i<=i2;i++)
    {
        cout<<2;
    }
    for(int i=1;i<=i1;i++)
    {
        cout<<1;
    }
    for(int i=1;i<=i0;i++)
    {
        cout<<0;
    }
    return 0;
}
