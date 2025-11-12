#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550;
const ll p=998244353;
ll n,m,ans,c[N],q[N],vis[N];
string s;
void dfs(ll x)
{
	if(x>n)
	{
		ll now=0,sum=0;
		for(int i=1; i<=n; ++i)
		{
			if(c[q[i]]<=now||s[i]=='0')
			{
				now++;
				continue;
			}
			sum++;
		}
		ans+=(sum>=m);
		return;
	}
	for(int i=1; i<=n; ++i)
	{
		if(!vis[i])
		{
			vis[i]=1;
			q[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1; i<=n; ++i)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}