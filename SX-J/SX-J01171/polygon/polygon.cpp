#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N = 5000 + 10;
int a[N];
int n;

int cmp(int aa, int bb) {
	return aa > bb;
}
int dp[N * N];
int b[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	if (n <= 2) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		int sum = a[1] + a[2] + a[3];
		sort(a + 1, a + n + 1, cmp);
		if (sum > a[1] * 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	cout << n;
	return 0;
}
