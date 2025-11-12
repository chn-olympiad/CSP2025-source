#include <bits/stdc++.h>
using namespace std;
int n, m;
int sum[505], c[505], k[505];
string h;
long long a = 1, x = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	int left = n;
	cin >> h;
	for (int i = 0; i < h.length(); i++) {
		sum[i] = (h[i] == '0');
		if (i > 0)
			sum[i] += sum[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (k[i] == 0) {
			a++;
			left--;
		} else {
			for (int j = 1; j < n; j++) {
				if (sum[j] >= k[i])
					c[j]++;
			}
		}
	}
	for (int i = 0; i < n && left > 0; i++) {
		x = (left *x) % 998244353;
		x = (a *x) % 998244353;
		left -= c[i];
		a += c[i];
		left--;
	}
	cout << x / n;
	return 0;
}