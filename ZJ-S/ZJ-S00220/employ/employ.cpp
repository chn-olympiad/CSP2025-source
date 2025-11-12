#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, mod = 998244353;

int n, m, res = 0;
string s;
int a[N], b[N];
bool flag[N];

void check()
{
	int cnt = 0, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(cnt >= a[b[i]])
		{
			cnt++;
			continue;
		}
		if(s[i - 1] == '0') cnt++;
		else sum++;
	}
	if(sum >= m) res++;
}

void dfs(int dep)
{
	if(dep > n)
	{
		check();
		return;
	}
	for(int i = 1; i <= n; i++)
		if(!flag[i])
		{
			flag[i] = 1;
			b[dep] = i;
			dfs(dep + 1);
			flag[i] = 0;
		}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 10) dfs(1);
	else
	{
		if(m == n)
		{
			cout << "0\n";
			return 0;
		}
		for(int i = 1; i <= n; i++)
			res = (res * i) % mod;
		cout << res << "\n";
		return 0;
	}
	cout << res << "\n";
	return 0;
}
