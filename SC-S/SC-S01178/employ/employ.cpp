#include<bits/stdc++.h>
using namespace std;

int n,m,mod=998244353,c[505],j[505];
bool vis[505],flag;
int tt,ly;
long long ans;
string s;
void dfs(int step)
{
    if(ly>=m)
    {
        ans++;
        ans=ans%mod;
        return;
    }
    if(step>n)
    {
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            if(s[step]=='0'||c[i]<=tt)
            {
                tt++;
                dfs(step+1);
                vis[i]=0;
                tt--;
            }
            else {
                ly++;
                dfs(step+1);
                vis[i]=0;
                ly--;
            }

        }
    }

}
int jc(int x)
{
    j[0]=1;
    j[1]=1;
    return j[x]=jc(x-1)*x;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]!=1)flag=1;
    }
    if(m==n)
    {
    	if(!flag) 
        	cout<<1;
        else cout<<0;
        return 0;
    }
    if(!flag)
    {
        cout<<jc(n)%mod;
        return 0;
    }
    dfs(1);
    cout<<ans%mod;
    return 0;
}