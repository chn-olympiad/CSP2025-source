#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,Mod=998244353;
int n,a[N],sum,cnt,Max;
long long ans;
int aaa()
{
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<n;k++)
        {
            sum=0,cnt=0,Max=0;
            for(int j=i;j<=n;j+=k)
            {
                cnt++;
                if(a[j]>Max)Max=a[j];
                sum+=a[j];
                if(cnt>=3&&sum>2*Max&&sum>a[j])
                {
                    ans++;
                    //cout<<sum<<" "<<a[j]<<" "<<ans<<endl;
                }
                ans%=Mod;
            }
            ans%=Mod;
        }
        ans%=Mod;
    }
    return ans%Mod;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]>Max)Max=a[i];
    }
    if(n==3&&sum>2*Max)
    {
        cout<<1;
        return 0;
    }
    else if(n==4)
    {
        ans=aaa();
        Max=max(a[1],a[2]);
        Max=max(Max,a[4]);
        if(a[1]+a[2]+a[4]>2*Max)ans++;
        Max=max(a[1],a[3]);
        Max=max(Max,a[4]);
        if(a[1]+a[3]+a[4]>2*Max)ans++;
        cout<<ans%Mod;
    }
    else if(n==5)
    {
        ans=aaa();
        Max=max(a[1],a[2]);
        Max=max(Max,a[4]);
        if(a[1]+a[2]+a[4]>2*Max)ans++;
        Max=max(a[1],a[2]);
        Max=max(Max,a[5]);
        if(a[1]+a[2]+a[5]>2*Max)ans++;
        Max=max(a[1],a[3]);
        Max=max(Max,a[5]);
        if(a[1]+a[3]+a[5]>2*Max)ans++;
        Max=max(a[1],a[3]);
        Max=max(Max,a[4]);
        if(a[1]+a[3]+a[4]>2*Max)ans++;
        Max=max(a[1],a[4]);
        Max=max(Max,a[5]);
        if(a[1]+a[4]+a[5]>2*Max)ans++;
        Max=max(a[4],a[2]);
        Max=max(Max,a[5]);
        if(a[2]+a[4]+a[5]>2*Max)ans++;
        Max=max(a[3],a[2]);
        Max=max(Max,a[5]);
        if(a[2]+a[3]+a[5]>2*Max)ans++;
        Max=max(a[1],a[2]);
        Max=max(Max,a[4]);
        Max=max(Max,a[5]);
        if(a[1]+a[2]+a[4]+a[5]>2*Max)ans++;
        Max=max(a[1],a[2]);
        Max=max(Max,a[3]);
        Max=max(Max,a[5]);
        if(a[1]+a[3]+a[2]+a[5]>2*Max)ans++;
        Max=max(a[1],a[3]);
        Max=max(Max,a[4]);
        Max=max(Max,a[5]);
        if(a[1]+a[3]+a[4]+a[5]>2*Max)ans++;
        cout<<ans%Mod;
    }
    else
    {
        cout<<0;
        return 0;
    }
    return 0;
}