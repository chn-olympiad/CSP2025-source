#include<bits/stdc++.h>
using namespace std;
int n,a[5010],mmx=0;
long long f[5010],ans=0;
void dfs(int u,int sum,int mx,int bs)
{
	if (u>n) return;
	int mx1=max(mx,a[u]);
	dfs(u+1,sum+a[u],mx1,bs+1);
	if (bs+1>=3&&sum+a[u]>mx1*2)
	{
		ans++;
		ans%=998244353;
	}
	dfs(u+1,sum,mx,bs);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mmx=max(mmx,a[i]);
	}
	if (mmx>1) dfs(1,0,0,0);
	else
	{
		long long sum=1;
		for (int i=1;i<=n;i++)
			sum=sum*2%998244353;
		long long p=n*(n-1)/2;
		ans=sum-p-n-1;
	}
	cout << ans;
	return 0;
}
