#include<bits/stdc++.h>

using namespace std;

const int Mod = 998244353; 

int len[5005];

int n;
int ans = 0;

void dfs(int x, int Max, int cnt, int choose)
{
	if(x > n)
	{
		if(choose >= 3)
		{
			if(cnt > 2 * Max)
			{
				ans++;
				ans %= Mod; 
			}
		}
		return;
	}
	dfs(x + 1, Max, cnt, choose);
	dfs(x + 1, max(Max, len[x]), cnt + len[x], choose + 1);
	
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> len[i];
	}
	
	if(n <= 25)
	{
		dfs(1, 0, 0, 0);
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
