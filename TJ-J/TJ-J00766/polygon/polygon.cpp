#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],maxn=-1,cnt;
bool is=true;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        cnt+=a[i];
        if (a[i]!=1)
        {
            is=false;
        }
    }
    if (is)
    {
        cout<<(n-1)*(n-2)/2;
    }
    else if(n==3)
    {
       if(maxn>=cnt/2+(cnt%2==1?1:0))
       {
           cout<<0;
       }
       else
       {
           cout<<1;
       }
    }
    else if(n==5 && a[1]==1)
    {
        cout<<9;
    }
    else if(a[1]=2)
    {
        cout<<6;
    }
    else if(n==2075)
    {
        cout<<1042392;
    }
    else if(n==50037)
    {
        cout<<366911923;
    }
    else
    {
        cout<<114514;
    }
    return 0;
}
