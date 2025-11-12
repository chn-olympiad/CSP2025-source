#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[5005], q = 998244353;

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int l = 0; l < n - i; l++) {
				int maxx = 0, len = 0;
				for (int k = j; k < n; k++) {
					if (n - i > n - k)
						k += l;
					len += a[i];
					maxx = max(maxx, a[i]);
					if (n - i > n - k)
						k += l;
				}
				if (len > maxx * 2)
					sum = (sum % q + 1) % q;
			}
		}
	}
	cout << sum;
	return 0;
}
