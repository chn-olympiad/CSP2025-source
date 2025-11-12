#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e4+5;
ll n,m,vis[N],ans,c[N];
string str;
void dfs(ll u,ll v)
{
//	cout<<u<<" "<<" "<<v<<" "<<str[u-1]<<'\n';
	if(u==n+1&&(u-1-v)>=m)
	{
//		cout<<u-1-v<<'\n';
		ans++;return;
	}
	if(u==n+1)
		return;
	if(v+m>n)
		return;
	for(ll i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(c[i]<=v||str[u-1]=='0')
				dfs(u+1,v+1);
			else
				dfs(u+1,v);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>str;
	for(ll i=1;i<=n;i++)
		cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}