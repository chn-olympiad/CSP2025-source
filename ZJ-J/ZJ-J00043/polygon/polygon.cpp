#include<bits/stdc++.h>
using namespace std;
long long n,a[5100],ans,f[5100];
void dfs(long long x,long long y,long long sum,long long q)
{
	if(x>n)
	{
		if(q>=3&&sum>2*y) ans++;
		return ;
	}
	dfs(x+1,a[x],sum+a[x],q+1);
	dfs(x+1,y,sum,q);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<ans%998244353;
	return 0;
}
/*
20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1

*/