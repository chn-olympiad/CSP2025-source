#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a[1020];
    int i=0,num=0;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char ch:s)
    {
        if(ch=='0')
        {
            a[num]=0;
            num++;
        }
        else if(ch=='1')
        {
            a[num]=1;
            num++;
        }
        else if(ch=='2')
        {
            a[num]=2;
            num++;
        }
        else if(ch=='3')
        {
            a[num]=3;
            num++;
        }else if(ch=='4')
        {
            a[num]=4;
            num++;
        }else if(ch=='5')
        {
            a[num]=5;
            num++;
        }else if(ch=='6')
        {
            a[num]=6;
            num++;
        }
        else if(ch=='7')
        {
            a[num]=7;
            num++;
        }else if(ch=='8')
        {
            a[num]=8;
            num++;
        }else if(ch=='9')
        {
            cout<<9;
        }
        i++;
    }
    for(int j=0;j<num;j++)
    {
        if(a[j]==8)
        {
            cout<<8;
        }
    }
    for(int j=0;j<num;j++)
    {
        if(a[j]==7)
        {
            cout<<7;
        }
    }for(int j=0;j<num;j++)
    {
        if(a[j]==6)
        {
            cout<<6;
        }
    }for(int j=0;j<num;j++)
    {
        if(a[j]==5)
        {
            cout<<5;
        }
    }for(int j=0;j<num;j++)
    {
        if(a[j]==4)
        {
            cout<<4;
        }
    }for(int j=0;j<num;j++)
    {
        if(a[j]==3)
        {
            cout<<3;
        }
    }
    for(int j=0;j<num;j++)
    {
        if(a[j]==2)
        {
            cout<<2;
        }
    }for(int j=0;j<num;j++)
    {
        if(a[j]==1)
        {
            cout<<1;
        }

    }
    for(int j=0;j<num;j++)
    {
        if(a[j]==0)
        {
            cout<<0;
        }
    }
    return 0;
}
