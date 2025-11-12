#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int ans = a[0];
	for (int i = 1; i < n; i ++) {
		ans ^= a[i];
	}
	cout << ans << endl;
	return 0;
}
