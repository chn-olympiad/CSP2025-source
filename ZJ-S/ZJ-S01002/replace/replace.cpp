#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 5e6 + 10, b = 131;
int n, Q;
ull f[N], g[N], pw[N];
char s1[N], s2[N], t1[N], t2[N]; 
map<pair<ull, ull>, int>mp;
ull getf(int l, int r) {
	if (l > r) return 0llu;
	return f[r] - f[l - 1] * pw[r - l + 1];
}
ull getg(int l, int r) {
	if (l > r) return 0llu;
	return g[r] - g[l - 1] * pw[r - l + 1];
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> Q;
	pw[0] = 1;
	for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * b;
	for (int i = 1; i <= n; i++) {
		cin >> (s1 + 1) >> (s2 + 1);
		int l = strlen(s1 + 1);
		ull h1 = 0, h2 = 0;
		for (int j = 1; j <= l; j++) {
			h1 = h1 * b + s1[j];
			h2 = h2 * b + s2[j];
		}
//		dbg("###", h1, h2);
		mp[make_pair(h1, h2)]++;
	}
	while (Q--) {
		cin >> (t1 + 1) >> (t2 + 1);
		int l = strlen(t1 + 1);
		if (l != (int)strlen(t2 + 1)) {
			cout << "0\n";
			continue;
		}
		for (int i = 1; i <= l; i++) {
			f[i] = f[i - 1] * b + t1[i];
			g[i] = g[i - 1] * b + t2[i];
		}
		ll ans = 0;
		for (int i = 1; i <= l; i++) {
			if (getf(1, i - 1) == getg(1, i - 1)) {
				for (int j = i; j <= l; j++) {
					if (getf(j + 1, l) == getg(j + 1, l)) {
//						dbg("###", i, j, f[j], f[i - 1], pw[j - i + 1], getf(i, j), getg(i, j));
						ans += mp[make_pair(getf(i, j), getg(i, j))];
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


