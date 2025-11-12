#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, al = 0;
const int maxn = 512;
bool r[maxn];
int b[maxn];

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		char a;
		cin >> a;

		if (a == '0') {
			r[i] = 0;

		} else {
			r[i] = 1;
			al++;
		}
	}

	for (int i = 1; i <= n; i++) {

		cin >> b[i];
	}

	if (al >= m) {
		cout << m;
	} else {
		int s = 1;

		for (int i = 1; i <= n; i++) {

			s *= b[i];
		}

		cout << s / 2 % 998244353;
	}

	return 0;
}