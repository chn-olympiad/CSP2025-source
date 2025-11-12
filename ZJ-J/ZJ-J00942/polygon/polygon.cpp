#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int Mod=998244353;
int a[5010],ans[5010],vis[5010],cnt;
void dfs(int l,int sum,int st)
{
	if(l>n) return ;
	if(l>=3)
	{
		if(sum>ans[l]*2)
		{
			cnt++;
			cnt%=Mod;
		}
	}
	for(int i=st;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ans[l+1]=a[i];
			dfs(l+1,sum+a[i],i);
			vis[i]=0;
		}
	}
}
__int128 u,o,p,pos;
int C(int x,int y)
{
	if(x==y) return 1;
	o=1,p=1;
	for(int i=2;i<=x;i++)
	{
		o*=i;
		//o%=Mod;
	}
	for(int i=2;i<=y-x;i++)
	{
		p*=i;
		//p%=Mod;
	}
	u=o*p;
	return pos/u;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	pos=1;
	for(int i=2;i<=n;i++)
	{
		pos*=i;
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) flag=1;
	}
	if(!flag)
	{
		//cout<<555;
		int sum=0;
		for(int i=3;i<=n;i++)
		{
			//cout<<C(i,n);
			sum+=C(i,n);
			//cout<<C(i,n)<<"\n";
			sum%=Mod;
		}
		cout<<sum%Mod;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(0,0,1);
	cout<<cnt%Mod;
	return 0;
}