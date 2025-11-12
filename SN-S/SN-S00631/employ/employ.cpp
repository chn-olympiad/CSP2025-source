#include<bits/stdc++.h>
#define ll long long 
#define mod 998344353
using namespace std;
ll n,m,sum[505],c[505],vis[505],ans;
string s;
void dfs(ll now,ll num,ll lose)
{
	if(now==n+1) {ans+=(num>=m); return;}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1; ll x=num,y=lose;
		if(c[i]>lose&&s[now]=='1') x++;
		else y++;
		dfs(now+1,x,y);
		vis[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	cin>>n>>m; cin>>s; s='1'+s; for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		dfs(1,0,0); cout<<ans; return 0;
	}
	return 0;
}
