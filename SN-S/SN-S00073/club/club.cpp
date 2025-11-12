#include<bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[4][100010];

int ans;

void dfs(int t, int num, int one, int two);
void input();

signed main()
{
	//一定要记住 
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int step;
	int i;
	int he;
	
	cin >> step;
	while(step--)
	{
		input();
		ans = 0;
		if(n < 1000)
		{
			dfs(1, 0, 0, 0);
			cout << ans << endl;				
		}
		else
		{
			sort(a[1] + 1, a[1] + n + 1, greater<int>());
			he = 0;
			for(i = 1; i <= n / 2; i++)
			{
				he = he + a[1][i];
			}
			cout << he << endl;
		}
	}
}

void dfs(int t, int num, int one, int two)
{
	//判越界 
	if(one > n / 2 || two > n / 2 || t - one - two - 1 > n / 2)
	{
		return;
	}
	if(t > n)
	{
		ans = max(ans, num);
		return;
	} 

	dfs(t + 1, num + a[1][t], one + 1, two);
	dfs(t + 1, num + a[2][t], one, two + 1);
	dfs(t + 1, num + a[3][t], one, two);
}

void input()
{
	int i, j;
	
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= 3; j++)
		{
			cin >> a[j][i];
		}
	}
}
