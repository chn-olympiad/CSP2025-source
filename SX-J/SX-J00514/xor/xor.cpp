#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int sum;
	if ((k == 1 || k == 0) && n > 2) {
		for (int i = 1; i <= n; i++)
			if (a[i] == k)
				cnt++;
		cout << cnt;
		return 0;
	}
	for (int l = 1; l <= n;) {
		if (a[l] == k) {
			cnt++;
			l++;
			continue;
		}
		sum = a[l];
		for (int r = 1; r < n; r++) {
			if (a[l + r] == k) {
				cnt++;
				l = l + r + 1;
				break;
			}
			sum ^= a[l + r];
			if (sum == k) {
				cnt++;
				l = l + r + 1;
				break;
			}
		}
		l++;
	}
	cout << cnt;
	return 0;
}