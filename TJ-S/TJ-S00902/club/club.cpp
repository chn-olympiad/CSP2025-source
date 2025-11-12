#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7, MAXJ = 5;
int t;
int n, mxp;
int a[MAXN][MAXJ];
long long dp[MAXN][MAXJ];    //dp[i][j]:存储第i个人选择第j个部门时该部门内的总满意度
int num[MAXJ];    //num[j]:存储第j个部门现在有几个人 
long long ans;
void dfs(int i)
{
	for (int j = 1; j <= 3; j++)
	{
		dp[i][j] = dp[i-1][j];
	} 
	for (int j = 1; j <= 3; j++)
	{
		if (num[j] < mxp)
		{
			int t = dp[i][j];
			dp[i][j] += a[i][j];
			num[j]++;
			
			if (i == n)
			{
				long long tans = 0;
				//把还没来得及继承的部门继承过来 
				for (int k = j + 1; k <= 3; k++)
				{
					dp[i][k] = dp[i-1][k];
				}
				for (int k = 1; k <= 3; k++)
				{
					tans += dp[i][k];
				}
//				for (int p = 1; p <= n; p++)
//				{
//					for (int q = 1; q <= 3; q++)
//					{
//						printf("%d ", dp[p][q]);
//					}
//					printf("\n");
//				}
//				printf("\n");
				dp[i][j] = t;
				num[j]--;
				ans = max(tans, ans);
				continue;
			}
			dfs(i+1);
			dp[i][j] = t;
			num[j]--;
		}
	}
} 

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		memset(num, 0, sizeof(num));
		
		scanf("%d", &n);
		mxp = n / 2;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= 3; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		dfs(1);
		printf("%d\n", ans);
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
*/
