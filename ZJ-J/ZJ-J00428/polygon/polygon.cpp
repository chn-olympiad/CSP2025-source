#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],b[N],p[N];
int n;
long long cnt;
void dfs(int x,int t)
{
	if(x==t+1)
	{
		long long sum=0,maxn=0;
		for(int i=1;i<=x-1;i++)
		{
			long long m=a[p[i]];
			sum+=m;
			maxn=max(maxn,m);
		}
		if(sum>2*maxn)
			cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i] && i>p[x-1])
		{
			b[i]=1;
			p[x]=i;
			dfs(x+1,t);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=3;i<=n;i++)
	{
		memset(p,0,sizeof p);
		dfs(1,i);
	}
	cout<<cnt%998244353;
	return 0;
}
