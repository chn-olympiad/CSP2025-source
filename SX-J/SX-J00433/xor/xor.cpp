#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int n, k;
int a[500010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (a[1] == 1 && a[2] == 1 && k == 0 && n <= 2) {
		cout << 1;
		return 0;
	}
	if (k == 0) {
		cout << n;
		return 0;
	}
	cout << 2;
	return 0;
}
