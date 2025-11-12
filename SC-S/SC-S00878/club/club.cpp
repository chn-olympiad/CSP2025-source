#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T;
int n;
int a[N][3];
bool checkA, checkB;

namespace CaseA
{
	int b[N];
	int ans;
	
	inline bool cmp(int A, int B)
	{
		return A > B;
	}
	
	void work()
	{
		ans = 0;
		
		for(int i = 1; i <= n; i ++)
		{
			b[i] = a[i][0];
		}
		
		sort(b + 1, b + 1 + n, cmp);
		
		for(int i = 1; i + i <= n; i ++)
		{
			ans += b[i];
		}
		
		printf("%d\n", ans);
		
		return;
	}
}

namespace Case1
{
	int ans = 0;
	
	void work()
	{
		ans = 0;
		
		for(int i = 0; i < 3; i ++)
		{
			for(int j = 0; j < 3; j ++)
			{
				if(i != j)
				{
					ans = max(ans, a[1][i] + a[2][j]);
				}
			}
		}
		
		printf("%d\n", ans);
		
		return;
	}
}

namespace Case2
{
	int ans = 0;
	
	void work()
	{
		ans = 0;
		
		for(int i1 = 0; i1 < 3; i1 ++)
		{
			for(int i2 = 0; i2 < 3; i2 ++)
			{
				for(int i3 = 0; i3 < 3; i3 ++)
				{
					for(int i4 = 0; i4 < 3; i4 ++)
					{
						if(i1 == i2 && i2 == i3 || i1 == i2 && i2 == i4 || i1 == i3 && i3 == i4 || i2 == i3 && i3 == i4)
						{
							continue;
						}
						
						ans = max(ans, a[1][i1] + a[2][i2] + a[3][i3] + a[4][i4]);
					}
				}
			}
		}
		
		printf("%d\n", ans);
		
		return;
	}
}

namespace Case3
{
	int ans = 0;
	int ij[11];
	
	bool check()
	{
		int cnt1, cnt2, cnt3;
		cnt1 = cnt2 = cnt3 = 0;
		
		for(int i = 1; i <= 10; i ++)
		{
			if(ij[i] == 0)
			{
				cnt1 ++;
			}
			else if(ij[i] == 1)
			{
				cnt2 ++;
			}
			else
			{
				cnt3 ++;
			}
		}
		
		if(cnt1 > 5 || cnt2 > 5 || cnt3 > 5)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void work()
	{
		ans = 0;
		
		for(ij[1] = 0; ij[1] < 3; ij[1] ++)
		{
			for(ij[2] = 0; ij[2] < 3; ij[2] ++)
			{
				for(ij[3] = 0; ij[3] < 3; ij[3] ++)
				{
					for(ij[4] = 0; ij[4] < 3; ij[4] ++)
					{
						for(ij[5] = 0; ij[5] < 3; ij[5] ++)
						{
							for(ij[6] = 0; ij[6] < 3; ij[6] ++)
							{
								for(ij[7] = 0; ij[7] < 3; ij[7] ++)
								{
									for(ij[8] = 0; ij[8] < 3; ij[8] ++)
									{
										for(ij[9] = 0; ij[9] < 3; ij[9] ++)
										{
											for(ij[10] = 0; ij[10] < 3; ij[10] ++)
											{
												if(check())
												{
													continue;
												}
												
												int sum = 0;
												
												for(int i = 1; i <= 10; i ++)
												{
													sum += a[i][ij[i]];
												}
												
												ans = max(ans, sum);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		printf("%d\n", ans);
		
		return;
	}
}

namespace Case4
{
	int ans = 0, tpans = 0;
	
	int p[N];
	int num[3];
	
	bool check()
	{
		if(num[0] > n / 2 || num[1] > n / 2 || num[2] > n / 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	double Rand()
	{
		return (double)rand() / RAND_MAX;
	}
	
	void SA()
	{
		double T, T0 = 100, d = 0.99, Te = 1e-15;
		
		T = T0;
		
		while(T > Te)
		{
			int x = rand() % n + 1;
			int y = rand() % 3;
			
			num[p[x]] --, num[y] ++;
			
			if(check())
			{
				num[p[x]] ++, num[y] --;
				continue;
			}
			
			tpans = ans - a[x][p[x]] + a[x][y];
			
			if(tpans > ans)
			{
				tpans = ans;
				p[x] = y;
			}
			else if(exp((double)(tpans - ans) / T) < Rand())
			{
				num[p[x]] ++, num[y] --;
			}
			
			T *= d;
		}
	}
	
	void work()
	{
		ans = 0;
		
		for(int i = 1; i + i <= n; i ++)
		{
			ans += a[i][0];
			num[0] ++;
			p[i] = 0;
		}
		
		for(int i = n / 2 + 1; i <= n; i ++)
		{
			int r = rand() % 2;
			
			if(r == 0)
			{
				ans += a[i][1];
				num[1] ++;
				p[i] = 1;
			}
			else
			{
				ans += a[i][2];
				num[2] ++;
				p[i] = 2;
			}
		}
		
		SA();
		
		printf("%d\n", ans);
		
		return;
	}
}

void solve()
{
	checkA = checkB = true;
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		
		if(a[i][1] != 0 || a[i][2] != 0)
		{
			checkA = false;
			
			if(a[i][2] != 0)
			{
				checkB = false;
			}
		}
	}
	
	if(checkA)
	{
		CaseA :: work();
		return;
	}
	else if(n == 2)
	{
		Case1 :: work();
		return;
	}
	else if(n == 4)
	{
		Case2 :: work();
		return;
	}
	else if(n == 10)
	{
		Case3 :: work();
		return;
	}
	else
	{
		Case4 :: work();
		return;
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	srand(time(0));
	
	cin >> T;
	
	while(T --)
	{
		solve();
	}
	
	return 0;
}