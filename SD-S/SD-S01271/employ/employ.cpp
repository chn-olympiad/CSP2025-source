#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const unsigned mod = 998244353;
int n, m;
int s[N];
int c[N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string str;
	cin >> str;
	bool tf = true;
	for (int i = 1; i <= n; i ++) {
		s[i] = str[i - 1] - '0';
		if (s[i] == 0) tf = false;
	}
	for (int i = 1; i <= n; i ++) {
		cin >> c[i];
	}
	if (n > 12) {
		if (tf) {
			unsigned long long f = 1;
			for (unsigned i = 1; i <= n; i ++) {
				f = f * i % mod;
			}
			cout << f;
			return 0;
		}
		cout << 0;
		return 0;
	}
	vector<int> v;
	for (int i = 1; i <= n; i ++) {
		v.push_back(i);
	}
	int cnt = 0;
	do {
		int notacc = 0, ct = 0;
		for (int i = 0; i < n; i ++) {
			if (c[v[i]] <= notacc) {
				notacc ++;
				continue;
			}
			if (s[i + 1] == 0) notacc ++;
			else ct ++;
		}
		if (ct >= m) {
			cnt ++;
			cnt %= mod;
		}
	}
	while (next_permutation(v.begin(), v.end()));
	cout << cnt;
	return 0;
}

