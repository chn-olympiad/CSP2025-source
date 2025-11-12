#include <bits/stdc++.h>
using namespace std;

int n, q, u, v, cnt;
string s;

int main() {

	freopen("repiace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> u >> v;

	}
	for (int i = 1; i <= q; i++) {
		cin >> a >> b;
		if (u == a) {
			a = u;
			cnt++;
		}
		if (v == b) {
			b = v;
			cnt++;
		}
		cout << cnt;
	}

	return 0;
}