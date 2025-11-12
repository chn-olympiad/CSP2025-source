#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
#define int long long
#define endl '\n'
const int mod = 998244353;
int h[510], a[510];
int jc[510];

inline int jiec(int n) {
	if (n == 0 || n == 1)
		return 1;
	if (jc[n] != 0)
		return jc[n] % mod;
	return jc[n] = jiec(n - 1) * n % mod;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int n;
	//cin >> n;
	//cout << n + 1;
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		h[i] = h[i - 1];
		if (s[i - 1] == '1')
			h[i]++;
	}
	if (h[n] < m) {
		cout << 0;
	} else if (h[n] == n) {
		int u = jiec(n);
		cout << u;
	} else {
		if (m == 1) {

			int u = jiec(n);
			cout << u;

		} else {
			sort(a + 1, a + 1 + n);
			int cnt = 0, icnt = 1;
			a[0] = -1;
			for (int i = 1, cf = 0; i <= n; i++) {
				if (a[i] == a[i - 1]) {
					if (cf == 0)
						cf = 2;
					else
						cf++;
				}
				if (a[i] != a[i - 1] || i == n) {
					if (cf != 0)
						icnt = (icnt % mod * jiec(cf) % mod) % mod;
					cf = 0;
				}
			}
			do {
				int yq = 0, jj = 0;
				for (int i = 1; i <= n; i++) {
					if (s[i - 1] == '0' || jj >= a[i])
						jj++;
					else
						yq++;
					//	cout << a[i] << " ";
				}
				if (yq >= m)
					cnt++;
				//	cout << endl;
			} while (next_permutation(a + 1, a + 1 + n));
			cnt = (cnt % mod *icnt % mod) % mod;
			cout << cnt << endl;
		}
	}
	return 0;
}
//AKCSPS2025
