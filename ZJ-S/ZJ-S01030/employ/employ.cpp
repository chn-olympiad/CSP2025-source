#include <bits/stdc++.h>
using namespace std;
#define int long long
const int md = 998244353, N = 510;
int n, m, c[N], p[N], ans;
char dif[N];
inline void mian() {
	for(int i = 1; i <= n; ++i) p[i] = i;
	do {
		bool is = 1;
		int now = 0, ko = 0;
		for(int i = 1; i <= n; ++i) {
			if(ko >= c[p[i]] || dif[i] == '0') {
				++ko;
				if(n - ko < m) {
					is = 0;
					break;
				}
				continue;
			}
			if(++now >= m) break;
		}
		if(is) ++ans;
	} while(next_permutation(p + 1, p + n + 1));
	cout << ans << '\n';
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> (dif + 1);
	for(int i = 1; i <= n; ++i) cin >> c[i];
	mian();
	return 0;
}