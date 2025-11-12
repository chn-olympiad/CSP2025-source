#include <bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,a[505],c[505];
int dp[(1<<18)+5][23];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n>18)
	{
		if(n==m)
		{
			bool fail=false;
			for(int i=1;i<=n;i++)
				if(a[i]==0||c[i]==0)
					fail=true;
			if(fail)
			{
				cout<<0;
				return 0; 
			}
			int ans=1;
			for(int i=1;i<=n;i++)
				ans=1ll*ans*i%p;
			cout<<ans;
			return 0;
		}
		//特殊性质A
		//我爆炸了
		 
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		int popcount=0;
		for(int j=1;j<=n;j++)
			if(i&(1<<(j-1)))
				popcount++;
		for(int j=0;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(i&(1<<(k-1)))
				{
					if(a[popcount]==0)
					{
						if(j)
							dp[i][j]=(dp[i][j]+dp[i-(1<<(k-1))][j-1])%p;
					}
					else
					{
						//录取成功 
						if(j<c[k]) 
							dp[i][j]=(dp[i][j]+dp[i-(1<<(k-1))][j])%p;
						//录取失败 
						else if(j&&j-1>=c[k])
							dp[i][j]=(dp[i][j]+dp[i-(1<<(k-1))][j-1])%p;
					}
				}
	}
	int ans=0;
	for(int i=0;n-i>=m;i++)
		ans=(ans+dp[(1<<n)-1][i])%p;
	cout<<ans;
	return 0;
}
