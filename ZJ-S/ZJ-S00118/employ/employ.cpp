#include<bits/stdc++.h>
using namespace std;
const long long Mod=998244353;
int n,m,c[510],vis[510],p[510];
char a[510];
long long ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int q=0;
		for(int i=1;i<=n;i++)
		{
			if(q>=c[p[i]]) q++;
			else if(a[i]=='0') q++;
		}
		if(n-q>=m) 
		{
			/*for(int i=1;i<=n;i++) cout<<p[i]<<" ";
			cout<<endl;*/
			ans=(ans+1)%Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			p[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve1()
{
	dfs(1);
	cout<<ans<<endl;
}
void solve2()
{
	bool flag=0;long long fc=1;
	for(int i=1;i<=n;i++) fc=fc*i%Mod;
	for(int i=1;i<=n;i++) 
	{
		if(a[i]=='0')
		{
			flag=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1) cout<<0<<endl;
	else cout<<fc<<endl;
}
int find(int x)
{
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(c[mid]<=x) l=mid;
		else r=mid;
	}
	return l;
}
void solve3()
{
	long long ret=1,q=0;
	long long fc=1;
	for(int i=1;i<=n;i++) fc=fc*i%Mod;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='1')
		{
			int tmp=find(i-1);
			if(tmp>q) ret=ret*(tmp-q)%Mod;
			q++;
		}
	}
	cout<<(fc-ret+Mod)%Mod<<endl;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(n<=10) solve1();
	else if(m==n) solve2();
	else if(m==1) solve3();
	return 0;
}// fc employ2.ans employ2.out
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
