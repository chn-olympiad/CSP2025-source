#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+9;
const int mod=998244353;
int n,m;
bool s[maxn];
int c[maxn];
int a[maxn];
bool vis[maxn];
int ans;
void dfs(int x,int dep)
{
	a[dep]=x;
	if(dep==n)
	{
		int res=0;
		for(int i=1;i<=n;i++) 
		{
			if(i-1-res>=c[a[i]]) continue;
			res+=s[i];
		}
		if(res>=m) ans++;
		if(ans>mod) ans-=mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		dfs(i,dep+1);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	string tt;
	cin>>tt;
	for(int i=1;i<=n;i++) s[i]=tt[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0,0);
	cout<<ans<<'\n';
	return 0;
}