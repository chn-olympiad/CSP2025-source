#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freio(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
using namespace std;
const int mod=998244353;
int n;
int a[5005];
bool f[5005];
int cnt;
void dfs(int x,int k,int s,int maxx)
{
	if(x>=3)
	{
		if(2*maxx<s)
		{
			cnt++;
			cnt%=mod;
		}
	}
	for(int i=k+1;i<=n;i++)
	{
		if(f[i]==false)
		{
			f[i]=true;
			dfs(x+1,i,s+a[i],a[i]);
			f[i]=false;
		}
	}
	return ;
}
//RP++
//10:00 40 dfs
int main()
{
	fastio
	freio("polygon")
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
	for(int i=1;i<=n-3;i++)
	{
		memset(f,false,sizeof f);
		f[i]=true;
		dfs(1,i,a[i],a[i]);
		f[i]=false;
	}
	cout<<(cnt+1)%mod;
	return 0;
}
