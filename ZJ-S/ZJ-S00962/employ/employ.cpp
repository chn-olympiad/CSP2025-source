#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m;
int a[505],b[505],jc[505];
int vis[505];
string s;
int ans;
void dfs(int sum,int ok)
{
	if(m>ok+b[n]-b[sum-1]) return ;
	if(sum==n+1)
	{
		if(ok>=m) ans++;
		if(ans>=mod) ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		vis[i]=1;
		if(s[sum]=='1'&&a[i]>sum-1-ok) dfs(sum+1,ok+1);
		else dfs(sum+1,ok);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s=" "+s;
	int f1=0;
	int sum=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1')
			f1++;
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1];
		if(s[i]=='1') b[i]++;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			sum++;
	if(m>b[n])
	{
		cout<<0;
		return 0;
	}
	if(m==n)
	{
		if(sum!=0||b[n]!=0)
		{
			cout<<0;
			return 0;
		}
		ans=1ll;
		for(int i=1;i<=n;i++) ans*=i,ans%=mod;
		cout<<ans;
		return 0;
	}
	if(n<=18)
	{
		dfs(1,0);
		cout<<ans;
	}
//	if(f1==1)
//	{
//		jc[0]=1;
//		for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
//		ans=jc[n];
//		for(int i=1;i<=n;i++)
//		{
//			
//		}
//	}
	return 0;
}
