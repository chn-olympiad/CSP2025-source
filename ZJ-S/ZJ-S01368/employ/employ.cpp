#include <bits/stdc++.h>
#define PII pair <int, int>
#define LL long long
#define DB double
#define ST string

#define fr(x, y, z) for(int x = (y); x <= (z); x ++ )
#define dfr(x, y, z) for(int x = (y); x >= (z); x -- )

using namespace std;

const int N = 510, MOD = 998244353;
int n, m; ST st;
int c[N], res;

bool used[N];
int a[N], A[N];
void dfs(int cnt, int unl)
{
//	cout << cnt << ' ' << unl << '\n';
	
	if(n - unl < m) return ;
	if(cnt - 1 - unl >= m)
	{
		res = (1ll * res + A[n - cnt + 1]) % MOD;
		return ;
	}
	if(cnt == n + 1)
	{
		if(n - unl >= m)
		{
			res = (res + ((n - unl) >= m)) % MOD;
//			cout << unl << '\n';
//			fr(i, 1, n) cout << a[i] << ' ';
//			cout << '\n';
		}
		return ;
	}
	
	fr(i, 1, n) if(!used[i])
	{
		used[i] = 1;
//		a[cnt] = i;
		dfs(cnt + 1, unl + (unl >= c[i] || st[cnt - 1] == '0'));
		used[i] = 0;
	}
}

//int qp(int x, int y)
//{
//	int res = 1;
//	while(y)
//	{
//		if(y & 1) res = 1ll * res * x % MOD;
//		x = 1ll * x * x % MOD; y >>= 1;
//	}
//	return res;
//}
//
//int A(int x, int y)
//{
//	int res = 1;
//	fr(i, x - y + 1, x) res = 1ll * res * i % MOD;
//	return res;
//}

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
//	cout << A(3, 2) << ' ' << A(5, 1) << '\n';
	
	cin >> n >> m >> st;
	A[0] = 1;
	fr(i, 1, n) A[i] = 1ll * A[i - 1] * i % MOD;
	
	fr(i, 1, n) cin >> c[i];
	
//	if(n > 10)
//	{
//		res = 1;
//		int cnt = 0;
//		fr(i, 1, n) cnt += (c[i] == 0);
//		
//		res = (1ll * cnt * A(n - cnt, m - 1) % MOD + 1ll * A(n - cnt, m)) % MOD;
//		
//		cout << res << '\n';
//	}
	
	res = 0;
	dfs(1, 0);
	
	cout << res << '\n';

	return 0;
}

