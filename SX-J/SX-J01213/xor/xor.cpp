#include <bits/stdc++.h>
using namespace std;
int n, a[500005], k, ans, sum;
bool vis[500005], f;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			ans++;
			vis[i] = 1;
		}
		if (a[i] != 1)
			f = 1;
	}
	if (f == 0 && k != 0 && k != 1) {
		cout << 0;
		return 0;
	} else if (f == 0 && k == 0) {
		cout << n / 2;
		return 0;
	} else if (f == 0 && k == 1) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			sum = a[i];
			for (int j = i + 1; j <= n; j++) {
				if (vis[j] == 0) {
					sum ^= a[j] ;
					if (sum == k) {
						ans++;
						i = j;
						break;
					}
				} else
					break;
			}
		}
	}
	cout << ans;
	return 0;
}
