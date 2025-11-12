#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,num=1,a,b;
    cin>>n>>a;
    for(int i=2;i<=n;i++)
    {
        cin>>b;
        if(b>a) num++;
    }
    int ax=(num-1+m)/m,ay;
    if(ax&1)
    {
        ay=num%m;
        if(ay==0) ay=m;
    }
    else
        ay=m-num%m;
    cout<<ax<<" "<<ay;
    return 0;
}
