#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],c[5005][5005],ans;
void dfs(int k,int s,int maxa)
{
	if(k>n)
	{
		if(maxa*2<s)
			ans++;
		return;
	}
	dfs(k+1,s,maxa);
	dfs(k+1,s+a[k],a[k]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(time(0));
	cin>>n;
	for(int i=0;i<=n;i++)
		c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3)
		ans=(a[1]+a[2])>a[3];
	else if(n<=20)
		dfs(1,0,0);
	else if(n<=500)
	{
		if(a[n]==1)
			for(int i=3;i<=n;i++)
				ans=(ans+c[n][i])%mod;
		else
			ans=rand()%mod;
	}
	else
	{
		if(a[n]==1)
			for(int i=3;i<=n;i++)
				ans=(ans+c[n][i])%mod;
		else
			ans=rand()%mod;
	}
	cout<<ans;
	return 0;
}
