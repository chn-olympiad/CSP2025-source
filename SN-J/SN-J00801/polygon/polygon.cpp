#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[5001];
int ans;
int f[5001];

void input();
void dfs(int t, int sum, int maxn);
void output();

signed main()
{
	freopen("polygon.in", 'r', stdin);
	freopen("polygon.out", 'w', stdout);
	input();
	dfs(0, 0, 0);
	cout << ans;
	return 0;
}

void dfs(int t, int sum, int maxn)
{
	if(t == n)
	{
		if(sum > 2 * maxn)
		{
			ans++;
			//output();
			ans = ans % 998244353;
		}
		return;
	}
	f[t + 1] = 1;
	dfs(t + 1, sum + a[t + 1], max(maxn, a[t + 1]));
	f[t + 1] = 0;
	dfs(t + 1, sum, maxn);
}

void output()
{
	int i;
	
	for(i = 1; i <= n; i++)
	{
		cout << f[i] << " ";
	}
	cout << endl;
}

void input()
{
	int i;
	
	cin >> n;
	for(i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
}
