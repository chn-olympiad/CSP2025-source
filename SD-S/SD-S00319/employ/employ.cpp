#include <bits/stdc++.h>
using namespace std;

const int N = 510, MOD = 998244353;
int c[N], b[N];
bool f[N];
int n, ans, m;
string s;

int jc(int n)
{
	long long mul = 1;
	for (int i = 1; i <= n; i++)
	{
		mul *= i;
		mul %= MOD; 
	}
	return mul;
}

bool check()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c[b[i]] <= cnt)
		{
			cnt++;
			continue;
		}
		if (s[i - 1] == '0') cnt++;
	}
	return (n - cnt) >= m;
}

void dfs(int step)
{
	if (step > n)
	{	
		if (check())
		{
			ans++;
//			for (int i = 1; i <= n; i++) cout << b[i] << ' ';
//			cout << endl;
		}
		ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[i]) continue;
		b[step] = i;
		f[i] = true;
		dfs(step + 1);
		f[i] = false;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flag = true;
	cin >> n >> m >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != '1') flag = false;
		cnt += s[i] - '0';
	}
	if (cnt < m)
	{
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	if (flag)
	{
		cout << jc(n);
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}
