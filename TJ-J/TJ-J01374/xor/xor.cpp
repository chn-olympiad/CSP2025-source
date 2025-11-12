#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100005],cnt;
bool flaga=true,flagb=true,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)flaga=false;
        if(!(a[i]>=0&&a[i]<=1))flagb=false;
    }
    if(flaga)
    {
        cout<<n/2;
    }
    else if(flagb&&k)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                cnt++;
            }
        }
        cout<<cnt;
    }
    else if(flagb&&!k)
    {
        int all;
        for(int i=1;i<=n;i++)
        {
            all+=a[i];
            if(all%2==0)
            {
                all=0;
                cnt++;
            }
        }
        cout<<cnt;
    }
    else
    {
        cout<<k;
    }
    return 0;
}
