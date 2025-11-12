#include <bits/stdc++.h>
using namespace std;
int n, m, qw[1000000005], ans = 1;
string q;

bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> q;
	for (int i = 1; i <= n; i++) {
		cin >> qw[i];
	}
	sort(qw + 1, qw + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		if (q[i] == 1)
			ans  = ans * qw[i];
	}
	cout << ans % 998244353;
	return 0;
}

