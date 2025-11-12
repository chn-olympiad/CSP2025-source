#include <bits/stdc++.h>

using namespace std;
int n,a[5010];
int b[5010];
int f[5010];
int cnt;
void dfs(int,int,int);
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 3;i<=n;i++)
	{
		dfs(0,i,0);
	}
	cout<<cnt;
	return 0;
}
void dfs(int p,int pp,int xxx)
{
	if(p==pp)
	{
		int ma = -1;
		int sum = 0;
		for(int i = 1;i<=pp;i++)
		{
			sum += b[i];
			ma = max(ma,b[i]);
		}
		if(sum>ma*2) cnt = (cnt+1)%998244353;
		return;
	}
	for(int i = xxx+1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i] = 1;
			b[p+1] = a[i];
			dfs(p+1,pp,i);
			f[i] = 0;
		}
	}
	return;
}
