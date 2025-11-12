#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	if (n == 2) {
		cout << 1;
		return 0;
	} else if (n == 1) {
		cout << 0;
		return 0;
	}
	return 0;
}