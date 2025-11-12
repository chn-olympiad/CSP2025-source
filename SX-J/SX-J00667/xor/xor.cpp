#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long x, n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		x = 0;
		for (int j = i; j <= n; j++) {
			x = x ^a[j];
			if (x == k) {
				ans++;
				i = j;
				break;
			}
		}

	}
	cout << ans;
	return 0;
}
