#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define V vector
#define x first
#define y second
using namespace std;

const int maxn = 500;
const int maxm = 500;
const int mod = 998244353;

int n, m;

int s[maxn + 5];
int c[maxn + 5];

int fr[maxn + 5];
int frac(int x)
{
	if(!x) return fr[x] = 1;
	return fr[x] = x * frac(x-1) % mod;
}

namespace A
{
	V<V<V<int>>> dp;
	int dfs(int i, int j, int k)
	{
		int& f = dp[i][j][k];
		if(~f) return f; f = 0;
		if(k == 0) return f = frac(i);
		if(!i) return f = 0;
		
	}
	
	int solve()
	{
		dp.resize(n+5, V<V<int>>(n+5, V<int>(m+5, -1)));
		cout << dfs(n, 0, m) << '\n';
		return 0;
	}
}

namespace s1
{
	V<V<int>> dp;
	int dfs(int i, int j)
	{
		int& f = dp[i][j];
		if(~f) return f; f = 0;
		int cnt = 0;
		for(int k = 0; k < n; ++k)
			if((i >> k) & 1) ++cnt;
		if(!i) return f = (n - j >= m);
		int nd = m - (cnt - j);
		for(int k = 0; k < n; ++k)
			if((i >> k) & 1)
			{
				if(c[k+1] <= j || s[n-cnt+1] == 1)
					f += dfs(i ^ (1<<k), j+1);
				else f += dfs(i ^ (1<<k), j);
				f %= mod;
			}
		return f;
	}
	int solve()
	{
		dp.resize((1<<n), V<int>(n+5, -1));
		cout << dfs((1<<n)-1, 0) << '\n';
		return 0;
	}
}

namespace B
{
	V<int> h;
	V<int> id;
	V<V<int>> dp;
	int dfs(int i, int j)
	{
		int& f = dp[i][j];
		if(~f) return f; f = 0;
		int cnt = 0;
		for(int k = 0; k < id.size(); ++k)
			if((i >> k) & 1) ++cnt;
		if(!i) return f = (id.size() - j >= m);
		for(int k = 0; k < id.size(); ++k)
			if((i >> k) & 1)
			{
//				cout << id.size()-cnt << '\n';
				if(c[id[k]] <= j + h[id[id.size()-cnt]])
					f += dfs(i ^ (1<<k), j+1);
				else f += dfs(i ^ (1<<k), j);
				f %= mod;
			}
		return f;
	}
	int solve()
	{
		h.resize(n + 5, 0);
		dp.resize((1<<n), V<int>(n+5, -1));
		for(int i = 1; i <= n; ++i)
		{
			h[i] += h[i-1] + s[i];
//			cout << h[i] << " \n"[i == n];
			if(!s[i])
				id.push_back(i);
		}
		cout << dfs((1<<id.size())-1, 0) << '\n';
		return 0;
	}
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	string S;
	cin >> S;
	bool isA = 1;
	int cntB = 0;
	for(int i = 0; i < n; ++i)
	{
		s[i+1] = S[i] ^ '1';
		if(!s[i+1]) ++cntB;
		if(s[i+1]) isA = 0;
	}
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	sort(c + 1, c + n + 1);
	if(n <= 18) return s1::solve();
	if(cntB <= 18)
	{
		return B::solve();
	}
	if(isA)
	{
		A::solve();
		return 0;
	}
	cout << 0 << '\n';

	return 0;
}
