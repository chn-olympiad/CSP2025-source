#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[(1<<20)][20],c[20];
const int mod=998244353;
void ock()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int count(int i)
{
	int res=0;
	while(i)
	{
		if(i&1)
		{
			res++;
		}
		i>>=1;
	}
	return res;
}
signed main()
{
	ock();
	int n,m,mode=1;
	scanf("%lld%lld",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
	}
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++)
	{
		int ct=count(i);
		for(int j=1;j<=n;j++)
		{
			//cout<<ct<<" ";
			if(((1<<(j-1))|i)==i)
			{
				for(int k=ct-1;k>=0;k--)
				{
					if(ct-k-1<c[j]&&s[ct-1]!='0')
					{
						dp[i][k+1]+=dp[i-(1<<(j-1))][k];
						if(dp[i][k+1]>mod)
						{
							dp[i][k+1]-=mod;
						}
					}
					else
					{
						dp[i][k]+=dp[i-(1<<(j-1))][k];
						if(dp[i][k]>mod)
						{
							dp[i][k]-=mod;
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++)
	{
		ans+=dp[(1<<n)-1][i];
		if(ans>mod)
		{
			ans-=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
/*
10 5
 1101111011
 6 0 4 2 1 2 5 4 3 3
*/
