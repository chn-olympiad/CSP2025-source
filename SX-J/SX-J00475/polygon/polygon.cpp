#include <bits/stdc++.h>
using namespace std;
int n, k, a[5005];

double cmp(int q, int w) {
	return q >= w;
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	if (a[0] == a[n - 1]) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += i;
		}
		cout << cnt;
		return 0;
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		for (int l = 0, r = l + i; r < n; l++, r++) {
			int sum = 0;
			for (int j = l; j <= r; j++) {
				sum += a[j];
			}
			if (a[l] < sum) {
				cnt++;
			}
		}
	}
	cout << cnt % 998244353;
	return 0;
}
