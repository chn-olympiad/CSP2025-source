#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
long long t, n, m, a[N][5], state[N], sum = 0, maxn = -1;

bool Check_cout(long long t[], int x)
{
	int cout1 = 0, cout2 = 0, cout3 = 0;
	for(int i = 1; i <= x; i ++)
	{
		if(t[i] == 1)  cout1 ++;
		else if(t[i] == 2)  cout2 ++;
		else cout3 ++;
		
		if(cout1 > n/2 || cout2 > n/2 || cout3 > n/2)  return false;
	}
	return true;
}

void dfs(int x)
{
	if(x == n+1)  return;
	
	for(int i = 1; i <= 3; i ++)
	{
		state[x] = i;
		if(Check_cout(state, x))
		{
			x ++;
			dfs(x);
		}
		else  continue;
		
		for(int j = 1; j <= n; j ++)  sum += a[j][state[j]];
		maxn = max(maxn, sum);
		sum = 0;
	}
	cout << maxn << endl;
	maxn = -1;
	return;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	for(int i = 1; i <= t ; i ++)
	{
		cin >> n;
		for (int i = 1; i <= n; i ++)
			for(int j = 1; i <= 3; j ++)
				cin >> a[i][j];
		
		if(n == 2)
		{
			for(int i = 1; i <= 3; i ++)
			{
				state[1] = i; 
				for(int j = 1; j <= 3; j ++)
				{
					state[2] = j;
					if(Check_cout(state, 2))
					{
						sum = sum + a[1][state[1]] + a[2][state[2]];
						maxn = max(maxn, sum);
						sum = 0;
					}
				}
			}
			cout << maxn << endl;
			maxn = -1;
		}
		
		if(n == 4)
		{
			for(int i = 1; i <= 3; i ++)
			{
				state[1] = i;
				for(int j = 1; j <= 3; j ++)
				{
					state[2] = j;
					for(int k = 1; k <= 3; k ++)
					{
						state[3] = k;
						for(int l = 1; l <= 3; l ++)
						{
							state[4] = l;
							if(Check_cout(state, 4))
							{
								for(int x = 1; x <= 4; x ++)  sum += a[x][state[x]];
								maxn = max(maxn, sum);
								sum = 0;
							}
						}
					}
				}
			}
			cout << maxn << endl;
			maxn = -1;
		}
		
		if(n == 10)
		{
			for(int i = 1; i <= 3; i ++)
			{
				state[1] = i;
				for(int j = 1; j <= 3; j ++)
				{
					state[2] = j;
					for(int k = 1; k <= 3; k ++)
					{
						state[3] = k;
						for(int l = 1; l <= 3; l ++)
						{
							state[4] = l;
							for(int m = 1; m <= 3; m ++)
							{
								state[5] = m;
								for(int n = 1; n <= 3; n ++)
								{
									state[6] = n;
									for(int o = 1; o <= 3; o ++)
									{
										state[7] = o;
										for(int p = 1; p <= 3; p ++)
										{
											state[8] = p;
											for(int q = 1; q <= 3; q ++)
											{
												state[9] = q;
												for(int r = 1; r <= 3; r ++)
												{
													state[10] = r;
													if(Check_cout(state, 10))
													{
														for(int x = 1; x <= 10; x ++)  sum += a[x][state[x]];
														maxn = max(maxn, sum);
														sum = 0;
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
			}
			cout << maxn << endl;
			maxn = -1;
		}
		
		else
			dfs(1);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}