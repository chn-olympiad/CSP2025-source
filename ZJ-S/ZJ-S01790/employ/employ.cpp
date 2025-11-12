#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const int mod=998244353;
const int N=505;
int c[N],p[N],ans=0;
string st;
bool vis[N];
int n,m;
void dfs(int s)
{
	if(s>n)
	{
		int cnt=0,no=0;
		for(int i=1;i<=n;i++)
		{
			if(st[i-1]=='0'||no>=c[p[i]])no++;
			else cnt++;
		}
		if(cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[s]=i;
		dfs(s+1);
		vis[i]=0;
	}
}
ll ffc(int x)
{
	return x==0?1:x*ffc(x-1)%mod;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=20)
	{
		dfs(1);
		cout<<ans%mod<<'\n';
	}
	else
	{
		cout<<ffc(n)%mod<<'\n';
	}
	return 0;
}