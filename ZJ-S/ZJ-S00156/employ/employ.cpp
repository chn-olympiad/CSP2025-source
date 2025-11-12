#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m,a[505],ans;
string s;
int vis[505];
vector <int> v;
void dfs(int x)
{
	if(x==n+1)
	{
		int giveup=0,ok=0;
		for(int i=0;i<v.size();i++)
		{
			if(giveup>=a[v[i]]) giveup++;
			else if(s[i]-'0'==0) giveup++;
		}
		if(n-giveup==m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			v.push_back(i);
			dfs(x+1);
			v.pop_back();
			vis[i]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}