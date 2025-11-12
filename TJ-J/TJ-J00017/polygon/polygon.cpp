#include <bits/stdc++.h>
using namespace std;
int n,a[1000005];
int f(int s,int x)
{
    int sum,sum1=1,sum2=1;
    for(int i=x-s+1;i<=x;i++)
        sum1*=i;
    for(int i=1;i<=s;i++)
        sum2*=i;
    sum=sum1/sum2;
    return sum;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n==3)
    {
            if(a[1]+a[2]+a[3]>a[3]*2)
                cout<<1;
            else
                cout<<0;
    }
    else{
            int ans=0;
            for(int i=3;i<=n;i++)
                ans+=f(i,n);
            cout<<ans%998244353;
    }
    return 0;
}
