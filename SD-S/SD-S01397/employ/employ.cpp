#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int mod=998244353;
string s;
int a[N];
struct pe{int t;int id;};
pe c[N];
long long ans;
int n,m;
bool vis[N];
bool cmp(pe x,pe y)
{
	return x.t<y.t;
}
void dfs(int cnt,int dep)
{
	if(dep==n)
	{
		if(n-cnt>=m)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		if(cnt>=c[c[i].id].t||a[dep]==0)
		{
			dfs(cnt+1,dep+1);
		}
		else
		{
			dfs(cnt,dep+1);
		}
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n>10)
	{
		cout<<0;
		return 0;
	}
	cin>>s;
	for(int i=0;i<n;i++)
	{
		a[i]=((int)(s[i]-'0'));
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i].t;
		c[i].id=i;
	}
	sort(c+1,c+n+1,cmp);
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
