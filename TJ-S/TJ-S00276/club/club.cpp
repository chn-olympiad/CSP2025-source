#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100001
using namespace std;
int a[MAXN][4], dp[MAXN][4], ppl[MAXN][4][4]; // ppl: i, j, per club
void debug(int n)
{
	cerr << "DP ------------" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
			cerr << dp[i][j] << " ";
		cerr << endl;
	}
	cerr << "---------------" << endl;
	cerr << "PPL -----------" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cerr << "(";
			for (int k = 1; k <= 3; k++)
				cerr << ppl[i][j][k] << " ";
			cerr << ") "; 
		}
		cerr << endl;
	}
	cerr << "---------------" << endl;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				scanf("%d", &a[i][j]);
		memset(dp, 0, sizeof(dp));
		memset(ppl, 0, sizeof(ppl));
		for (int i = 1; i <= n; i++) // people
		{
			for (int j = 1; j <= 3; j++) // cur club (i,j) 
			{
				int maxn = 0, maxi = 0;
				for (int k = 1; k <= 3; k++) // inherit prev stat (i-1,k)
				{
					int x;
					if (ppl[i - 1][k][j] + 1 > n / 2) // prev stat cur club ppl (i-1,k,j)
					{
						x = -1;
						// do inherit
						for (int l = 1; l <= 3; l++) // prev per club ppl
						{
							// cur stat idx ppl (i,j,l)
							// prev stat idx ppl (i-1,k,l)
							ppl[i][j][l] = ppl[i - 1][k][l];
						}
					} 
					else
					{
						x = dp[i - 1][k] + a[i][j];
						// do inherit
						for (int l = 1; l <= 3; l++) // prev per club ppl
						{
							// cur stat idx ppl (i,j,l)
							// prev stat idx ppl (i-1,k,l)
							ppl[i][j][l] = ppl[i - 1][k][l];
							if (j == l)
								ppl[i][j][l]++; 
						}
					}
					if (x > maxn)
					{
						maxn = x;
						maxi = k;
					}
					for (int l = 1; l <= 3; l++) // undo
						ppl[i][j][l] = 0;
				}
				dp[i][j] = maxn;
				if (ppl[i - 1][maxi][j] + 1 > n / 2) // redo
				{
					// do inherit
					for (int l = 1; l <= 3; l++) // prev per club ppl
					{
						// cur stat idx ppl (i,j,l)
						// prev stat idx ppl (i-1,k,l)
						ppl[i][j][l] = ppl[i - 1][maxi][l];
					}
				} 
				else
				{
					// do inherit
					for (int l = 1; l <= 3; l++) // prev per club ppl
					{
						// cur stat idx ppl (i,j,l)
						// prev stat idx ppl (i-1,k,l)
						ppl[i][j][l] = ppl[i - 1][maxi][l];
						if (j == l)
							ppl[i][j][l]++; 
					}
				}
			}
		}
//		debug(n);
		int ans = 0;
		for (int i = 1; i <= 3; i++)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans); 
	} 
	return 0;
}
