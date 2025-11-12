#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    string s;
    cin>>s;
    int cnt=0;
    bool e=true;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==0)
        {
            e=false;
            break; 
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cnt++;
        }
    }
    n-=cnt;
    if(!e)
    {
        cout<<0;
        return 0;
    }
    else
    {
        int ans=0;
        
        for(int i=1;i<=m;i++)
        {
            int cnt=1;
            for(int j=n;j>=i;j--)
            {
                cnt*=j;
                cnt%=mod;
            }
            ans+=cnt;
            ans%=mod;
        }
        cout<<ans%mod;
    }
    return 0;
}

