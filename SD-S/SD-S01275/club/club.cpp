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
int t;
int n;
namespace Solve1
{
	const int maxn=210;
	int a[maxn][4];
	int dp[maxn][maxn][maxn];
	int solve()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				scanf("%d",&a[i][j]);
			}
		}
		memset(dp,0,sizeof(dp));
		dp[1][1][0]=a[1][1];
		dp[1][0][1]=a[1][2];
		dp[1][0][0]=a[1][3];
		for(int i=2;i<=n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				for(int k=0;k<=i-j;++k)
				{
					dp[i][j][k]=dp[i-1][j][k]+a[i][3];
					if(j>0)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					}
					if(k>0)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					}
				}
			}
		}
		int ans=0;
		for(int j=0;j<=n;++j)
		{
			for(int k=0;k<=n;++k)
			{
				if(j>n/2||k>n/2||(n-j-k)>n/2)
				{
					continue;
				}
				ans=max(ans,dp[n][j][k]);
			}
		}
		printf("%d\n",ans);
	}
}
namespace Solve2
{
	const int maxn=1e5+10;
	int a[4][maxn];
	int moder;
	void solveA();
	void solveB();
	void solveC();
	void solve()
	{
		bool fc2=1;
		bool fc3=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=3;++j)
			{
				scanf("%d",&a[j][i]);
			}
			if(a[2][i]!=0)fc2=0;
			if(a[3][i]!=0)fc3=0;
		}
		if(fc2)
		{
			solveA();
		}
		else if(fc3)
		{
			solveB();
		}
		else
		{
			solveC();
		}
	}
	void solveA()
	{
		sort(a[1]+1,a[1]+n+1);
		int ans=0;
		for(int i=n;i>n/2;--i)
		{
			ans+=a[1][i];
		}
		printf("%d\n",ans);
	}
	void solveB()
	{
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			ans+=a[1][i];
		}
		for(int i=1;i<=n;++i)
		{
			a[3][i]=a[2][i]-a[1][i];
		}
		sort(a[3]+1,a[3]+n+1);
		for(int i=n;i>n/2;--i)
		{
			ans+=a[3][i];
		}
		printf("%d\n",ans);
	}
	void solveC()
	{
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])
			{
				ans+=a[1][i];
			}
			else if(a[2][i]>=a[3][i]&&a[2][i]>=a[1][i])
			{
				ans+=a[2][i];
			}
			else
			{
				ans+=a[3][i];
			}
		}
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=200)
		{
			Solve1::solve();
		}
		else
		{
			Solve2::solve();
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
