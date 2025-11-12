#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 505, mod = 998244353;
int n, m, p[N]; std::string s;
int fac[N], inv[N];

inline int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod; b >>= 1;
 	}
 	return res;
}

signed main()
{
	std::freopen("employ.in", "r", stdin);
	std::freopen("employ.out", "w", stdout);
	
	std::cin >> n >> m >> s; bool flag = 0;
	for (int i = 1; i <= n; ++i) std::cin >> p[i];
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] == '0') flag = 1;
	if (!flag) 
	{
		int sum = 1;
		for (int i = 1; i <= n; ++i) sum = sum * i % mod;
		std::cout << sum << '\n';
		return 0;
	}
	return 0;
}