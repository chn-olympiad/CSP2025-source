#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ll n, k, sum = 0, sum2 = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != 1 and a[i] != 0 and k != 0) {
			break;
		}
		if (a[i] == 1) {
			sum++;
		}
		if (a[i] == 0) {
			sum2++;
		}
		if (i == n) {
			if (k == 0) {
				cout << sum2;
				return 0;
			}
			cout << sum / k;
			return 0;
		}
	}
	return 0;
}