#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],ma=-1,ans=0;
queue <int> q;
void dfs(int dep,int cnt,int side,int sum,int ma)
{
	if(dep>n)
	{
		if(cnt==side)
		{
			if(sum>ma*2)
				ans++;
		}
		return;
	}
	dfs(dep+1,cnt,side,sum,ma);
	q.push(a[dep]);
	if(a[dep]>ma)
		ma=a[dep];
	dfs(dep+1,cnt+1,side,sum+a[dep],ma);
	q.pop();
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
		dfs(1,0,i,0,-1);
	}
	cout<<ans%998244353;
	return 0;
}
