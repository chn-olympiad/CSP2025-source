#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;
int n,m;
constexpr ll mod=998244353;
const int maxN=500+10;
char s[maxN];
int c[maxN];
namespace T4f1
{
	const int maxn=19;
	int dp[maxn][maxn][(1<<(maxn-1))+10];
	bitset<maxn> bs;
	void solve()
	{
		for(int i=1;i<=n;++i)
		{
			if(c[i]>0&&s[1]=='1')
			{
				dp[1][1][1<<(i-1)]=1;
				dp[1][0][1<<(i-1)]=0;
			}
			else
			{
				dp[1][1][1<<(i-1)]=0;
				dp[1][0][1<<(i-1)]=1;
			}
		}
//		printf("____\n");
		for(int i=1;i<n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				for(int S=0;S<(1<<n);++S)
				{
					for(int k=1;k<=n;++k)
					{
						if((1<<(k-1))&S)
						{
							continue;
						}
//						printf("%d %d %d %d\n",i,j,S,k);
						if(c[k]<=i-j||s[i+1]=='0')
						{
							dp[i+1][j][S|(1<<(k-1))]=(dp[i+1][j][S|(1<<(k-1))]+dp[i][j][S])%mod;
						}
						else
						{
							dp[i+1][j+1][S|(1<<(k-1))]=(dp[i+1][j+1][S|(1<<(k-1))]+dp[i][j][S])%mod;
						}
					}
				}
			}
		}
//		printf("____\n");
		ll ans=0;
		for(int i=m;i<=n;++i)
		{
			for(int S=0;S<(1<<n);++S)
			{
				ans+=dp[n][i][S];
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
}



int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c[i]);
	}
	if(n<=18)
	{
		T4f1::solve();
	}
	else
	{
		bool TRUm=1;
		for(int i=1;i<=n;++i)
		{
			if(c[i]==0||s[i]=='0')
			{
				TRUm=0;
			}
		}
		if(TRUm)
		{
			ll ans=1;
			for(int i=1;i<=n;++i)
			{
				ans=ans*i%mod;
			}
			printf("%lld\n",ans);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
