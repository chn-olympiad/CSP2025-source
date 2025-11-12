#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,m;
int c[505];
int a[505];
bool vis[505];
string s;
void dfs(int k)
{
	if(k==n+1)
	{
		int ml=0;
		for(int i=1;i<=n;++i)
		if(s[i-1]=='0') ml++;
		else if(ml>=c[a[i]])
		{
			ml++;
			continue;
		}
		if(n-ml>=m) ans++;
		return;
	}
	for(int i=1;i<=n;++i)
	if(vis[i]==0)
	{
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans<<"\n";
	return 0;
}
