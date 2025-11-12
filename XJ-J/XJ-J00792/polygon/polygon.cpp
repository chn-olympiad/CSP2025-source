#include <bits/stdc++.h>
using namespace std;
long long n, a[5001], sum=0, maxn=-1e8, ans=0;
void solve()
{
	long long k, i, j;
	for(k=1;;k++)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				sum+=a[j];
				maxn=max(maxn, a[j]);
			}
			if(sum>maxn*2) ans++;
		}
		if(i>=n)
		{
			ans%=998244353;
			cout<<ans;
			return;
		}
	}
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	solve();
	return 0;
}
