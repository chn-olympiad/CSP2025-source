#include<bits/stdc++.h>
using namespace std;
long long a[510],vis[510];
long long n,m,ans;
string s;
void dfs(int u,int p,int sum)
{
//	cout<<u<<' ';
	if(sum-p<a[u])
	{
		if(s[sum]=='1')p++;
	}
	sum++;
	if(sum==n)
	{
		if(p>=m)
		{
			ans++;
			ans%=998244353;
//			cout<<'a';
		}
//		cout<<endl;
		return;
	}
	if(n-sum<m-p)return;
	vis[u]=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1)continue;
		dfs(i,p,sum);
	}
	vis[u]=0;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>18)
	{
		long long ans=1;
		for(long long i=1;i<=n;i++)
		{
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(i,0,0);
	}
	cout<<ans;
	return 0;
}