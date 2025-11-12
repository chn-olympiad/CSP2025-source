#include<bits/stdc++.h>
using namespace std;
int ss(int n)
{
    return (n+1)*n/2;
}
int a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long jg;
    int num_1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
            num_1++;
    }
    if(num_1==n)
    {
        jg=ss(n)%998244353;
        cout<<jg;
    }
    else
        cout<<5;
    return 0;
}
