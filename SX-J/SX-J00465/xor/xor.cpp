#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
const int N_MAX = 5e5 + 10;

int n, k;
int a, cnta;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		cnta += a;
	}

	if (!k) {
		cout << cnta / 2 << endl;
	} else {
		cout << cnta << endl;
	}

	return 0;
}
