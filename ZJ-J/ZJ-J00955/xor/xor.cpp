#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n,k,pd=0,ans=0,l=1,r=1;
    int a[10005];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(k==0)
    {
        int t=1;
        while(a[t]==0)
            t++;
        ans-=t;
    }
    while(r!=n)
    {
        if(pd==k)
        {
            ans++;
            l=r+1;
            r=l-1;
            pd=a[l];
        }
        else if(pd>k)
            pd=pd-a[r];
        else
            pd=pd+a[r];
        r++;
    }
    cout<<ans;
    return 0;
}
