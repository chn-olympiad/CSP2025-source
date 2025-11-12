#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3+10, M = 998244353;
int n, arr[N], ans;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1, cmp);
	if (n == 3) {
		if (arr[1] * 2 < arr[1] + arr[2] + arr[3])
			cout << 1, exit(0);
		else
			cout << 0, exit(0);
	}
	if (arr[1] == arr[n]) {
		for (int i = 3; i <= n; i++) {
			int cnt = 1;
			int k = min(i, n - i);
			for (int j = n; j >= n - k + 1; j--) {
				cnt *= j;
				cnt %= M;
			}
			for (int j = 1; j <= k; j++)
				cnt /= j;
			ans += cnt;
		}
	}
	cout << ans;
	return 0;
}