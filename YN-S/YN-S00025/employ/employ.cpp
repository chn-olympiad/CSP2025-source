#include <bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long res = 0;
const long long mod = 998244353;

long long jc[502] = {0};

long long out[502] = {0};

bool p[502] = {0};
bool s[502];
long long c[502];

long long jie(long long k) {
	if (jc[k] != 0) {
		return jc[k];
	} else {
		jc[k] = k * jie(k - 1) % mod;
		return jc[k];
	}

}

void dfs(long long k, long long sum, long long l) {
	if (k > n + 1) {
		return;
	}
	if (sum == m) {
		if (k == 1) {
			return;
		}
		res %= mod;
		res += jie(n - k + 1);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (p[i]) {
			continue;
		} else {
			p[i] = 1;
			out[k] = i;
			if (s[k] && l < c[i]) {
				dfs(k + 1, sum + 1, l);
			} else {
				dfs(k + 1, sum, l + 1);
			}
			p[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	jc[0] = 1;
	cin >> n >> m;
	cin.get();
	for (int i = 1; i <= n; i++) {
		s[i] = cin.get() - 48;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(1, 0, 0);
	cout << res;
	return 0;
}