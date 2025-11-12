#include <bits/stdc++.h>
using namespace std;
const int Maxn=510;
const long long mod=998244353;
int n,m,c[Maxn],cnt;
long long ans;
string s1;
void Find(int site,int lost,int vic)
{
    if(vic==m)
    {
        if(n==site-1 or n==site)
        {
            ans+=1;
        }
        else
        {
            long long ls=1;
            for(int i=1;i<=n-site+1;i++)
            {
                ls*=i;
                ls=ls%mod;
            }
            ans+=ls;
        }
        ans=ans%mod;
        return;
    }
    if(lost>n-m)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]==-1)
        {
            continue;
        }
        int save=c[i];
        if(s1[site-1]=='1' and save>lost)
        {
            c[i]=-1;
            Find(site+1,lost,vic+1);
            c[i]=save;
        }
        else
        {
            c[i]=-1;
            Find(site+1,lost+1,vic);
            c[i]=save;
        }
    }
    return;
}
int main()
{
    freopen("employ2.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s1;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        if(s1[i]=='1')
        {
            cnt+=1;
        }
    }
    if(cnt<m)
    {
        cout<<0;
        return 0;
    }
    sort(c,c+n+1);
    if(m==n and n>20)
    {
        long long ls=1;
        for(int i=1;i<=n;i++)
        {
            ls*=i;
            ls=ls%mod;
        }
        cout<<ls;
        return 0;
    }
    Find(1,0,0);
    cout<<ans;
    return 0;
}
