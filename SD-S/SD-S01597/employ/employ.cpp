#include<bits/stdc++.h>
using namespace std;
int const N=505,P=998244353;
int n,m,a[N],p[N],ans;
bool b[N];
string s;
bool vis[N];
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
			continue;
		if(i-cnt-1>=a[p[i]])
			continue;
		cnt++;
		if(cnt>=m)
			return 1;
	}
	return 0;
}
void dfs(int c)
{
	if(c==n+1)
	{
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		p[c]=i;
		dfs(c+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		b[i]=s[i-1]-'0';
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}

