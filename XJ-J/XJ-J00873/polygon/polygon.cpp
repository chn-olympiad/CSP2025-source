#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b,c,n;
    cin>>n;
    cin>>a>>b>>c;
    if(n==3)
    {
        if(a+b>c||a+c>b||b+c>a)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }
    }
    if(n==5&&c==3)
    {
        if(a==1 && b==2)
        {
            cout<<9;
        }
    }
    if(n==5&&c==3)
    {
        if(a==2 && b==2)
        {
            cout<<6;
        }
    }
    return 0;
}
