#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 500;
const int MOD = 998244353;
ll ans;
int n, m;
int val[MAXN];
string dific;

int p[MAXN];

inline bool check() {
	int ret = 0, rejected = 0;
	for (int i = 1; i <= n; ++i) {
		if (rejected >= val[p[i]] || dific[i - 1] == '0')
			rejected++;
		else
			ret++;
		if (ret >= m)
			return true;
	}
	return false;
}

inline void solve1() {
	for (int i = 1; i <= n; ++i)
		p[i] = i;
	
	ans += check();
	while (next_permutation(p + 1, p + n + 1))
		ans += check();
	
	cout << ans % MOD << '\n';
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	cin >> dific;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];
	
	solve1();
	return 0;
}
