#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int>a(n + 3, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (!k) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				sum++;
			else if (a[i + 1]) {
				i++;
				sum++;
			}
		}
	} else {
		for (int i = 1; i <= n; i += 2) {
			if ((a[i] == 1 && a[i + 1] == 0) || (a[i] == 0 && a[i + 1] == 1))
				sum++;
			if (a[i] == 1 && a[i + 1] == 1)
				sum += 2;
		}
	}
	cout << sum;
	return 0;
}
