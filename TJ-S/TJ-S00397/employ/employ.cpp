#include<bits/stdc++.h>
using namespace std;
int a[505],b[505],c[105];
bool vis[105];
int main()
{
    int ans=0;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) b[i]=i;
    do
    {
        for(int i=1;i<=n;i++)
            c[i]=a[b[i]];
        for(int i=1;i<=n;i++) vis[i]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<cnt<<" ";
            if (vis[i]) continue;
            if (s[i]=='0')
            {
                vis[i]=1;
                cnt++;
                for(int j=i+1;j<=n;j++)
                {
                    if (cnt>=c[j])
                    {
                        vis[j]=1;
                        cnt++;
                    }
                }
            }
        }
        int cntt=0;
        for(int i=1;i<=n;i++)
        {
            if (!vis[i]) cntt++;
        }
        //cout<<cntt<<" ";
        if (cntt>=m) ans++;
    }while (next_permutation(b+1,b+n+1));
    cout<<ans;
    reutrn 0;
}
