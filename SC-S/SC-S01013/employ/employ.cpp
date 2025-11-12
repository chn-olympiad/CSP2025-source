#include <bits/stdc++.h>
#define E(i, l, r) for(int i = l;i <= r;++ i)
using ll = long long;
using namespace std;
const int N = 1e5 + 10;
const ll MOD = 998244353;
int n, m, ans, q, c[N], s[N], p[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	E(i, 1, n) {
		char ch;
		cin >> ch;
		s[i] = ch - '0';
		p[i] = i;
		q += s[i];
	}
	E(i, 1, n) cin >> c[i];
	do {
		int tot = 0;
		E(i, 1, n) {
			if(!s[i]) ++ tot;
			else if(c[p[i]] <= tot) ++tot;
		}
		ans += (n - tot >= m);
	} while(next_permutation(p + 1, p + n + 1));
	return cout << ans << "\n", 0;
}